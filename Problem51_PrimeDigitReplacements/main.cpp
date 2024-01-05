/*

By replacing the 1st digit of the 2-digit number *3, it turns out that
six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this
5-digit number is the first example having seven primes among the
ten generated numbers, yielding the family: 56003, 56113, 56333,
56443, 56663, 56773, and 56993. Consequently 56003, being the
first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number
(not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "primzahlen.h"
using namespace std ;

void plusEins( bool* arr, int dim, int pos = -1 )
{
	if ( pos == -1 )
		pos = dim - 1 ;

	if ( arr[ pos ] == 0 )
		arr[ pos ] = 1 ;
	else
	{
		arr[ pos ] = 0 ;
		if ( pos - 1 >= 0 )
			plusEins( arr, dim, pos - 1 ) ;
	}
}

int main ()
{
	int const MAX_PRIMZAHL = 1000000 ;
	bool* istPrim = siebEratosthenes( MAX_PRIMZAHL ) ;

	for ( int p = 1 ;  p <= MAX_PRIMZAHL ;  ++p )
		if ( istPrim[ p ] )
		{
			bool abbrechen = false ;

			int nZiffern = int( log10( double( p ) ) ) + 1 ;

			bool* ersetzen = new bool[ nZiffern ] ;
			for ( int j = 0 ;  j < nZiffern ;  ++j )
				ersetzen[ j ] = false ;

			int* ziffern = new int[ nZiffern ] ;
			int p_kpi = p ;
			for ( int z = 0 ;  p_kpi > 0 ;  ++z )
			{
				ziffern[ z ] = p_kpi % 10 ;
				p_kpi /= 10 ;
			}

			for ( int j = 0 ;  j < pow( 2., nZiffern ) - 2 ;  ++j )
			{
				plusEins( ersetzen, nZiffern ) ;
				vector< int > familie ;

				for ( int z = 0 ;  z <= 9 ;  ++z )
				{
					int* ziffern_kpi = new int[ nZiffern ] ;
					for ( int k = 0 ;  k < nZiffern ;  ++k )
						ziffern_kpi[ k ] = ziffern[ k ] ;

					bool abbruch = false ;
					// ersetze alle Ziffern in p, für die ersetzen[ k ] = true ist, mit z
					for ( int k = 0 ;  k < nZiffern ;  ++k )
						if ( ersetzen[ k ] == true )
						{
							if ( ziffern_kpi[ k ] == z )
							{
								abbruch = true ;
								break ;
							}

							ziffern_kpi[ k ] = z ;
						}

					if ( abbruch )
						continue ;
						
					int neueZahl = 0 ;
					for ( int k = 0 ;  k < nZiffern ;  ++k )
						neueZahl += ziffern_kpi[ k ] * pow( 10., k ) ;

					if ( istPrim[ neueZahl ] && int( log10( double( neueZahl ) ) ) + 1 == nZiffern )
					{
						bool vorhanden = false ;
						for ( int k = 0 ;  k < familie.size() ;  ++k )
							if ( familie.at( k ) == neueZahl )
							{
								vorhanden = true ;
								break ;
							}

						if ( !vorhanden )
							familie.push_back( neueZahl ) ;
					}

					delete[] ziffern_kpi ;
				}
				
				
				if ( familie.size() == 8 )
				{
					cout << "Loesung: " << p << endl << endl ;
					for ( int k = 0 ;  k < familie.size() ;  ++k )
						cout << familie.at( k ) << endl ;
					abbrechen = true ;
					break ;
				}
			}

			delete[] ziffern ;
			delete[] ersetzen ;

			if ( abbrechen )
				break ;
		}


	delete[] istPrim ;




	return 0 ;
}