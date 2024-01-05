/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <iostream>
#include "teiler.h"
using namespace std ;

// ein "freundliches Paar" sind zwei Zahlen a, b mit a ungleich b, für die gilt, dass die Summe der Teiler
// von a gleich b ist und die Summe der Teiler von b gleich a ist. Dann nennt man a und b "freundliche Zahlen"
bool istFreundlicheZahl( unsigned long long a )
{
	unsigned long long b = echteTeilersumme( a ) ;

	if ( a != b )
		if ( echteTeilersumme( b ) == a )
			return true ;

	return false ;
}

int main ()
{
	unsigned long long summe = 0 ;
	for ( int a = 1 ;  a < 10000 ;  ++a )
	{
		unsigned long long b = echteTeilersumme( a ) ;

		if ( a != b )
			if ( echteTeilersumme( b ) == a )
				summe += a + b ;
	}

	cout << summe / 2 ;
	return 0 ;
}