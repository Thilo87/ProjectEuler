#include <iostream>
#include "primzahlen.h"
#include <set>
using namespace std ;

struct cmp
{
	bool operator()( const pair< long long, long long >& lhs, const pair< long long, long long >& rhs )
	{
		return lhs.second < rhs.second ;
	}
} ;

int main ()
{
	int const MAX_N = 100000 ;
	vector< int > primzahlen = primzahlliste( MAX_N ) ;

	multiset< pair< long long, long long >, cmp > werte ; // ( n, rad( n ) ), sortiert nach rad( n )

	for ( int n = 1 ;  n <= MAX_N ;  ++n )
	{
		unsigned long long rad_n = 1 ;
		for ( int i = 0 ;  i < primzahlen.size() ;  ++i )
			if ( n % primzahlen.at( i ) == 0 )
				rad_n *= primzahlen.at( i ) ;

		werte.insert( pair< long long, long long >( n, rad_n ) ) ;
	}

	int j = 1 ;
	for ( multiset< pair< long long, long long >, cmp >::iterator i = werte.begin() ;  i != werte.end() ;  ++i, ++j )
	{
		if ( j == 10000 )
			cout << (*i).first << endl ;
	}

	
	return 0 ;
}