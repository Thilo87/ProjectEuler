/*

The number 3797 has an interesting property. Being prime itself, it is possible to continuously
remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/

#include <iostream>
#include <cmath>
#include <string>
#include "teiler.h"
using namespace std ;

unsigned long long stringZuZahl( string const& s )
{
	unsigned long long zahl = 0 ;
	for ( int i = 0 ;  i < s.size() ;  ++i )		zahl += ( s.at( i ) - '0' ) * pow( 10., double( s.size() - i - 1 ) ) ;

	return zahl ;
}

// gibt die ersten n Ziffern von zahl zurück
unsigned long long ersteZiffern( unsigned long long zahl, int n )
{
	return zahl / unsigned long long( pow( 10., floor( log10( double( zahl ) ) ) + 1 - n ) ) ;
}

// gibt die letzten n Ziffern von zahl zurück
unsigned long long letzteZiffern( unsigned long long zahl, int n )
{
	return zahl % unsigned long long( pow( 10., n ) ) ;
}

int main ()
{
	bool* istPrim = siebEratosthenes( 999999 ) ;
	istPrim[ 1 ] = false ;

	int summe = 0 ;
	for ( int i = 11 ;  i < 999999 ;  ++i )
	{
		int ziffernanzahl = log10( double( i ) ) + 1 ;

		bool istTruncatable = true ;

		for ( int j = ziffernanzahl ;  j >= 1 && istTruncatable == true ;  --j )
			if ( !istPrim[ ersteZiffern( i, j ) ] )
				istTruncatable = false ;

		for ( int j = ziffernanzahl ;  j >= 1 && istTruncatable == true ;  --j )
			if ( !istPrim[ letzteZiffern( i, j ) ] )
				istTruncatable = false ;

		if ( istTruncatable ) 
			summe += i ;
	}

	cout << summe  << endl ;

	return 0 ;
}