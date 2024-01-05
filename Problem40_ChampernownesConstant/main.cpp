/*

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std ;

// gibt die ersten n Nachkommastellen von Champernowne's Zahl als Vector zurück
vector< int > nachkommastellenChamp( int n )
{
	vector< int > stellen ;

	int z = 1 ;
	while ( stellen.size() < n )
	{
		int ziffern = floor( log10( double( z ) ) ) + 1 ;
		for ( int i = 0 ;  i < ziffern ;  ++i )
			stellen.push_back( int( z / pow( 10., ziffern - i - 1 ) ) % 10 ) ;

		++z ;
	}

	// überflüssige Stellen entfernen
	while ( stellen.size() > n )
		stellen.pop_back() ;

	return stellen ;
}

int main ()
{
	vector< int > stellen = nachkommastellenChamp( 1000001 ) ;

	cout << stellen.at( 0 ) * stellen.at( 9 ) * stellen.at( 99 ) * stellen.at( 999 ) * stellen.at( 9999 ) * stellen.at( 99999 ) * stellen.at( 999999 ) << endl ;

	return 0 ;
}