/*

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 
there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

*/

#include <iostream>
using namespace std ;

int main ()
{
	int count[ 1001 ] = { 0 } ;

	for ( int a = 1 ;  a <= 1000 ;  ++a )
		for ( int b = a + 1 ;  a + b <= 1000 ;  ++b )
			for ( int c = b + 1 ;  a + b + c <= 1000 ;  ++c )
				if ( a*a + b*b == c*c )
					++count[ a + b + c ] ;

	int max_n = 0 ;
	int max_p = 0 ;
	for ( int p = 1 ;  p <= 1000 ;  ++p )
		if ( count[ p ] > max_n )
		{
			max_n = count[ p ] ;
			max_p = p ;
		}

	cout << "p: " << max_p << ", n: " << max_n << endl ;

	return 0 ;
}