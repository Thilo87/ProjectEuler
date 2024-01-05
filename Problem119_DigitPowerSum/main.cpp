#include <iostream>
#include <ttmath\ttmath.h>
#include <vector>
#include <algorithm>
using namespace std ;

typedef ttmath::Int< 1000 > BigInteger ;
typedef unsigned long long uint64 ;

BigInteger ziffernSumme( BigInteger n )
{
	BigInteger summe = 0 ;
	while ( n > 0 )
	{
		summe += n % 10 ;
		n /= 10 ;
	}
	return summe ;
}

int main()
{
	vector< BigInteger > zahlen ;
	int N = 0 ;
	for ( int n = 4 ;  true ;  ++n )
	{
		bool abbruch = false ;
		BigInteger c( n ) ;
		for ( int e = 2 ;  e <= 50 ;  ++e )
		{
			c *= n ;
			
			if ( ziffernSumme( c ) == n )
			{
				++N ;
				zahlen.push_back( c ) ;
			}

			if ( N >= 40 )
			{
				abbruch = true ;
				break ;
			}
		}

		if ( abbruch )
			break ;
	}

	sort( zahlen.begin(), zahlen.end() ) ;

	cout << zahlen.at( 29 ) << endl ;
	return 0 ;
}