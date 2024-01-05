/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of
the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

*/

#include <iostream>
using namespace std ;

bool isPandigital( unsigned long long n )
{
	if ( floor( log10( double( n ) ) ) + 1 != 10 )
		return false ;

	bool digit[ 10 ] = { false } ;
	while ( n > 0 )
	{
		digit[ n % 10 ] = true ;
		n /= 10 ;
	}

	for ( int i = 0 ;  i < 10 ;  ++i )
		if ( !digit[ i ] )
			return false ;

	return true ;
}

int main ()
{
	unsigned long long sum = 0 ;

	for ( int d1 = 1 ;  d1 <= 9 ;  ++d1 )
		for ( int d2 = 0 ;  d2 <= 9 ;  ++d2 )
			for ( int d3 = 0 ;  d3 <= 9 ;  ++d3 )
				for ( int d4 = 0 ;  d4 <= 8 ;  d4 += 2 )
					for ( int d5 = 0 ;  d5 <= 9 ;  ++d5 )
						if ( ( d3 * 100 + d4 * 10 + d5 ) % 3 == 0 )
							for ( int d6 = 0 ;  d6 <= 5 ;  d6 += 5 )
								for ( int d7 = 0 ;  d7 <= 9 ;  ++d7 )
									if ( ( d5 * 100 + d6 * 10 + d7 ) % 7 == 0 )
										for ( int d8 = 0 ;  d8 <= 9 ;  ++d8 )
											if ( ( d6 * 100 + d7 * 10 + d8 ) % 11 == 0 )
												for ( int d9 = 0 ;  d9 <= 9 ;  ++d9 )
													if ( ( d7 * 100 + d8 * 10 + d9 ) % 13 == 0 )
														for ( int d10 = 0 ;  d10 <= 9 ;  ++d10 )
															if ( (d8 * 100 + d9 * 10 + d10 ) % 17 == 0 )
																if ( isPandigital( d1 * 1000000000LL + d2 * 100000000LL + d3 * 10000000LL + d4 * 1000000LL + d5 * 100000LL + d6 * 10000LL + d7 * 1000LL + d8 * 100LL + d9 * 10LL + d10 ) )
																	sum += d1 * 1000000000LL + d2 * 100000000LL + d3 * 10000000LL + d4 * 1000000LL + d5 * 100000LL + d6 * 10000LL + d7 * 1000LL + d8 * 100LL + d9 * 10LL + d10 ;

	cout << sum << endl ;

	return 0 ;
}