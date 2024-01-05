/*

It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?

*/

#include <iostream>
#include "kettenbrueche.h"
using namespace std ;

int main ()
{
	int const MAX_KONV = 1000 ;
	vector< int > sqrt_2 = kettenbruch_sqrt( 2 ) ;


	ttmath::Int< 100 > pn = 0, pn_m1 = 1, pn_m2 = 0 ;
	ttmath::Int< 100 > qn = 0, qn_m1 = 0, qn_m2 = 1 ;

	int zaehlerMehrZiffern = 0 ;

	unsigned int z = 0 ;
	for ( unsigned int i = 0 ;  z < MAX_KONV + 1 ;  ++i, ++z )
	{
		if ( i >= sqrt_2.size() )
			i = 1 ;

		// Zähler entwickeln
		pn = pn_m1 * sqrt_2.at( i ) + pn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		pn_m2 = pn_m1 ;
		pn_m1 = pn ;


		// Nenner entwickeln
		qn = qn_m1 * sqrt_2.at( i ) + qn_m2 ; // q_n = b_n * q_(n-1) + q_(n-2)

		qn_m2 = qn_m1 ;
		qn_m1 = qn ;

		if ( pn.ToString().size() > qn.ToString().size() )
			++zaehlerMehrZiffern ;

	}

	cout << zaehlerMehrZiffern << endl ;

	return 0 ;
}