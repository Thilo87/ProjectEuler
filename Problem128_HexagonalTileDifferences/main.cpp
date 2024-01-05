#include <iostream>
#include "primzahlen.h"
using namespace std ;

typedef unsigned long long uint64 ;

int main()
{
	int const MAX_DIFF = 1000000 ;
	bool* istPrim = siebEratosthenes( MAX_DIFF ) ;
	vector< uint64 > hexagons ;

	for ( uint64 r = 2 ;  hexagons.size() < 2000 ;  ++r )
		if ( istPrim[ 6*r - 1 ] )
		{
			if ( istPrim[ 6*r + 1 ] )
				if ( istPrim[ 12*r + 5 ] )
					hexagons.push_back( 2 + 3*r*( r - 1 ) ) ;

			if ( istPrim[ 12*r - 7 ] )
				if ( istPrim[ 6*r + 5 ] )
					hexagons.push_back( 3*( r*r + r ) + 1 ) ;
		}
	
	cout << hexagons.at( 1997 ) << endl ;

	delete[] istPrim ;

	return 0 ;
}