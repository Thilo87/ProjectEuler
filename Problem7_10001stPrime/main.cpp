#include <iostream>
using namespace std ;

bool istPrim( long long n )
{
	for ( int i = 2 ;  i < n ;  ++i )
		if ( n % i == 0 )
			return false ;

	return true ;
}

long long ntePrimzahl( long long n )
{
	int z = 0 ;

	long long i = 2 ;
	for ( ;  z < n ;  ++i )
		if ( istPrim( i ) )
			++z ;

	return i - 1 ;
}

int main()
{
	cout << ntePrimzahl( 10001 ) ;
	return 0 ;
}