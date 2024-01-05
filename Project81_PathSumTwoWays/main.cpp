/*

In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

	
131	673	234	103	18
201	96	342	965	150
630	803	746	422	111
537	699	497	121	956
805	732	524	37	331
	

Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.

*/

#include <iostream>
#include <fstream>
#include "dijkstraGraph.h"
using namespace std ;

void TwoWays()
{
	int const ZEILEN = 80 ;
	int const SPALTEN = 80 ;


	ifstream fin( "matrix1.txt" ) ;

	// Matrix, in der die Koeffizienten gespeichert werden
	int** koeffizientenmatrix = new int*[ ZEILEN ] ;
	for ( int i = 0 ;  i < SPALTEN ;  ++i )
		koeffizientenmatrix[ i ] = new int[ SPALTEN ] ;

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			fin >> koeffizientenmatrix[ i ][ j ] ;

			if ( j != SPALTEN - 1 )
			{
				// Kommata "einlesen", um in der nächsten Iteration wieder einen int lesen zu können
				char c ;
				fin >> c ;
			}
		}

	fin.close() ;


	// Graph erzeugen
	dijkstraGraph graph( ZEILEN * SPALTEN, 0 ) ;
	graph.getKnoten( 0 ) ->distanz = koeffizientenmatrix[ 0 ][ 0 ] ;

	// Kanten nach rechts
	for ( int i = 0 ;  i < ZEILEN ;  ++i )
		for ( int j = 0 ;  j < SPALTEN - 1 ;  ++j )
			graph.neueKante( j + i * SPALTEN, j + i * SPALTEN + 1, koeffizientenmatrix[ i ][ j + 1 ] ) ;

	//// Kanten nach unten
	for ( int i = 0 ;  i < ZEILEN - 1 ;  ++i )
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
				graph.neueKante( j + i * SPALTEN, j + ( i + 1 ) * SPALTEN, koeffizientenmatrix[ i + 1 ][ j ] ) ;

	graph.startDijkstra() ;
	cout << graph.getKnoten( ZEILEN * SPALTEN - 1 ) ->distanz << endl ;
}

void FourWays()
{
	int const ZEILEN = 80 ;
	int const SPALTEN = 80 ;


	ifstream fin( "matrix3.txt" ) ;

	// Matrix, in der die Koeffizienten gespeichert werden
	int** koeffizientenmatrix = new int*[ ZEILEN ] ;
	for ( int i = 0 ;  i < SPALTEN ;  ++i )
		koeffizientenmatrix[ i ] = new int[ SPALTEN ] ;

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			fin >> koeffizientenmatrix[ i ][ j ] ;

			if ( j != SPALTEN - 1 )
			{
				// Kommata "einlesen", um in der nächsten Iteration wieder einen int lesen zu können
				char c ;
				fin >> c ;
			}
		}

	fin.close() ;


	// Graph erzeugen
	dijkstraGraph graph( ZEILEN * SPALTEN, 0 ) ;
	graph.getKnoten( 0 ) ->distanz = koeffizientenmatrix[ 0 ][ 0 ] ;

	// Kanten nach rechts
	for ( int i = 0 ;  i < ZEILEN ;  ++i )
		for ( int j = 0 ;  j < SPALTEN - 1 ;  ++j )
		{
			graph.neueKante( j + i * SPALTEN, j + i * SPALTEN + 1, koeffizientenmatrix[ i ][ j + 1 ] ) ;
			graph.neueKante( j + i * SPALTEN + 1, j + i * SPALTEN, koeffizientenmatrix[ i ][ j + 1 ] ) ;
		}

	// Kanten nach unten
	for ( int i = 0 ;  i < ZEILEN - 1 ;  ++i )
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			graph.neueKante( j + i * SPALTEN, j + ( i + 1 ) * SPALTEN, koeffizientenmatrix[ i + 1 ][ j ] ) ;
			graph.neueKante( j + ( i + 1 ) * SPALTEN, j + i * SPALTEN, koeffizientenmatrix[ i + 1 ][ j ] ) ;
		}

	graph.getKnoten( 80 ) ->info() ;
}

int main ()
{
	FourWays() ;
	return 0 ;
}