#include <iostream>
#include <set>
#include <vector>
#include "primzahlen.h"
using namespace std ;

typedef long long int64 ;

void primMenge( int z[ 9 ], vector< vector< int64 > >& m, int s = 0, vector< int64 > e = vector< int64 >( 0 ) )
{
	int64 n = 0 ;
	for ( int i = s ;  i < 9 ;  ++i )
	{
		n *= 10 ;
		n += z[ i ] ;

		if ( istPrim_MRD( n ) )
		{
			e.push_back( n ) ;
			if ( i == 8 )
				m.push_back( e ) ;
			else
			{
				primMenge( z, m, i + 1, e ) ;
				e.pop_back() ;
			}
		}
	}
}

int main ()
{
	int z[] = { 1,2,3,4,5,6,7,8,9 } ;
	set< vector< int64 > > k ;

	do
	{
		vector< vector< int64 > > m ;
		primMenge( z, m ) ;
		for ( int i = 0 ;  i < m.size() ;  ++i )
			sort( m.at( i ).begin(), m.at( i ).end() ) ;

		k.insert( m.begin(), m.end() ) ;
	}
	while ( next_permutation( z, z + 9 ) ) ;

	cout << k.size() << endl ;

	return 0 ;
}