#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

// ist es erlaubt, die Zahl n auf das Feld ( x, y ) zu setzen
bool erlaubt( int n, int x, int y, int** sudoku )
{
	if ( sudoku[ y ][ x ] != 0 )
		return false ;

	// überprüfe von links nach rechts
	for ( int j = 0 ;  j < 9 ;  ++j )
		if ( sudoku[ y ][ j ] == n )
			return false ;

	// überprüfe von oben nach unten
	for ( int i = 0 ;  i < 9 ;  ++i )
		if ( sudoku[ i ][ x ] == n )
			return false ;

	// überprüfe Block
	int blockX = ( x / 3 ) * 3 ;
	int blockY = ( y / 3 ) * 3 ;
	for ( int j = blockX ;  j < blockX + 3 ;  ++j )
		for ( int i = blockY ;  i < blockY + 3 ;  ++i )
			if ( sudoku[ i ][ j ] == n )
				return false ;

	return true ;
}

bool sucheFreiesFeld( int** sudoku, int& x, int& y )
{
	for ( x = 0 ;  x < 9 ;  ++x )
		for ( y = 0 ;  y < 9 ;  ++y )
			if ( sudoku[ y ][ x ] == 0 )
				return true ;

	return false ;
}

bool loeseSudoku( int** sudoku )
{
	int x, y ;

	if ( !sucheFreiesFeld( sudoku, x, y ) )
		return true ;
	
	for ( int n = 1 ;  n <= 9 ;  ++n )
	{
		if ( erlaubt( n, x, y, sudoku ) )
		{
			sudoku[ y ][ x ] = n ;
			if ( loeseSudoku( sudoku ) )
				return true ;

			sudoku[ y ][ x ] = 0 ;
		}
	}

	return false ;
}

int main ()
{
	int pruefsumme = 0 ;

	fstream fin( "sudoku.txt" ) ;

	// Sudoku-Matrix deklarieren
	int** sudoku = new int*[ 9 ] ;
	for ( int i = 0 ;  i < 9 ;  ++i )
		sudoku[ i ] = new int[ 9 ] ;


	for ( int z = 0 ;  z < 50 ;  ++z )
	{
		// Sudoku-Matrix resetten
		for ( int i = 0 ;  i < 9 ;  ++i )
			for ( int j = 0 ;  j < 9 ;  ++j )
				sudoku[ i ][ j ] = 0 ;
	
		// Sudoku einlesen
		string s ;
		getline( fin, s ) ;
		for ( int i = 0 ;  i < 9 ;  ++i )
		{
			getline( fin, s ) ;
			for ( int j = 0 ;  j < 9 ;  ++j )
				sudoku[ i ][ j ] = s.at( j ) - '0' ;
		}

		// Sudoku lösen
		loeseSudoku( sudoku ) ;

		pruefsumme += sudoku[ 0 ][ 0 ] * 100 + sudoku[ 0 ][ 1 ] * 10 + sudoku[ 0 ][ 2 ] ;
	}

	fin.close() ;

	cout << pruefsumme << endl ;

	return 0 ;
}