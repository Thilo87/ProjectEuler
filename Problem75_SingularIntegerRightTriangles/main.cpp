/*

It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5)
24 cm: (6,8,10)
30 cm: (5,12,13)
36 cm: (9,12,15)
40 cm: (8,15,17)
48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?

*/

#include <iostream>
#include <vector>
using namespace std ;

typedef unsigned long long ULL ;

int const MAX_L = 1500000 ;
int count[ MAX_L + 1 ] = { 0 } ;

int gcd( int a , int b )
{
	while ( b != 0 )
	{
		int h = a % b ;
		a = b ;
		b = h ;
	}

	return a ;
}

int main ()
{
	vector< vector< int > > relPrimeNumbers ;

	int n = 0 ;

	for ( int i = 1 ;  i <= 1225 ;  ++i )
		for ( int j = i + 1 ;  j <= 1225 ;  ++j )
			if ( gcd( i, j ) == 1 )
			{
				vector< int > relPrimePair ;
				relPrimePair.push_back( i ) ;
				relPrimePair.push_back( j ) ;

				relPrimeNumbers.push_back( relPrimePair ) ;
			}
	
	for ( int z = 0 ;  z < relPrimeNumbers.size() ;  ++z )
	{
		ULL u = relPrimeNumbers.at( z ).at( 1 ) ;
		ULL v = relPrimeNumbers.at( z ).at( 0 ) ;

		if ( ( u + v ) % 2 != 0 )
		{
			ULL a = u*u - v*v ;
			ULL b = 2*u*v ;
			ULL c = u*u + v*v ;

			if ( a + b + c <= MAX_L )
			{
				int p = a + b + c ;
				for ( int k = 1 ;  k * p <= MAX_L ;  ++k )
					++count[ k * p ] ;
			}
		}
	}

	
	for ( int i = 0 ;  i <= MAX_L ;  ++i )
		if ( count[ i ] == 1 )
			++n ;

	cout << n << endl ;
	return 0 ;
}