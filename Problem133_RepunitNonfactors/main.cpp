/*

A number consisting entirely of ones is called a repunit. We shall define R(k)
to be a repunit of length k; for example, R(6) = 111111.

Let us consider repunits of the form R(10n).

Although R(10), R(100), or R(1000) are not divisible by 17, R(10000) is divisible by 17.
Yet there is no value of n for which R(10n) will divide by 19. In fact, it is remarkable
that 11, 17, 41, and 73 are the only four primes below one-hundred that can be a factor of R(10n).

Find the sum of all the primes below one-hundred thousand that will never be a factor of R(10n).

*/

#include <iostream>
#include "primzahlen.h"
#include <vector>
#include <algorithm>
#include <ttmath\ttmath.h>
using namespace std ;

typedef unsigned long long uint64 ;
typedef ttmath::Int< 10000 > bInt ;

// gibt die Repunitzahl R( n ) zurück.
bInt repunitZahl( uint64 n )
{
	static uint64 n_alt = 0 ;
	static bInt zahl = 0 ;
	static bInt potenz = 1 ;

	if ( signed( n - n_alt ) < 0 )
	{
		n_alt = 0 ;
		zahl = 0 ;
		potenz = 1 ;
	}

	for ( int i = 0 ;  i < n - n_alt ;  ++i )
	{
		zahl += potenz ;
		potenz *= 10 ;
	}

	n_alt = n ;

	return zahl ;
}

int main ()
{
	int const MAX_PRIMZAHL = 100000 ;

	bool* istPrim = siebEratosthenes( MAX_PRIMZAHL ) ;
	bool primfaktoren[ MAX_PRIMZAHL + 1 ] = { false } ;
	

	
	vector< uint64 > T10ei ; // Teiler von 10^i
	
	// alle Teiler von 10^i ermitteln, welche kleiner als MAX_PRIMZAHL sind
	// ( 10^i hat die Primfaktorzerlegung 2^x * 5^y )
	for ( int e2 = 0 ;  true ;  ++e2 )
	{
		if ( pow( 2., e2 ) > MAX_PRIMZAHL )
			break ;

		for ( int e5 = 0 ;  true ;  ++e5 )
		{
			uint64 zahl = uint64( pow( 2., e2 ) * pow( 5., e5 ) ) ;
			if ( zahl <= MAX_PRIMZAHL )
				T10ei.push_back( zahl ) ;
			else
				break ;
		}
	}

	sort( T10ei.begin(), T10ei.end() ) ; // Teiler von 10^i aufsteigend sortieren


	for ( int i = 1 ;  i < T10ei.size() ;  ++i )
	{
		cout << "R(" << T10ei.at( i ) << "): " ;

		bInt R_n = repunitZahl( T10ei.at( i ) ) ;
		for ( uint64 j = T10ei.at( i ) + 1 ;  j <= MAX_PRIMZAHL ;  j += T10ei.at( i ) )
			if ( istPrim[ j ] )
				if ( R_n % j == 0 )
					{
						cout << j << " " ;
						R_n /= j ;
						primfaktoren[ j ] = true ;
					}
		cout << endl ;
		}



	uint64 summe = 0 ;
	for ( int i = 0 ;  i <= MAX_PRIMZAHL ;  ++i )
		if ( istPrim[ i ] && primfaktoren[ i ] == false )
			summe += i ;

	cout << summe << endl ;

	delete[] istPrim ;

	return 0 ;
}