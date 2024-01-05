/*

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

*/

#include <iostream>
#include <cmath>
#include <climits>
#include "primzahlen.h"
using namespace std ;

typedef unsigned long long ULL ;

// gibt zurück, ob n eine Permutation von m ist
bool istPermutation( ULL n, ULL m )
{
	int ziffern_n[ 10 ] = { 0 } ;
	int ziffern_m[ 10 ] = { 0 } ;

	while ( n > 0 )
	{
		++ziffern_n[ n % 10 ] ;
		n /= 10 ;
	}

	while ( m > 0 )
	{
		int md = m % 10 ;
		++ziffern_m[ md ] ;

		if ( ziffern_m[ md ] > ziffern_n[ md ] )
			return false ;

		m /= 10 ;
	}

	for ( int i = 0 ;  i < 10 ;  ++i )
		if ( ziffern_n[ i ] != ziffern_m[ i ] )
			return false ;

	return true ;
}

int main ()
{

	int const MAX_N = 10000000 ;
	bool* istPrim = siebEratosthenes( MAX_N ) ;

	int max_n = 0 ;
	double min_ratio = DBL_MAX ;
	for ( int n = 2 ;  n < MAX_N ;  ++n )
	{
		int phi = eulerschePhiFunktion( n, istPrim ) ;
		
		if ( n / double( phi ) < min_ratio )
			if ( istPermutation( n, phi ) )
			{
				min_ratio = n / double( phi ) ;
				max_n = n ;
			}

		if ( n % 100000 == 0 )
			cout << n << endl ;
	}

	cout << max_n << endl ;

	delete[] istPrim ;


	return 0 ;
}