/*

Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when
n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the
consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression
that produces the maximum number of primes for consecutive values of n, starting with n = 0.


*/

#include <iostream>
#include <cmath>
#include "teiler.h"
using namespace std ;

int main ()
{
	int const MAX_PRIMZAHL_VERMUTUNG = 100000 ;
	bool* istPrim = siebEratosthenes( MAX_PRIMZAHL_VERMUTUNG ) ;

	int bestes_a, bestes_b ;
	int beste_aufeinanderfolgendePrimzahlen = 0 ;

	for ( int b = 2 ;  b < 1000 ;  ++b )
		if ( istPrim[ b ] ) // b muss prim sein, da sonst für n = 0: n^2 + an + b nicht prim wäre
		{
			// a muss aus [1-b, 998] sein, da mit n = 1: 1 + a + b >= 2  <=>  a >= 1-b
			for ( int a = 1 - b ;  a < 999 ;  ++a )
			{
				if ( abs( a ) % 2 == 1 ) // a muss ungerade sein, da mit n = 1, b ungerade, a gerade:
										 // 1 + 2m + 2n + 1 gerade ( nicht prim ) und mit n = 2, b = 2, a gerade:
										 // 4 + 2m + 2 gerade ( nicht prim )
				{
					int n = 0 ;
					int aufeinanderfolgendePrimzahlen = 0 ;
					int quadratischerFunktionswert = n * n + a * n + b ;

					while ( istPrim[ quadratischerFunktionswert ] )
					{
						++aufeinanderfolgendePrimzahlen ;
						++n ;
						quadratischerFunktionswert = n * n + a * n + b ;

						if ( quadratischerFunktionswert >= MAX_PRIMZAHL_VERMUTUNG )
						{
							cerr << "Primzahl-Vermutung ueberschritten!" << endl ;
							return -1 ;
						}
					}

					if ( n > beste_aufeinanderfolgendePrimzahlen )
					{
						beste_aufeinanderfolgendePrimzahlen = n ;
						bestes_a = a ;
						bestes_b = b ;
					}
				}
			}
		}

	cout << bestes_a * bestes_b << endl ;

	return 0 ;
}