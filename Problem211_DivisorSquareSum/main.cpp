/*

For a positive integer n, let σ2(n) be the sum of the squares of its divisors. For example,
σ2(10) = 1 + 4 + 25 + 100 = 130.

Find the sum of all n, 0 < n < 64,000,000 such that σ2(n) is a perfect square.

*/

#include <iostream>
#include <vector>
#include <climits>
#include <ttmath\ttmath.h>
using namespace std ;

int const MAX_N = 64000000 ;
unsigned long long sigma_2s[ MAX_N ] = { 0 } ;

bool istPerfektesQuadrat( unsigned long long n )
{
	if ( n % 4 && n % 8 != 1 )
		return false ;

	unsigned long long mod16 = n % 16 ;
	if ( mod16 > 2 && mod16 != 4 && mod16 != 9 )
		return false ;

	double sqrt_n = sqrt( double( n ) ) ;
	return sqrt_n == int( sqrt_n ) ;
}

int main ()
{
	sigma_2s[ 1 ] = 1 ;

	unsigned long long summe = 0 ;
	for ( int i = 2 ;  i < MAX_N ;  ++i )
	{
		for ( int j = i ;  j < MAX_N ;  j += i )
			sigma_2s[ j ] += pow( i, 2. ) ;

		if ( istPerfektesQuadrat( sigma_2s[ i ] + 1 ) )
			summe += i ;
	}

	cout << summe + 1 << endl ;

	return 0 ;
}