/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?

*/

#include <iostream>
#include <cmath>
using namespace std ;

unsigned long long ziffernQuadratSumme( unsigned long long n )
{
	int ziffernAnzahl = floor( log10( double( n ) ) ) + 1 ;

	unsigned long long summe = ( n % 10 ) * ( n % 10 ) ;
	for ( int i = 1 ;  i < ziffernAnzahl ;  ++i )
	{
		n /= 10 ;
		int ziffer = n % 10 ;
		summe += ziffer * ziffer ;
	}

	return summe ;
}

int main ()
{
	int anzahl89 = 0 ;
	for ( unsigned long long n = 1 ;  n <= 10000000 ;  ++n )
	{
		unsigned long long zQS = ziffernQuadratSumme( n ) ;

		while ( zQS != 1 && zQS != 89 )
			zQS = ziffernQuadratSumme( zQS ) ;

		if ( zQS == 89 )
			++anzahl89 ;
	}

	cout << anzahl89 * 2 << " " << "8581146" << endl ;

	return 0 ;
}