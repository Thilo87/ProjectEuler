/*

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

It turns out that F541, which contains 113 digits, is the first Fibonacci number
for which the last nine digits are 1-9 pandigital (contain all the digits 1 to 9,
but not necessarily in order). And F2749, which contains 575 digits, is the first
Fibonacci number for which the first nine digits are 1-9 pandigital.

Given that Fk is the first Fibonacci number for which the first nine digits 
AND the last nine digits are 1-9 pandigital, find k.

*/

#include <iostream>
using namespace std ;

typedef unsigned long long uint64 ;


bool istPandigital19( uint64 n )
{
	int ziffernAnzahl[ 10 ] = { 0 } ;
	
	while ( n > 0 )
	{
		++ziffernAnzahl[ n % 10 ] ;

		if ( ziffernAnzahl[ n % 10 ] > 1 )
			return false ;

		n /= 10 ;
	}

	if ( ziffernAnzahl[ 0 ] > 0 )
		return false ;

	for ( int i = 1 ;  i < 10 ;  ++i )
		if ( ziffernAnzahl[ i ] != 1 )
			return false ;

	return true ;
}

double const log10_sqrt5 = log10( sqrt( 5. ) ) ;
double const log10_goldSchnitt = log10( ( 1 + sqrt( 5. ) ) / 2. ) ;

uint64 F( int n, int a )
{	
	double v = n * log10_goldSchnitt - log10_sqrt5 ;
	return pow( 10., v - floor( v ) + 8 ) ;
}

int main ()
{
	uint64 F_nm1 = 1, F_nm2 = 1 ;
	uint64 F_n ;

	int a = 9 ;

	for ( int n = 2 ;  true ;  ++n )
	{
		F_n = ( F_nm2 + F_nm1 ) % 1000000000 ;
		F_nm1 = F_nm2 ;
		F_nm2 = F_n ;

		if ( n > 2 )
			if ( istPandigital19( F_n ) )
				if ( istPandigital19( F( n + 1, a ) ) )
				{
					cout << n + 1 << endl ;
					break ;
				}
	}
	return 0 ;
}