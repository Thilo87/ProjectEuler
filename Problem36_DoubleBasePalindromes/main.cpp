/* 

The decimal number, 585 = 1001001001(2) (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/

#include <iostream>
#include <cmath>
#include "stellenwertsysteme.h"
#include <vector>
using namespace std ;

// gibt die i-te Ziffern von n zurück
int iteZiffer( int i, long long n )
{
	return int( ( n % int( pow(10., i) ) ) / pow( 10., i-1 ) ) ;
}

// gibt Anzahl der Ziffern von n zurück
int ziffernanzahl( long long n )
{
	return int( log10( double( n ) ) ) + 1 ;
}

// ist n ( gegeben als Dezimalzahl ) ein Palindrom ?
bool istPalindrom( long long n )
{
	int ziffern = ziffernanzahl( n ) ;

	for ( int i = 1 ;  i <= ziffern / 2 ;  ++i )
		if ( iteZiffer( i, n ) != iteZiffer( ziffern - i + 1, n ) )
			return false ;
	return true ;
}

// ist n ( gegeben als Binärzahl ) ein Palindrom ?
bool istPalindrom( vector< int > binaerzahl )
{
	int ziffern = binaerzahl.size() ;

	for ( int i = 0 ;  i <= ziffern / 2 ;  ++i )
		if ( binaerzahl.at( i ) != binaerzahl.at( ziffern - i - 1 ) )
			return false ;
	return true ;
}


int main ()
{
	unsigned long long summe = 0 ;
	for ( int i = 0 ;  i < 1000000 ;  ++i )
		if ( istPalindrom( i ) )
		{
			vector< int > binaerzahl = dez_in_bin_v( i ) ;
			if ( istPalindrom( binaerzahl ) )
			{
				summe += i ;
			}
		}

	cout << summe ;

	return 0 ;
}