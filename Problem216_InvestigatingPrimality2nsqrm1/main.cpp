#include <iostream>
//#include "MRTBig.h"
#include "primzahlen.h"
#include <cmath>
using namespace std ;

int const LIMIT = 50000000 ;
bool istPrim[ LIMIT + 1 ] ;

int main()
{
	typedef unsigned long long uint64 ;
	typedef long long int64 ;

	int N = 0 ;

	for ( int i = 0 ;  i <= LIMIT ;  ++i )
		istPrim[ i ] = true ;
	istPrim[ 0 ] = istPrim[ 1 ] = false ;


	for ( int64 n = 2 ;  n <= LIMIT ;  ++n )
	{
		int64 b = 2*n*n - 1 ;
		for ( int64 k = 1 ;  true ;  ++k )
			if ( b*k + n <= LIMIT )
				istPrim[ b*k + n ] = false ;
			else
				break ;


		for ( int64 k = -1 ;  true ;  --k )
			if ( -( b*k + n ) <= LIMIT )
				istPrim[ -( b*k + n ) ] = false ;
			else
				break ;
	}

	for ( uint64 i = 2 ;  i <= LIMIT ;  ++i )
	{
		if ( i % 100000 == 0 )
			cout << i << endl ;

		if ( istPrim[ i ] )
		{
			if ( istPrim_MRD( 2*i*i - 1 ) )
				++N ;
		}
	}

	cout << N << endl ;
	

	return 0 ;
}