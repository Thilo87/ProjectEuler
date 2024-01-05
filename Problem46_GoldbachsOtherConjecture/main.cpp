/*

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

*/

#include <iostream>
#include <cmath>
#include "primzahlen.h"
using namespace std ;

int main ()
{
	int const MAX_PRIM = 10000 ;
	bool* istPrim = siebEratosthenes( MAX_PRIM ) ;


	for ( int n = 9 ;  true ;  n += 2 )
		if ( !istPrim[ n ] ) // n ist zusammengesetzt ( und ungerade )
		{
			bool moeglich = false ;
			for ( int p = 2 ;  p < n ;  ++p )
				if ( istPrim[ p ] )
				{
					for ( int a = 1 ;  a < sqrt( n / 2. ) ;  ++a )
						if ( p + 2 * a * a == n )
						{
							moeglich = true ;
							break ;
						}

					if ( moeglich )
						break ;
				}
			
			if ( !moeglich )
			{
				cout << n << endl ;
				break ;
			}
		}

	delete[] istPrim ;
	return 0 ;
}