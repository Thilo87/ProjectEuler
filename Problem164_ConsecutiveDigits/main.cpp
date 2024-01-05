#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

typedef unsigned long long uint64 ;
typedef ttmath::Int< 10 > BigInteger ;

BigInteger moeglichkeiten( int& k, int d1, int d2, int i ) ;
BigInteger moeglichkeiten( int k ) ;


BigInteger tabelle[ 10 ][ 10 ][ 20 ] ;

BigInteger moeglichkeiten( int k )
{
	BigInteger N = 0 ;
	int& kn = k ;
	for ( int d = 1 ;  d <= 9 ;  ++d )
		N += moeglichkeiten( kn, d, 0, 1 ) ;

	return N ;
}

BigInteger moeglichkeiten( int& k, int d1, int d2, int i )
{
	if ( i == k )
		return 0 ;

	BigInteger N = 0 ;

	if ( i == k - 1 )
		return 10 - d1 - d2 ;
	else
		for ( int d = 0 ;  d < 10 - d1 - d2 ;  ++d )
			if ( tabelle[ d ][ d1 ][ i ] != -1 ) // wenn die tabelle diesen Eintrag schon enthält
				N += tabelle[ d ][ d1 ][ i ] ;
			else // ansonsten berechnen
			{
				tabelle[ d ][ d1 ][ i ] = moeglichkeiten( k, d, d1, i + 1 ) ;
				N += moeglichkeiten( k, d, d1, i + 1 ) ;
			}

	return N ;
}

int main()
{
	// tabelle mit "undefiniert" füllen
	for ( int i = 0 ;  i < 10 ;  ++i )
		for ( int j = 0 ;  j < 10 ;  ++j )
			for ( int k = 0 ;  k < 20 ;  ++k )
				tabelle[ i ][ j ][ k ] = -1 ;

	BigInteger N = moeglichkeiten( 20 ) ;

	cout << N << endl ;

	return 0 ;
}

