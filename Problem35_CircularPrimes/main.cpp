/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

*/
#include <iostream>
#include <cmath>
using namespace std ;

// gibt ein bool-Array zurück, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( int n )
{
	bool* gestrichen = new bool[ n ] ;
	for ( int i = 0 ;  i < n ;  ++i )
		gestrichen[ i ] = false ;

	for ( int i = 2 ;  i <= sqrt( double( n ) ) ;  ++i )
		if ( !gestrichen[ i ] )
			for ( int j = i * i ;  j < n ;  j += i )
				gestrichen[ j ] = true ;

	// Liste invertieren
	for ( int i = 0 ;  i < n ;  ++i )
		if ( gestrichen[ i ] )
			gestrichen[ i ] = false ;
		else
			gestrichen[ i ] = true ;

	return gestrichen ;
}

// lässt eine Ganzzahl zirkulieren
void drehe( int& n )
{
	int letzteZiffer = n % 10 ;
	n = ( ( n - letzteZiffer ) / 10 ) + letzteZiffer * pow( 10., floor( log10( double( n ) ) ) ) ;
}

int main ()
{
	bool* istPrim = siebEratosthenes( 1000000 ) ;

	int anzahl = 1 ;
	for ( int i = 3 ;  i < 1000000 ;  i += 2 )
	{
		if ( istPrim[ i ] )
		{
			bool istPrimZirkulaer = true ;

			int tmp = i ;	// ursprüngliche Primzahl temporär speichern, um sie nach fehlgeschlagener
							// der Überprüfung auf zirkuläre Primzahleigenschaft wieder zurücksetzen kann und nicht
							// weiterdrehen muss, bis sie wieder ihre ursprüngliche Form hat ( zu ineffizient )
			for ( int j = 0 ;  j < floor( log10( double( i ) ) ) + 1 ;  ++j )
			{
				drehe( i ) ; // Zahl zirkulieren

				if ( !istPrim[ i ] )
				{
					istPrimZirkulaer = false ;
					i = tmp ;
					break ;
				}
			}

			if ( istPrimZirkulaer )
				++anzahl ;
		}
	}

	cout << anzahl ;
	return 0 ;
}

//void tausche( char* text, int n, int k )
//{
//	char temp = text[ n ] ;
//	text[ n ] = text[ k ] ;
//	text[ k ] = temp ;
//}
//
//void permutiere(char* elems, int mid, int end)
//{
//    static int count;
//    if (mid == end) {
//        cout << ++count << " : " << elems << endl;
//        return ;
//    }
//    else {
//    for (int i = mid; i <= end; i++) {
//            tausche(elems, mid, i);
//            permutiere(elems, mid + 1, end);
//            tausche(elems, mid, i);
//        }
//    }
//}