/*

It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?

*/

#include <iostream>
#include <vector>
#include <set>
#include "primzahlen.h"
using namespace std ;


int main ()
{
	int const MAX_PRIMZAHL = 1000 ;
	bool* istPrim = siebEratosthenes( MAX_PRIMZAHL ) ;

	int const LIMIT = 100 ;
	int wege[ LIMIT + 1 ] = { 0 } ;
	wege[ 0 ] = 1 ;
	wege[ 1 ] = 0 ;

	for ( int p = 2 ;  p <= LIMIT ;  ++p )
		if ( istPrim[ p ] )
			for ( int i = p ;  i <= LIMIT ;  ++i )
				wege[ i ] += wege[ i - p ] ;

	for ( int i = 0 ;  i <= LIMIT ;  ++i )
		if ( wege[ i ] > 5000 )
		{
			cout << i << endl ;
			break ;
		}

	return 0 ;
}