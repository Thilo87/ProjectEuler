#include <iostream>
#include <vector>
using namespace std ;

typedef unsigned long long uint64 ;
typedef long long int64 ;

int const LIMIT = 1000000 ;

int main()
{
	vector< vector< pair< uint64, uint64 > > > TGT( LIMIT ) ;

	uint64 N = 0 ;
	for ( int n = 2 ;  n < LIMIT ;  ++n )
	{
		TGT.at( n ).push_back( pair< uint64, uint64 >( 1, n ) ) ;
		for ( int j = n ;  j < LIMIT ;  j += n )
			TGT.at( j ).push_back( pair< uint64, uint64 >( n, j/n ) ) ;

		uint64 nL = 0 ;
		for ( int j = 0 ;  j < TGT.at( n ).size() ;  ++j )
		{
			int64 t = TGT.at( n ).at( j ).first ;
			if ( ( n + t*t ) % ( 4*t ) == 0 && ( 5*n + t*t ) % ( 4*t ) == 0 )
			{
				int64 c = ( n + t*t ) / ( 4*t ) ;
				int64 x = ( 5*n + t*t ) / ( 4*t ) ;
				int64 y = x - c ;
				int64 z = x - 2*c ;

				if ( x > 0 && y > 0 && z > 0 )
					++nL ;

			}
		}

		if ( nL == 10 )
			++N ;
	}

	cout << N << endl ;

	return 0 ;
}