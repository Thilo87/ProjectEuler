/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std ;

void tausche( char* text, int n, int k )
{
	char temp = text[ n ] ;
	text[ n ] = text[ k ] ;
	text[ k ] = temp ;
}

void permutiere(char* elems, int dimElems, int mid, int end, vector<char*>& liste )
{
    static int count;
    if (mid == end) {
		char* neu = new char[ dimElems ] ;
		for ( int i = 0 ;  i < dimElems ;  ++i )
			neu[ i ] = elems[ i ] ;

        liste.push_back( neu ) ;
        return ;
    }
    else {
    for (int i = mid; i <= end; i++) {
            tausche(elems, mid, i);
            permutiere(elems, dimElems, mid + 1, end, liste );
            tausche(elems, mid, i);
        }
    }
}

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

int main ()
{
	bool* istPrim = siebEratosthenes( 7654321 ) ;
	char zahl[] = "7654321" ;
	int dimZahl = 8 ;

	vector<char*> permutationen ;
	permutiere( zahl , dimZahl, 0, dimZahl-2, permutationen ) ;

	int groessteZahl = 0 ;
	for ( int i = 0 ;  i < permutationen.size() ;  ++i )
	{
		int alsZahl = 0 ;
		for ( int j = 0 ;  j < dimZahl-1 ;  ++j )
			alsZahl += ( permutationen.at( i )[ j ] - '0' ) * pow( 10., dimZahl - 2 - j )  ;
			
		if ( istPrim[ alsZahl ] )
			if ( alsZahl > groessteZahl )
				groessteZahl = alsZahl ;
	}

	cout << groessteZahl ;
	
	return 0 ;
}