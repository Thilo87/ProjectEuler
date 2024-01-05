/*

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/

#include <iostream>
#include <ttmath\ttmath.h>
#include <cmath>
using namespace std ;

int main ()
{
	int summe = 0 ;
	for ( int i = 2 ;  i <= 1000000 ;  ++i )
	{
		int ziffernSumme = 0 ;

		int i_kopie = i ;
		while ( i_kopie > 0 )
		{
			ziffernSumme += pow( i_kopie % 10, 5. ) ;
			i_kopie /= 10 ;
		}

		if ( ziffernSumme == i )
			summe += ziffernSumme ;
	}

	cout << summe << endl ;
	return 0 ;
}