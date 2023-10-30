/*
    Portions of the unit tests in this file are based on unit tests from two
    other Galois field libraries:

    GaloisCPP, copyright (c) Saied H. Khayat
    (https://github.com/saiedhk/GaloisCPP), released under the MIT license
    (http://opensource.org/licenses/MIT);

    and,

    liboa, copyright (c) Robert Carnell (https://github.com/bertcarnell/oa),
    released under the LGPLv3 license (https://opensource.org/licenses/LGPL-3.0).
*/

#include <galois++/element.h>
#include <galois++/field.h>
#include <galois++/primes.h>
#include <iostream>

using namespace std;

inline void Assert(bool test, string msg)
{
    if (!test)
    {
        string message = "Assertion Error: ";
        message.append(msg);
        message.append("\n\n");
        throw logic_error(message.c_str());
    }
}

inline void Assert(bool test)
{
    Assert(test, "Error in test - no message");
}

/**
 * Assert that the expression throws an error.  It is caught if is derived from
 * runtime_error or from logic_error
 */
#define ASSERT_THROW(exp)                                              \
    try                                                                \
    {                                                                  \
        exp;                                                           \
        throw string(                                                  \
            "Failed: test that should throw an exception did not.\n"); \
    }                                                                  \
    catch (runtime_error re)                                           \
    {                                                                  \
    }                                                                  \
    catch (logic_error le)                                             \
    {                                                                  \
    }

void testIsPrime()
{
    Assert(isPrime(0) == false, "error 0 prime");
    Assert(isPrime(1) == false, "error 1 prime");
    Assert(isPrime(2) == true, "error 2 prime");
    Assert(isPrime(3) == true, "error 3 prime");
    Assert(isPrime(4) == false, "error 4 not prime");
    Assert(isPrime(5) == true, "error 5 prime");
    Assert(isPrime(6) == false, "error 6 not prime");
}

void testPrimePow()
{
    int p = 0;
    int n = 0;
    bool isit = findPrimePower(8, &p, &n);
    Assert(p == 2 && n == 3 && isit == true);

    p = n = 0;
    isit = findPrimePower(23, &p, &n);
    Assert(p == 23 && n == 1 && isit == true);

    // Not Prime
    p = n = 0;
    isit = findPrimePower(6, &p, &n);
    Assert(p == 0 && n == 1 && isit == false);

    // q < 1
    p = n = 0;
    isit = findPrimePower(-1, &p, &n);
    Assert(p == 0 && n == 0 && isit == false);
}

void testPrimes()
{
    printf("\tTesting prime numbers...");
    testIsPrime();
    testPrimePow();
    printf("passed\n");
}

void testGFConstruct()
{
    printf("\tTesting Galois field construction...");

    Galois::Field gf = Galois::Field();
    Assert(gf.resize(3) == true);
    cout << gf << endl;
    Assert(gf.resize(5) == true);
    cout << gf << endl;
    Assert(gf.resize(7) == true);
    cout << gf << endl;
    Assert(gf.resize(9) == true);
    cout << gf << endl;
    Assert(gf.resize(11) == true);
    cout << gf << endl;
    Assert(gf.resize(13) == true);
    cout << gf << endl;
    Assert(gf.resize(16) == true);
    cout << gf << endl;
    Assert(gf.resize(17) == true);
    cout << gf << endl;
    Assert(gf.resize(19) == true);
    cout << gf << endl;
    Assert(gf.resize(23) == true);
    cout << gf << endl;
    Assert(gf.resize(49) == true);
    cout << gf << endl;
    ASSERT_THROW(gf.resize(-3));
    ASSERT_THROW(gf.resize(1));
    ASSERT_THROW(gf.resize(100));
    // ASSERT_THROW(gf.resize(ipow(2, 30)));

    printf("passed\n");
}

void testGFMath()
{
    printf("\tTesting Galois field arithmetic...\n");
    vector<int> gfs = {9, 11, 13, 16, 49};

    for (size_t i = 0; i < gfs.size(); ++i)
    {
        // Define Galois Galois::Field
        Galois::Field gf(gfs[i]);
        cout << "Testing GF(" << gfs[i] << ")" << endl;
        //---------------------------------

        Galois::Element E(&gf), F(&gf), G(&gf), H(&gf);

        int a = 2, b = 3;
        // cout << "a=" << a << "  b=" << b << endl;

        Galois::Element A(&gf, 1);
        Galois::Element B(&gf, 2);
        Galois::Element C(&gf, 3);
        Galois::Element D(&gf, 6);

        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        cout << "C: " << C << endl;
        cout << "D: " << D << endl;

        //*********************** action begins ************************

        try
        {
            cout << "\nACTION: E = A + B\n";
            E = A + B;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        //-------------------------------------------------------------
        cout << "\nACTION: E = -A\n";
        E = -A;
        cout << "RESULT: E = " << E;

        cout << "\nACTION: F = -E\n";
        F = -E;
        cout << "RESULT: F = " << F;

        Assert(F == A, "ERROR: F==A is false");
        cout << "\nOK: F==A is true\n";

        //-------------------------------------------------------------
        cout << "\nACTION: copy constructor: Galois::Element CopyofD(D)\n";
        Galois::Element CopyofD(D);
        cout << "RESULT: CopyofD = " << CopyofD;

        Assert(CopyofD == D, "ERROR: CopyofD==D is false");
        cout << "\nOK: CopyofD==D is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: F = C - D\n";
            F = C - D;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: E = D + F\n";
            E = D + F;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(C == E, "ERROR: C==E is false");
        cout << "\nOK: C==E is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: F = A * B\n";
            F = A * B;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: E = F / A\n";
            E = F / A;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(B == E, "ERROR: B==E is false");
        cout << "\nOK: B==E is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: F = A / B\n";
            F = A / B;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: E = F * B\n";
            E = F * B;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(A == E, "ERROR: A==E is false");
        cout << "\nOK: A==E is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = a * B\n";
            E = a * B;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = A * b\n";
            F = A * b;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: G = E + F\n";
            G = E + F;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: E = B * a\n";
            E = B * a;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = b * A\n";
            F = b * A;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: H = F + E\n";
            H = F + E;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(G == H, "ERROR: G==H is false");
        cout << "\nOK: G==H is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: G = A * B + C * D\n";
            G = A * B + C * D;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: H = D * C + B * A\n";
            H = D * C + B * A;
            cout << "RESULT: H = " << H;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(G == H, "ERROR: G==H is false");
        cout << "\nOK: G==H is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: G = A * B * C * D\n";
            G = A * B * C * D;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: G = G / A\n";
            H = (((G / A) / D) / C);
            cout << "RESULT: G = " << H;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(B == H, "ERROR: B==H is false");
        cout << "\nOK: B==H is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: G = A * B * C * D * A * B * D * C\n";
            G = A * B * C * D * A * B * D * C;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: H = A * A * C * C * B * B * D * D\n";
            H = A * A * C * C * B * B * D * D;
            cout << "RESULT: H = " << H;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(G == H, "ERROR: G==H is false");
        cout << "\nOK: G==H is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = (A + B) * C\n";
            E = (A + B) * C;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = A * C + B * C\n";
            F = A * C + B * C;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(E == F, "ERROR: E==F is false");
        cout << "\nOK: E==F is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = (A + C) * (B + D)\n";
            E = (A + C) * (B + D);
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = B * A + D * A + C * B + D * C\n";
            F = B * A + D * A + C * B + D * C;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(E == F, "ERROR: E==F is false");
        cout << "\nOK: E==F is true\n";

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = (A + C) / (B + D)\n";
            cout << "A + C = " << (A + C) << endl;
            cout << "B + D = " << (B + D) << endl;
            E = (A + C) / (B + D);
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = (D + B) / (C + A)\n";
            F = (D + B) / (C + A);
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: G = E * F\n";
            G = E * F;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = 2*A + C*D\n";
            E = 2 * A + C * D;
            cout << "RESULT: E = " << E;
            cout << "\nACTION: F = B*B - 5*D\n";
            F = B * B - 5 * D;
            cout << "RESULT: F = " << F;
            cout << "\nACTION: G = E / F\n";
            G = E / F;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: F = ((-D)*5 + B*B) / (D*C + A*2)\n";
            F = ((-D) * 5 + B * B) / (D * C + A * 2);
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout << "\nACTION: G = E * F\n";
            G = E * F;
            cout << "RESULT: G = " << G;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = A / A\n";
            E = A / A;
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        //-------------------------------------------------------------
        try
        {
            cout << "\nACTION: E = sqrt(A)\n";
            E = A.sqrt();
            cout << "RESULT: E = " << E;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(E.value() >= 0, "ERROR: A has no root");

        try
        {
            cout << "\nACTION: F = E * E\n";
            F = E * E;
            cout << "RESULT: F = " << F;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

        Assert(A == F, "ERROR: A==F is false");
        cout << "\nOK: A==F is true\n";

        cout << "\n---------------------------------------------------\n";
    }
    printf("passed\n");
}

int main(int argc, const char *argv[])
{
    try
    {
        testPrimes();
        testGFConstruct();
        testGFMath();
    }
    catch (const exception &e)
    {
        cout << endl
             << e.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
