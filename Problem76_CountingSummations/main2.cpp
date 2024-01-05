/*

It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?

*/

#include <iostream>
using namespace std ;

int main ()
{
	int wege[ 100 + 1 ] = { 0 } ;
	wege[ 0 ] = 1 ;

	for ( int i = 1 ;  i <= 99 ;  ++i )
		for ( int j = i ;  j <= 100 ;  ++j )
			wege[ j ] += wege[ j - i ] ;

	cout << wege[ 100 ] << endl ;
	return 0 ;
}