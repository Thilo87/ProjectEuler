/*

In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

*/

#include <iostream>
using namespace std ;

int main ()
{
	int muenzen[ 8 ] = { 1, 2, 5, 10, 20, 50, 100, 200 } ;
	int wege[ 200 + 1 ] = { 0 } ;
	wege[ 0 ] = 1 ;

	for ( int i = 0 ;  i < 8 ;  ++i )
		for ( int j = muenzen[ i ] ;  j <= 200 ;  ++j )
			wege[ j ] += wege[ j - muenzen[ i ] ] ;

	cout << wege[ 200 ] << endl ;
	
	return 0 ;
}