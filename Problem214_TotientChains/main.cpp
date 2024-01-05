#include <iostream>
#include "primzahlen.h"
using namespace std ;

int const LIMIT = 40000000 ;
int phi[ LIMIT + 1 ] = { 1 } ;

int main()
{
	vector< int > primzahlen = primzahlliste( LIMIT ) ;

	// Phi-Werte erzeugen
	for ( int n = 0 ;  n <= LIMIT ;  ++n )
		phi[ n ] = n ;

	for ( int i = 0 ;  i < primzahlen.size() ;  ++i )
	{
		int p = primzahlen.at( i ) ;
		for ( int j = p ;  j <= LIMIT ;  j += p )
			phi[ j ] -= phi[ j ] / p ;
	}


	unsigned long long summe = 0 ;
	for ( int i = 0 ;  i < primzahlen.size() ;  ++i )
	{
		int p = primzahlen.at( i ) ;

		int wert = phi[ p ] ;
		int kettenlaenge = 2 ;

		bool fehler = false ;
		while ( wert != 1 )
		{
			wert = phi[ wert ] ;
			++kettenlaenge ;

			if ( kettenlaenge > 25 )
			{
				fehler = true ;
				break ;
			}
		}

		if ( !fehler && kettenlaenge == 25 )
			summe += p ;
	}

	cout << summe << endl ;

	return 0 ;
}