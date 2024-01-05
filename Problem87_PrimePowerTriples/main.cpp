/*



The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28.
In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube,
and prime fourth power?

*/

#include <iostream>
#include <cmath>
#include "primzahlen.h"
using namespace std ;

int main ()
{
	bool* istPrim = siebEratosthenes( 7100 ) ;

	bool* istDarstellbar = new bool[ 50000000 ] ;
	for ( int i = 0 ;  i < 50000000 ;  ++i )
		istDarstellbar[ i ] = false ;

	for ( unsigned long long p1 = 2 ;  p1 <= 7069 ;  ++p1 )
		if ( istPrim[ p1 ] )
			for( unsigned long long p2 = 2 ;  p2 <= 367;  ++p2 )
				if ( istPrim[ p2 ] )
					for ( unsigned long long p3 = 2 ;  p3 <= 83 ;  ++p3 )
						if ( istPrim[ p3 ] )
						{
							long long zahl = p1 * p1 + p2 * p2 * p2 + p3 * p3 * p3 * p3 ;

							if ( zahl < 50000000 )
								istDarstellbar[ zahl ] = true ;
						}

	int anzahl = 0 ;
	for ( int i = 0 ;  i < 50000000 ;  ++i )
		if ( istDarstellbar[ i ] )
			++anzahl ;

	cout << anzahl << endl ;

	return 0 ;
}