#include <iostream>
#include <cmath>
using namespace std ;

// ist n Primzahl ?
bool istPrim( long long n )
{
	for ( int i = 2 ;  i <= sqrt( double( n ) ) ;  ++i )
		if ( n % i == 0 )
			return false ;

	return true ;
}

int main ()
{
	unsigned long long summe = 5 ;

	for ( int n = 5 ;  n < 2000000 ;  n += 2 )
		if ( istPrim( n ) )
			summe += n ;

	cout << summe ;
	return 0 ;
}