#include <iostream>
#include <cmath>
#include <ttmath\ttmath.h>
using namespace std ;

// enhaltener 7-er Exponent in der n!-Fakultät
int ex( int n )
{
	int e = 0 ;
	for ( int i = 7 ;  i <= n ;  i *= 7 )
		e += n / i ;

	return e ;
}

typedef unsigned long long uint64 ;

uint64 N( uint64 n ) 
{
	uint64 N = 1 ;
	while ( n > 0 )
	{
		N *= ( n % 7 )  + 1 ;
		n /= 7 ;
	}

	return N ;
}

int main()
{
	uint64 Ng = 0 ;
	for ( uint64 i = 0 ;  i < 1000000000 ;  ++i )
		Ng += N( i ) ;

	cout << Ng << endl ;

	

	//unsigned long long z = 21 ;
	//unsigned long long E = z * ( z + 1 ) / 2 ;

	//unsigned long long N = 0 ;

	//for ( int r = 1 ;  r <= z ;  ++r )
	//{
	//	int exr = ex( r ) ;
	//	for ( int n = 2 ;  n <= z - r ;  ++n )
	//		if ( ex( n + r - 1 ) - ex( n - 1 ) > exr ) // f_{r}^n durch 7 teilbar
	//			++N ;
	//}
	//
	//cout << E - N << endl ;
	
	return 0 ;
}