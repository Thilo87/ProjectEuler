#include <iostream>
#include "primzahlen.h"
using namespace std ;

int main()
{
	int const LIMIT = 100000000 ;
	vector< int > primzahlen = primzahlliste( LIMIT / 2 ) ;

	int N = 0 ;
	for ( int i = primzahlen.size() - 1 ;  true ;  --i )
	{
		if ( primzahlen.at( i ) < 10000 )
			break ;
			
		for ( int j = 0 ;  true ;  ++j )
			if ( primzahlen.at( i ) * primzahlen.at( j ) < LIMIT )
				++N ;
			else
				break ;
	}

	// alle Primzahlen p < sqrt( 10^8 ) kann man einzeln quadrieren, um eine Zahl mit zwei Primfaktoren zu erhalten
	// es gibt 1229 Primzahlen < sqrt( 10^8 ), also 1229 Möglichkeiten

	// alle Primzahlen p < sqrt( 10^8 ) kann man zu zweit kombinieren
	// aus 1229 Primzahlen kann man 2 auswählen auf 1229 nCr 2 = 754606 Möglichkeiten

	cout << N + 1229 + 754606 << endl ;

	return 0 ;
}