#include <iostream>
using namespace std ;

int const LIMIT = 10000000 ;
int d[ LIMIT ] = { 2 } ;

int main()
{
	int N = 0 ;

	d[ 1 ] = 1 ;
	for ( int n = 2 ;  n < LIMIT ;  ++n )
	{
		if ( d[ n ] == d[ n - 1 ] )
			++N ;

		for ( int j = 2*n ;  j < LIMIT ;  j += n )
			++d[ j ] ;
	}

	cout << N << endl ;

	return 0 ;
}