/*

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
is unusual in two ways: (i) each of the three terms are prime, and,
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

*/

#include <iostream>
#include <set>
#include "primzahlen.h"
using namespace std ;

int ziffernPrimzahlProdukt( int n )
{
	int ziffernErsatz[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 } ;

	int produkt = 1 ;
	while ( n > 0 )
	{
		produkt *= ziffernErsatz[ n % 10 ] ;
		n /= 10 ;
	}

	return produkt ;
}

int main ()
{
	struct pCmp
	{
		bool operator() ( const pair< int, int >& lhs, const pair< int, int >& rhs )
		{
			return ( lhs.second < rhs.second ) || ( lhs.first < rhs.first ) ;
		}
	} ;

	multiset< pair< int, int >, pCmp > primzahlen ;


	vector< int > vprimzahlen = primzahlliste( 10000 ) ;

	for ( int i = 0 ;  i < vprimzahlen.size() ;  ++i )
		if ( int( log10( double( vprimzahlen.at( i ) ) ) ) + 1 == 4 )
			primzahlen.insert( pair< int, int >( vprimzahlen.at( i ), ziffernPrimzahlProdukt( vprimzahlen.at( i ) ) ) ) ;

	multiset< pair< int, int >, pCmp >::iterator it ;
	for ( it = primzahlen.begin() ;  it != primzahlen.end() ;  ++it )
	{
		int primProdukt = (*it).second ;
		vector< int > abc ;

		multiset< pair< int, int >, pCmp >::iterator it2 ;
		for ( it2 = it ;  primProdukt == (*it2).second ;  ++it2 )
			abc.push_back( (*it2).first ) ;

		if ( abc.size() > 2 )
		{
			for ( int j = 0 ;  j < abc.size() - 2 ;  ++j )
			{
				if ( 2 * abc.at( j + 1 ) == abc.at( j ) + abc.at( j + 2 ) )
						cout << abc.at( j ) << abc.at( j + 1 ) << abc.at( j + 2 ) << endl ;
			}

		}
	}

	return 0 ;
}