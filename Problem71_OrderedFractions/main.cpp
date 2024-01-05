#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std ;

// steinscher Algorithmus um den ggT( a, b ) zu berechnen
long long ggT_Stein( long long a, long long b )
{
	if ( a == 0 )
		return b ;

	long long k = 0 ;
	while ( a % 2 == 0 && b % 2 == 0 )
	{
		a /= 2 ;
		b /= 2 ;
		++k ;
	}

	long long t ;
	if ( a % 2 == 1 )
		t = -b ;
	else
		t = a ;

	while ( t != 0 )
	{
		while ( t % 2 == 0 )
			t /= 2 ;
		if ( t > 0 )
			a = t ;
		else
			b = -t ;

		t = a - b ;
	}

	return a * pow( 2., int( k ) ) ;
}

vector< long long > kuerzen( long long zaehler, long long nenner )
{
	long long ggT = ggT_Stein( zaehler, nenner ) ;
	
	vector< long long > gekuerzterBruch( 2 ) ;
	gekuerzterBruch.at( 0 ) = zaehler / ggT ;
	gekuerzterBruch.at( 1 ) = nenner / ggT ;

	return gekuerzterBruch ;
}



int main ()
{
	unsigned long long d2 = -1 ;
	unsigned long long n2 = 1 ;

	for ( unsigned long long d = 2 ;  d <= 1000000 ;  ++d )
		for ( unsigned long long n = ( 3 / 7. ) * d ;  n >= ceil( ( n2 / double( d2 ) ) * d ) ;  --n )
		{
			if ( 3 * d > 7 * n )
				if ( n * d2 >= n2 * d )
				{
					n2 = n ;
					d2 = d ;
				}
		}

	vector< long long > bruch = kuerzen( n2, d2 ) ;
	cout << bruch.at( 0 ) << " / " << bruch.at( 1 ) << endl ;

	return 0 ;
}