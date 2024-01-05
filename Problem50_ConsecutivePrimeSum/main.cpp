/*

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms,
and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/

#include <iostream>
#include <cmath>
#include <vector>
#include "teiler_2.h"
using namespace std ;

int main ()
{
	int const OBERE_PRIMZAHLGRENZE = 10000 ;
	bool* istPrim = siebEratosthenes( 10000000 ) ;

	vector< int > primzahlListe ;
	for ( int i = 2 ;  i < OBERE_PRIMZAHLGRENZE ;  ++i )
		if ( istPrim[ i ] )
			primzahlListe.push_back( i ) ;

	int max_aufeinanderfolgendePrimzahlen = 0 ;
	int max_primzahl = 0 ;
	for ( int i = 0 ;  i < primzahlListe.size() ;  ++i )
	{
		int summe = primzahlListe.at( i ) ;
		for ( int j = i + 1 ;  j < primzahlListe.size() - 1 ;  ++j )
		{
			summe += primzahlListe.at( j ) ;
			if ( istPrim[ summe ] && summe < 1000000 )
				if ( j - i + 1 > max_aufeinanderfolgendePrimzahlen )
				{
					max_aufeinanderfolgendePrimzahlen = j - i + 1 ;
					max_primzahl = summe ;
				}
				
		}
	}

	cout << max_primzahl << endl ;



	delete[] istPrim ;

	return 0 ;
}