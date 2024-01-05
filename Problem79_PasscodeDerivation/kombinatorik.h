#include <iostream>
#include <vector>
using namespace std ;

// speichert in m alle Möglichkeiten, k Elemente aus e auszuwählen ( e.size() über k )
template< typename T >
void k_aus_n( int k, vector< T > e, vector< vector< T > >& m )
{
	vector< T > c ;
	k_aus_n< T >( k, e, m, 1, -1, c ) ;
}

template< typename T >
static 
void k_aus_n( int k, vector< T > e, vector< vector< T > >& m, int s, int j, vector< T >& c )
{
	for ( int i = j + 1 ;  i < e.size() ;  ++i )
	{
		c.push_back( e.at( i ) ) ;

		if ( s == k )
			m.push_back( c ) ;
		else
			k_aus_n< T >( k, e, m, s + 1, i, c ) ;

		c.pop_back() ;
	}
}