/*

A perfect number is a number for which the sum of its proper divisors is exactly equal 
to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, 
which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called
abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that 
can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can
be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that
the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

*/

#include <iostream>
#include "teiler.h"
using namespace std ;

// the smallest abundant number is the 12
// the smallest odd abundant number is the 945
// the smallest odd abundant number, which is not evenly divisible by 3, is 5.391.411.025
bool isAbundantNumber( unsigned long long n )
{
	if ( n < 12 ) // the smallest abundant number is the 12
		return false ;

	if ( n % 2 == 1 && n < 945 ) // the smallest odd abundant number is the 945
		return false ;

	if ( n % 2 == 1 && n % 3 != 0 && n < 5391411025 ) // the smallest odd abundant number, which is not evenly divisible by 3, is 5.391.411.025
		return false ;

	if ( echteTeilersumme( n ) > n )
		return true ;

	return false ;
}

int main ()
{
	// bool-array with all the abundant numbers
	bool isAbundant[ 28124 ] = { false } ;
	for ( int i = 1 ;  i <= 28123 ;  ++i )
		if ( isAbundantNumber( i ) )
			isAbundant[ i ] = true ;
		else
			isAbundant[ i ] = false ;

	unsigned long long sum = 0 ;
	for ( int k = 1 ;  k <= 28123 ;  ++k )
	{
		bool sumAbundant = false ;
		for ( int i = 1 ;  i <= k / 2 ;  ++i )
		{
			if ( isAbundant[ i ] && isAbundant[ k - i ] ) // k can be written as the sum of two abundant numbers
			{
				sumAbundant = true ;
				break ;
			}
		}

		if ( sumAbundant == false )
			sum += k ;
	}

	cout << sum << endl ;

	return 0 ;
}