/*

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying 
by 1, 2, 3, 4, and 5, giving the pandigital, 918273645,
which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number
that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

*/

#include <iostream>
#include <cmath>
using namespace std ;

void zuruecksetzen( int* ziffernAnzahl, int* ziffernAnzahlNeu )
{
	for ( int i = 0 ;  i < 10 ;  ++i )
		ziffernAnzahl[ i ] -= ziffernAnzahlNeu[ i ] ;
}

// erwartet als Eingabe eine Zahl, in der jede Ziffer nur einmal vorkommt und nur die Ziffern 1-9
unsigned long long machePandigital( unsigned long long n )
{
	int ziffernAnzahl[ 10 ] = { 0 } ;

	unsigned long long n_kopie ;
	bool abbrechen ;

	int p = 1 ;
	for ( ;  true ;  ++p )
	{
		abbrechen = false ;

		n_kopie = p * n ;
		while ( n_kopie > 0 )
		{
			if ( ziffernAnzahl[ n_kopie % 10 ] > 0 )
			{
				abbrechen = true ;
				break ;
			}

			++ziffernAnzahl[ n_kopie % 10 ] ;
			n_kopie /= 10 ;
		}

		if ( abbrechen )
			break ;
	}

	int prod = 1 ;
	for ( int i = 1 ;  i < 10 ;  ++i )
		prod *= ziffernAnzahl[ i ] ;

	unsigned long long ergebnis = 0 ;
	if ( prod == 1 && p > 2 && ziffernAnzahl[ 0 ] == 0 )
	{
		for ( int i = 1 ;  i < p ;  ++i )
		{
			int z = i * n ;
			ergebnis *= pow( 10., int( log10( double( z ) ) ) + 1 ) ;
			ergebnis += z ;
		}
	}
	
	return ergebnis ;
}

int main ()
{
	unsigned long long max_pand = 0 ;
	for ( int i = 2 ;  i <= 100000 ;  ++i )
	{
		unsigned long long pandigitaleZahl = machePandigital( i ) ;
		if ( pandigitaleZahl != 0 )
			max_pand = max( pandigitaleZahl, max_pand ) ;
	}

	cout << max_pand << endl ;

	return 0 ;
}