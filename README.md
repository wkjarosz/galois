# galois++

Status:
[![macOS build](https://github.com/wkjarosz/galois/actions/workflows/ci-mac.yml/badge.svg?branch=master)](https://github.com/wkjarosz/galois/actions/workflows/ci-mac.yml)
[![Linux build](https://github.com/wkjarosz/galois/actions/workflows/ci-linux.yml/badge.svg?branch=master)](https://github.com/wkjarosz/galois/actions/workflows/ci-linux.yml)
[![Windows build](https://github.com/wkjarosz/galois/actions/workflows/ci-windows.yml/badge.svg?branch=master)](https://github.com/wkjarosz/galois/actions/workflows/ci-windows.yml)

This is C++ library for general Galois fields based on [Art Owen's code in Statlib](http://ftp.uni-bayreuth.de/math/statlib/designs/). This library supports arithmetic over a finite field of any prime power, GF(p^n) where p is a prime and n >= 1, and it does so relatively efficiently by relying on addition and multiplication tables.

## Library organization

The library consists primarily of two classes:
+ The Galois `Field` class precomputes various tables for efficient arithmetic on a Galois field with `q` elements. This is essentially Owen's `GF` C struct converted to a C++ class with a constructor and a few convient member functions.
+ The Galois `Element` class takes a pointer to a `Field` and enables arithmetic over a Galois field using operator overload.

## Example usage

For example the following code performs simple arithmetic over GF(q = 2^2 = 4):
```cpp
Galois::Field gf(4);
std::cout << gf << std::endl;

Galois::Element A(&gf,3);
Galois::Element B(&gf,2);
Galois::Element C = A * B;
Galois::Element D = (B - 1) / C;

std::cout << "A = " << A << std::endl;
std::cout << "B = " << B << std::endl;
std::cout << "C = A * B = " << C << std::endl;
std::cout << "D = (B - 1) / C = " << D << std::endl;
```

This would output:
```
For GaloisField(4) p=2 n=2
x**n = (1,1)


GF(4) Polynomial coefficients:
  0  0 0 
  1  1 0 
  2  0 1 
  3  1 1 


GF(4) Addition Table
   0 1 2 3
   1 0 3 2
   2 3 0 1
   3 2 1 0


GF(4) Multiplication table
   0 0 0 0
   0 1 2 3
   0 2 3 1
   0 3 1 2


GF(4) Reciprocals
 0 -1
 1 1
 2 3
 3 2


GF(4) Negatives
 0 0
 1 1
 2 2
 3 3


GF(4) Square roots
 0 0
 1 1
 2 3
 3 2

A = 3
B = 2
C = A * B = 1
D = (B - 1) / C = 3
```

The `test` subdirectory contains some unit tests, which can also serve as additional usage examples.

## Acknowledgements & links
This library is adapted directly from [Art Owen's code in Statlib](http://ftp.uni-bayreuth.de/math/statlib/designs/).

Other Galois field libraries served as inspiration, including:
 * [GaloisCPP](https://github.com/saiedhk/GaloisCPP), by Saied H. Khayat
 * [liboa](https://github.com/bertcarnell/oa), by Robert Carnell
