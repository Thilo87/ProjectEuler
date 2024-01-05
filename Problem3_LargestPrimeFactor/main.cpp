#include <iostream>
using namespace std ;

bool istPrim( long long n )
{
	for ( int i = 2 ;  i < n ;  ++i )
		if ( n % i == 0 )
			return false ;

	return true ;
}

void primfaktorzerlegung( long long n )
{
	for ( int i = 2 ;  i <= n ;  ++i )
		if ( istPrim( i ) ) // ist i Primzahl?
			if ( n % i == 0 ) // ist i ein Primfaktor von n?
			{
				n /= i ; // teile n durch den Primfaktor von n
				cout << i << endl ; // gebe Primfaktor aus
				i = 1 ; // beginne Schleife von vorne
			}
}

int main ()
{
	primfaktorzerlegung( 600851475143LL ) ;

	return 0 ;
}