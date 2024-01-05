#include <iostream>
using namespace std ;

typedef unsigned long long uint64 ;
typedef long long int64 ;

int const LIMIT = 50000000 ;
int const U = 1 ;

bool istLoesung( uint64 t, uint64 n )
{
	if ( ( n + t*t ) % ( 4*t ) == 0 && ( 5*n + t*t ) % ( 4*t ) == 0 )
	{
		int64 c = ( n + t*t ) / ( 4*t ) ;
		int64 x = ( 5*n + t*t ) / ( 4*t ) ;
		int64 y = x - c ;
		int64 z = x - 2*c ;

		if ( x > 0 && y > 0 && z > 0 )
			return true ;
		else
			return false ;
	}
	else
		return false ;
}

uint64 nL[ LIMIT ] = { 0 } ;	
int main()
{
	uint64 N = 0 ;
	for ( uint64 n = 2 ;  n < LIMIT ;  ++n )
	{
		if ( nL[ n ] > U )
			continue ;

		if ( istLoesung( 1, n ) )
			++nL[ n ] ;

		for ( int j = n ;  j < LIMIT ;  j += n )
		{
			if ( nL[ j ] > U )
				continue ;

			if ( istLoesung( n, j ) )
				++nL[ j ] ;
		}

		if ( nL[ n ] == U )
			++N ;
	}

	cout << N << endl ;

	return 0 ;
}