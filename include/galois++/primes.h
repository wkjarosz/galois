/**
   \file primes.h
   \author Wojciech Jarosz
   \copyright Copyright (c) 2019, Wojciech Jarosz

   \brief Utilities related to prime numbers.

   Some of these functions are adapted from:
  
   Reference:
   <ul><li><a href="http://lib.stat.cmu.edu/designs/">Statlib Designs</a></li>
   <li><a href="http://lib.stat.cmu.edu/designs/oa.c">Owen's Orthogonal Array
   Algorithms</a></li></ul>

   License:  This file may be freely used and shared according to the original
   license.
  
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

/**
   Returns any of the first NUM_PRIMES prime numbers.
   
   NUM_PRIMES is currently 2,580; the largest stored prime is 23,099
   
   \param n     The index of the desired prime number.
                
   \return      Returns the n-th prime when 1 <= n <= NUM_PRIMES.
                Returns NUM_PRIMES, the index of the largest prime available,
                when n = -1. Returns 1 when n = 0.
 */
unsigned nthPrime(int n);


/**
   Returns the smallest prime greater than or equal to \c n.
   
   \param n     The number to be bounded.
   \return      The smallest prime number that is greater than or equal to n.
                If n is larger than the largest stored prime (23099), then 0
                is returned.
 */
unsigned primeGE(int n);

/**
   Returns any of the first NUM_PRIME_POWERS prime powers.

   NUM_PRIME_POWERS is currently 2,648; the largest stored prime poiwer is
   23,099

   \param n     The index of the desired prime power.

   \return      Returns the n-th prime when 1 <= n <= NUM_PRIME_POWERS.
                Returns NUM_PRIME_POWERS, the index of the largest prime
                available, when n = -1. Returns 1 when n = 0.
 */
unsigned nthPrimePower(int n);


/**
   Returns the smallest prime power greater than or equal to \c n.
   
   \param n     The number to be bounded.
   \return      The smallest prime power that is greater than or equal to n.
                If n is larger than the largest stored prime power (23099),
                then 0 is returned.
 */
unsigned primePowerGE(int n);

/**
   Returns true for prime argument

   \param p     number to test
   \return      true if \c p is prime
 */
bool isPrime(unsigned int p);

/**
   Find \f$ q=p^n \f$ if \f$ q \f$ is a prime power with \f$ n>0 \f$

   \param q     integer that is a prime power
   \param p     the prime base
   \param n     the integer power
   \return      true iff successful
 */
bool findPrimePower(int q, int* p, int* n);

/**
   \param q     The number of test for primality
   \return      true for prime power argument
 */
bool isPrimePower(int q);