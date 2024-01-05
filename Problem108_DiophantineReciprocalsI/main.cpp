#include <iostream>
using namespace std ;

typedef unsigned long long uint64 ;
int const primzahlen[ 7 ] = { 2, 3, 5, 7, 11, 13, 17 } ;

int teiler( uint64 n )
{
	int t = 1 ;

	for ( int i = 0 ;  i < 7 ;  ++i )
	{
		int e = 0 ;
		while ( n % primzahlen[ i ] == 0 )
		{
			++e ;
			n /= primzahlen[ i ] ;
		}
		t *= ( 2*e + 1 ) ;
	}

	if ( n != 1 )
		return -1 ;
	else
		return t ;
}

int main()
{
	for ( uint64 n = 1 ;  true ;  ++n )
		if ( teiler( n ) / 2 > 1000 )
		{
			cout << n << endl ;
			break ;
		}
	
	return 0 ;
}