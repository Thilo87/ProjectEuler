/*

The proper divisors of a number are all the divisors excluding the number itself.
For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum
of these divisors is equal to 28, we call it a perfect number.

Interestingly the sum of the proper divisors of 220 is 284 and the sum of
the proper divisors of 284 is 220, forming a chain of two numbers.
For this reason, 220 and 284 are called an amicable pair.

Perhaps less well known are longer chains. For example,
starting with 12496, we form a chain of five numbers:

12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)

Since this chain returns to its starting point,it is called an amicable chain.

Find the smallest member of the longest amicable chain with no element exceeding one million.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std ;

// gibt einen Vector mit den echten Teilersummen aller Zahlen bis einschließlich limit zurück
vector< int > echteTeilersummen( unsigned long long limit )
{
	vector< int > ts( limit + 1, 1 ) ;
	ts.at( 0 ) = 0 ;
	ts.at( 1 ) = 0 ;

	for ( int i = 2 ;  i <= limit ;  ++i )
		for ( int j = 2 * i ;  j <= limit ;  j += i )
			ts.at( j ) += i ;

	return ts ;
}


int main ()
{
	int const MAX_N = 1000000 ;
	vector< int > teilersumme = echteTeilersummen( MAX_N ) ;

	int maxKettenlaenge = 0 ;
	vector< int > maxKette ;
	for ( int i = 1 ;  i <= MAX_N ;  ++i )
	{
		int n = i ;
		vector< int > kette ;
		kette.push_back( n ) ;

		bool ueberlauf = false ;
		while ( true )
		{
			n = teilersumme.at( n ) ;
			if ( n > MAX_N )
			{
				ueberlauf = true ;
				break ;
			}

			// Überprüfung, ob das Kettenglied n in der Kette schon vorhanden ist
			bool kettenglied_vorhanden = false ;
			for ( int j = 0 ;  j < kette.size() ;  ++j )
				if ( kette.at( j ) == n )
				{
					kettenglied_vorhanden = true ;
					kette.push_back( n ) ;
					break ;
				}

			if ( kettenglied_vorhanden )
				break ;

			kette.push_back( n ) ;
		}

		if ( kette.at( 0 ) == kette.back() && !ueberlauf )
		{
			if ( kette.size() - 1 > maxKettenlaenge )
			{
				maxKettenlaenge = kette.size() - 1 ;
				maxKette = kette ;
			}
		}
	}

	int kleinstesKettenglied = INT_MAX ;
	for ( int i = 0 ;  i < maxKette.size() ;  ++i )
		kleinstesKettenglied = min( kleinstesKettenglied, maxKette.at( i ) ) ;

	cout << kleinstesKettenglied << endl ;


	return 0 ;
}