/**
   \file gfield.cpp
   \author Wojciech Jarosz
   \copyright Copyright (c) 2019, Wojciech Jarosz
  
   License:  This file may be freely used and shared according to the original
   license.
  
   Reference:
   <ul><li><a href="http://lib.stat.cmu.edu/designs/">Statlib Designs</a></li>
   <li><a href="http://lib.stat.cmu.edu/designs/oa.c">Owen's Orthogonal Array
   Algorithms</a></li></ul>
  
   Original Header:
   <blockquote>
   These programs construct and manipulate orthogonal arrays.  They were
   prepared by
  
   - Art Owen
   - Department of Statistics
   - Sequoia Hall
   - Stanford CA 94305
  
   They may be freely used and shared.  This code comes
   with no warranty of any kind.  Use it at your own
   risk.
  
   I thank the Semiconductor Research Corporation and
   the National Science Foundation for supporting this
   work.
   </blockquote>
 */

#include <galois++/field.h>
#include <galois++/primes.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

namespace Galois
{

// local functions
namespace
{

/**
   pow() with integer arguments and value

   \return      <code>a</code> raised to the <code>b</code>th power
 */
int ipow(int a, int b)
{
    return (int)std::pow((double)a, (double)b);
}


/**
   Multiplication in polynomial representation.
  
   Set prod = p1*p2 with coefficients modulo p, and x^n replaced
   by polynomial xton.
  
   \param p     modulus
   \param n     length of p1 and p2
   \param xton  representation of x^n
   \param p1    polynomial 1
   \param p2    polynomial 2
   \param prod  the product of the polynomials
 */
void polyProd(int p, int n, const vector<int>& xton, const int* p1,
              const int* p2, vector<int>& prod)
{
    vector<int> longprod(2 * n - 1);

    longprod.assign(2 * n - 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            longprod[i + j] += p1[i] * p2[j];

    for (int i = 2 * n - 2; i > n - 1; i--)
        for (int j = 0; j < n; ++j)
            longprod[i - n + j] += xton[j] * longprod[i];

    for (int i = 0; i < n; ++i)
        prod[i] = longprod[i] % p;
}

/**
   Addition in polynomial representation
  
   \param p     modulus
   \param n     the length of p1 and p2
   \param p1    polynomial 1
   \param p2    polynomial 2
   \param sum   the sum of the polynomials
 */
void polySum(int p, int n, const int* p1, const int* p2, vector<int>& sum)
{
    for (int i = 0; i < n; ++i)
        sum[i] = (p1[i] + p2[i]) % p;
}

/**
   Convert polynomial to integer in <code>0..q-1</code>
  
   \param p     polynomial multiplier
   \param n     the length of poly
   \param poly  the polynomial
   \return      an integer
 */
int poly2int(int p, int n, const vector<int>& poly)
{
    int ans = 0;
    for (int i = n - 1; i > 0; i--)
        ans = (ans + poly[i]) * p;
    ans += poly[0];

    return ans;
}

/**
   Prepare (+,*,^-1) lookup tables.
  
   \param gf    the Galois field
   \param p     the modulus
   \param n     the length of xton
   \param xton  the x^n vector
   \return      true for success
 */
bool prepare(Field& gf, int p, int n, const vector<int>& xton)
{
    vector<int> poly(n);

    gf.n = n;
    gf.p = p;
    int q = 1;
    for (int i = 0; i < n; ++i)
        q *= p;

    gf.q = q;
    // gf.xton = xton;

    gf.plus.resize(q, q);
    gf.times.resize(q, q);
    gf.inv = vector<int>(q);
    gf.neg = vector<int>(q);
    gf.root = vector<int>(q);
    gf.poly.resize(n, q);

    for (int i = 0; i < n; ++i)
        gf.poly(i, 0) = 0;

    for (int i = 1; i < q; ++i)
    {
        int click;
        for (click = 0; gf.poly(click, i - 1) == (p - 1); ++click)
            gf.poly(click, i) = 0;

        gf.poly(click, i) = gf.poly(click, i - 1) + 1;
        for (int j = click + 1; j < n; ++j)
            gf.poly(j, i) = gf.poly(j, i - 1);
    }

    for (int i = 0; i < q; ++i)
        for (int j = 0; j < q; ++j)
        {
            polySum(p, n, gf.poly.row(i), gf.poly.row(j), poly);
            gf.plus(j, i) = poly2int(p, n, poly);
            polyProd(p, n, xton, gf.poly.row(i), gf.poly.row(j), poly);
            gf.times(j, i) = poly2int(p, n, poly);
        }

    for (int i = 0; i < q; ++i)
    {
        gf.inv[i] = -1;
        for (int j = 0; j < q; ++j)
            if (gf.times(j, i) == 1)
                gf.inv[i] = j;

        if (i > 0 && gf.inv[i] <= 0)
        {
            ostringstream msg;
            msg << "There is something wrong with the Galois field\n";
            msg << "used for q=" << q << ".  Element " << i
                << " has no reciprocal.\n";
            const string smsg = msg.str();
            throw runtime_error(smsg.c_str());
        }
    }

    for (int i = 0; i < q; ++i)
    {
        gf.neg[i] = -1;
        for (int j = 0; j < q; ++j)
            if (gf.plus(j, i) == 0)
                gf.neg[i] = j;

        if (i > 0 && gf.neg[i] <= 0)
        {
            ostringstream msg;
            msg << "There is something wrong with the Galois field\n";
            msg << "used for q=" << q << ".  Element " << i
                << " has no negative.\n";
            throw runtime_error(msg.str().c_str());
        }
    }

    for (int i = 0; i < q; ++i)
    {
        gf.root[i] = -1;
        for (int j = 0; j < q; ++j)
            if (gf.times(j, j) == i)
                gf.root[i] = j;
    }
    return true;
}

// include declarations of xtndeclare
#include "xtndeclare.h"

const vector<int>* xton(int q)
{
    const vector<int>* xtn = nullptr;
// include generated code
#include "xtndispatch.h"
    return xtn;
}

bool getField(int q, Field& gf)
{
    int p, n;

    if (q < 1)
    { /* Impossible argument */
        throw runtime_error("Field must have positive number of elements.\n");
    }
    if (q == 1)
    { /* Pointless  argument */
        throw runtime_error("Field with 1 element was requested. \n");
    }

    if (!findPrimePower(q, &p, &n))
    {
        ostringstream msg;
        msg << "q=" << q << " is not a prime power.\n";
        const string smsg = msg.str();
        throw runtime_error(smsg.c_str());
    }

    auto xtn = xton(q);

    if (xtn && !xtn->empty())
    {
        if (prepare(gf, p, n, *xtn))
            return true;
        else
        {
            ostringstream msg;
            msg << "Construction failed for Field(" << q << ").\n";
            const string smsg = msg.str();
            throw runtime_error(smsg.c_str());
        }
    }
    else
    {
        ostringstream msg;
        msg << "Field(" << q << ") = Field(" << p << "^" << n << ") is not\n";
        msg << "included in this program. To add it, consider modifying "
               "gfields.c.\n";
        const string smsg = msg.str();
        throw runtime_error(smsg.c_str());
    }
    return true;
}

} // namespace

Field::Field()
{
    // empty
}

Field::Field(int q)
{
    getField(q, *this);
}

bool Field::resize(int newQ)
{
    return q == newQ || getField(newQ, *this);
}

ostream& operator<<(ostream& output, const Field& gf)
{
    int width = 1;
    if (gf.q > 9)
        width++;
    if (gf.q > 99)
        width++;
    if (gf.q > 999)
        width++;
    if (gf.q > 999)
        width++;
    if (gf.q > 9999)
        width++;
    if (gf.q > 99999)
        width++;
    if (gf.q > 999999)
        width++;

    output << "\nFor GaloisField(" << gf.q << ") p=" << gf.p << " n=" << gf.n
           << "\n";
    // output << "x**n = (";
    // for (int i = 0; i < gf.n - 1; ++i)
    //     output << gf.xton[i] << ",";
    // output << gf.xton[gf.n - 1] << ")\n";

    output << "\n\nGF(" << gf.q << ") Polynomial coefficients:\n";
    for (int i = 0; i < gf.q; ++i)
    {
        output << "  " << setw(width) << i << "  ";
        for (int j = 0; j < gf.n; ++j)
            output << setw(width) << gf.poly(j, i) << " ";
        output << endl;
    }
    output << "\n\nGF(" << gf.q << ") Addition Table\n";
    for (int i = 0; i < gf.q; ++i)
    {
        for (int j = 0; j < gf.q; ++j)
            output << " " << setw(width) << gf.plus(j, i);
        output << endl;
    }
    output << "\n\nGF(" << gf.q << ") Multiplication table\n";
    for (int i = 0; i < gf.q; ++i)
    {
        for (int j = 0; j < gf.q; ++j)
            output << " " << setw(width) << gf.times(j, i);
        output << endl;
    }
    output << "\n\nGF(" << gf.q << ") Reciprocals\n";
    for (int i = 0; i < gf.q; ++i)
        output << " " << setw(width) << i << " " << setw(width + 1) << gf.inv[i]
               << endl;

    output << "\n\nGF(" << gf.q << ") Negatives\n";
    for (int i = 0; i < gf.q; ++i)
        output << " " << setw(width) << i << " " << setw(width) << gf.neg[i]
               << endl;

    output << "\n\nGF(" << gf.q << ") Square roots\n";
    for (int i = 0; i < gf.q; ++i)
        output << " " << setw(width) << i << " " << setw(width + 1)
               << gf.root[i] << endl;

    return output;
}

} // namespace Galois