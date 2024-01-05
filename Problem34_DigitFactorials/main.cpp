/*


145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

*/

#include <iostream>
using namespace std ;

int main ()
{
	int fak[ 10 ] = { 1, 1, 2, 2*3, 2*3*4, 2*3*4*5, 2*3*4*5*6, 2*3*4*5*6*7, 2*3*4*5*6*7*8, 2*3*4*5*6*7*8*9 } ;

	int endsumme = 0 ;
	for ( int i = 3 ;  i <= 2000000 ;  ++i )
	{
		unsigned long long summe = 0 ;
		int i_kopie = i ;

		while ( i_kopie > 0 )
		{
			summe += fak[ i_kopie % 10 ] ;
			i_kopie /= 10 ;
		}

		if ( summe == i )
			endsumme += i ;
	}

	cout << endsumme << endl ;

	return 0 ;
}