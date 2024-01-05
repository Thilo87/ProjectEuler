/*

The 5-digit number, 16807=75, is also a fifth power.
Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

*/

#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

int main ()
{
	int n = 0 ;

	for ( int a = 1 ;  a <= 1000 ;  ++a )
		for ( int b = 1 ;  b <= 1000 ;  ++b )
		{
			if ( floor( b * log10( double( a ) ) ) + 1 == b )
				++n ;
		}

	cout << n << endl ;

	return 0 ;
}