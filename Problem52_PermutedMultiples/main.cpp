/*

It can be seen that the number, 125874, and its double, 251748, contain exactly
the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

*/

#include <iostream>
using namespace std ;

// returns, if n is a permutation of m
bool isPermutation( unsigned long long n, unsigned long long m )
{
	int digits_n[ 10 ] = { 0 } ;
	int digits_m[ 10 ] = { 0 } ;

	while ( n > 0 )
	{
		++digits_n[ n % 10 ] ;
		n /= 10 ;
	}

	while ( m > 0 )
	{
		int md = m % 10 ;
		++digits_m[ md ] ;

		if ( digits_m[ md ] > digits_n[ md ] )
			return false ;

		m /= 10 ;
	}

	for ( int i = 0 ;  i < 10 ;  ++i )
		if ( digits_n[ i ] != digits_m[ i ] )
			return false ;

	return true ;
}

int main ()
{
	for ( int i = 1 ;  true ;  ++i )
		if ( isPermutation( i, 2*i ) && isPermutation( i, 3 * i ) && isPermutation( i, 4 * i )
			 && isPermutation( i, 5 * i ) && isPermutation( i, 6 * i ) )
		{
			cout << i << endl ;
			break ;
		}

	return 0 ;
}