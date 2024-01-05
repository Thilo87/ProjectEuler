#include <iostream>
#include <vector>
using namespace std ;

int const MAX_N = 1000000 ;
vector< int > T[ MAX_N + 1 ] ;

int main ()
{
	int Ng = 0 ;

	for ( int n = 2 ;  n <= MAX_N ;  ++n )
	{
		T[ n ].push_back( 1 ) ;
		for ( int j = n ;  j <= MAX_N ;  j += n )
			T[ j ].push_back( n ) ;

		int N = 0 ;
		for ( vector< int >::iterator t = T[ n ].begin() ;  t != T[ n ].end() ;  ++t )
			if ( (*t) % 2 == 0 && n % ( 2*(*t) ) == 0 )
				++N ;

		Ng += N / 2 ;
	}	

	cout << Ng << endl ;

	return 0 ;
}