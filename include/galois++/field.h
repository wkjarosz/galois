/**
   \file field.h
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
#pragma once

#include <galois++/array2d.h>
#include <iostream>

namespace Galois
{

/*!
   Defines a Galois Field of characteristic \f$p\f$ and dimesion \f$n\f$ (for \f$GF(p^n\f$)).

   It stores the polynomial field itself and various tables for efficient
   arithmetic operations (addition/negation, multiplication/division, square
   root) over the field.
*/
class Field
{
public:
    /**
        Construct an empty Galois field.
     */
    Field();

    /**
        Construct a Galois field with q arguments.
        \param q the number of arguments
     */
    Field(int q);

    /**
        Resize this field to have q arguments.
        \return true for success
     */
    bool resize(int q);

    /**
        Outputs information about this Galois Field to the output stream.
        \param gf Field on the right of << sign
        \param output an output stream on the left of << sign
        \returns output stream
    */
    friend std::ostream& operator<<(std::ostream& output, const Field& gf);

    int n;                 ///< Vector Length
    int p;                 ///< modulus
    int q;                 ///< q = p^n
    std::vector<int> inv;  ///< multiplicative inverses
    std::vector<int> neg;  ///< negatives
    std::vector<int> root; ///< square roots
    Array2d<int> plus;     ///< sum field
    Array2d<int> times;    ///< product field
    Array2d<int> poly;     ///< polynomial field
};

} // namespace Galois
