#include <iostream>
#include <fstream>
#include <cmath>
using namespace std ;

int main ()
{
	// Matrix vom Format (DIM_I, DIM_J)
	int const DIM_I = 20 ;
	int const DIM_J = 20 ;

	int matrix[ DIM_I ][ DIM_J] ;

	// Matrix einlesen
	ifstream fin( "matrix.txt" ) ;

	if ( !fin )
		return -1 ;

	for ( int i = 0 ;  i < DIM_I ;  ++i )
		for ( int j = 0 ;  j < DIM_J ;  ++j )
			fin >> matrix[ i ][ j ] ;

	fin.close() ;


	// größtes Produkt aus 4 Zahlen in der Matrix finden

	int groesstesProdukt = 0 ;

	// diagonal von oben links nach unten rechts
	for ( int i = 0 ;  i <= DIM_I - 4 ;  ++i )
		for ( int j = 0 ;  j <= DIM_J - 4 ;  ++j )
		{
			int produkt = 1 ;
			for ( int k = 0 ;  k < 4 ;  ++k )
				produkt *= matrix[ k + i ][ j + k ] ;

			groesstesProdukt = max( produkt, groesstesProdukt ) ;
		}

	// diagonal von oben rechts nach unten links
	for ( int i = 0 ;  i <= DIM_I - 4 ;  ++i )
		for ( int j = DIM_J - 1 ;  j >= 3 ;  --j )
		{
			int produkt = 1 ;
			for ( int k = 0 ;  k < 4 ;  ++k )
				produkt *= matrix[ k + i ][ j - k ] ;

			groesstesProdukt = max( produkt, groesstesProdukt ) ;
		}

	// von links nach rechts
	for ( int i = 0 ;  i < DIM_I ;  ++i )
		for ( int j = 0 ;  j <= DIM_J - 4 ;  ++j )
		{
			int produkt = 1 ;
			for ( int k = 0 ;  k < 4 ;  ++k )
				produkt *= matrix[ i ][ j + k ] ;
			
			groesstesProdukt = max( produkt, groesstesProdukt ) ;
		}

	// von oben nach unten
	for ( int i = 0 ;  i <= DIM_I - 4 ;  ++i )
		for ( int j = 0 ;  j < DIM_J ;  ++j )
		{
			int produkt = 1 ;
			for ( int k = 0 ;  k < 4 ;  ++k )
				produkt *= matrix[ k + i ][ j ] ;

			groesstesProdukt = max( produkt, groesstesProdukt ) ;
		}
	
	cout << groesstesProdukt << endl << endl ;

	return 0 ;
}