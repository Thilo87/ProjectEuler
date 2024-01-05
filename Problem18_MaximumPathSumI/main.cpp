/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

*/

#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
using namespace std ;

int main ()
{
	ifstream fin( "dreieck.txt" ) ;

	if ( !fin )
	{
		cerr << "Fehler!" << endl ;
		return - 1 ;
	}

	int const ZEILEN = 15 ;
	int const SPALTEN = 15 ;

	// Matrix mit dem Format ( ZEILEN, SPALTEN ) allozieren, vollständig mit 0 initialisieren und dann mit Daten
	// aus der Datei füllen
	double** dreieck = new double*[ ZEILEN ] ;
	double** suchdreieck = new double*[ ZEILEN ] ;
	for ( int i = 0 ;  i < ZEILEN ;  ++i )
	{
		dreieck[ i ] = new double[ SPALTEN ] ;
		suchdreieck[ i ] = new double[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			dreieck[ i ][ j ] = 0 ;
			suchdreieck[ i ][ j ] = 0 ;
		}

		// Matrix mit Daten füllen
		for ( int j = 0 ;  j < i + 1 ;  ++j )
		{
			fin >> dreieck[ i ][ j ] ;
			suchdreieck[ i ][ j ] = 100 - dreieck[ i ][ j ] ;
		}
	}

	fin.close() ;

	int pfadsumme = dreieck[ 0 ][ 0 ] ;

	int positionZeile = 0 ;
	int positionSpalte = 0 ;


	// Dijkstra-Algorithmus:
	// Wiederhole, bis alle Knoten besucht sind:
	// - setze den unbesuchten Knoten mit der geringsten Distanz als aktuell und besucht
	// - für alle unbesuchten Nachbarn: addiere eigene Distanz und das Kantengewicht
	//		- wenn ihre Summe geringer ist als deren aktuelle Distanz,
	//		- dann setze sie
	//		- und setze dich als ihren Vorgänger


	// Vorgänger-Matrix für alle Knoten
	vector< int >** vorgaenger = new vector< int >*[ ZEILEN ] ;

	// Distanz-Matrix für alle Knoten
	double** distanz = new double*[ ZEILEN ] ;

	// Besucht-Matrix für alle Knoten
	bool** besucht = new bool*[ ZEILEN ] ;

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
	{
		vorgaenger[ i ] = new vector< int >[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			vorgaenger[ i ][ j ].push_back( -1 ) ;
			vorgaenger[ i ][ j ].push_back( -1 ) ;
		}

		distanz[ i ] = new double[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
			distanz[ i ][ j ] = INT_MAX ;

		besucht[ i ] = new bool[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
			besucht[ i ][ j ] = false ;
	}


	// Startknoten als den Knoten mit der geringsten Distanz markieren und sich selbst als Vorgänger setzen
	distanz[ 0 ][ 0 ] = 0 ;
	vorgaenger[ 0 ][ 0 ].at( 0 ) = 0 ;
	vorgaenger[ 0 ][ 0 ].at( 1 ) = 0 ;

	// suche Knoten mit geringster Distanz
	int akZeile = 0 ;
	int akSpalte = 0 ;
	double kleinsteDistanz = distanz[ 0 ][ 0 ] ;

	for ( int k = 0 ;   k < 200 ;  ++k )
	{
		kleinsteDistanz = INT_MAX ;

		for ( int i = 0 ;  i < ZEILEN ;  ++i )
			for ( int j = 0 ;  j < SPALTEN ;  ++j )
				if ( distanz[ i ][ j ] < kleinsteDistanz && besucht[ i ][ j ] == false )
				{
					kleinsteDistanz = distanz[ i ][ j ] ;
					akZeile = i ;
					akSpalte = j ;
				}

		// setze Knoten als besucht
		besucht[ akZeile ][ akSpalte ] = true ;

		if ( akZeile != ZEILEN - 1 )
		{
			if ( !besucht[ akZeile + 1 ][ akSpalte ] )
				if ( distanz[ akZeile ][ akSpalte ] + suchdreieck[ akZeile + 1 ][ akSpalte ] < distanz[ akZeile + 1 ][ akSpalte ] )
				{
					distanz[ akZeile + 1 ][ akSpalte ] = distanz[ akZeile ][ akSpalte ] + suchdreieck[ akZeile + 1 ][ akSpalte ] ;
					vorgaenger[ akZeile + 1 ][ akSpalte ].at( 0 ) = akZeile ;
					vorgaenger[ akZeile + 1 ][ akSpalte ].at( 1 ) = akSpalte ;
				}

			if ( !besucht[ akZeile + 1 ][ akSpalte + 1 ] )
				if ( distanz[ akZeile ][ akSpalte ] + suchdreieck[ akZeile + 1 ][ akSpalte + 1 ] < distanz[ akZeile + 1 ][ akSpalte + 1 ] )
				{
					distanz[ akZeile + 1 ][ akSpalte + 1 ] = distanz[ akZeile ][ akSpalte ] + suchdreieck[ akZeile + 1 ][ akSpalte + 1 ] ;
					vorgaenger[ akZeile + 1 ][ akSpalte + 1 ].at( 0 ) = akZeile ;
					vorgaenger[ akZeile + 1 ][ akSpalte + 1 ].at( 1 ) = akSpalte ;
				}
		}
	}

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
	{
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			if ( distanz[ i ][ j ] != INT_MAX )
				cout << distanz[ i ][ j ] << " " ;
			else
				cout << "inf" << " " ;
		}
		cout << endl ;
	}

	int maxWert = distanz[ ZEILEN - 1 ][ 0 ] ;
	int maxZ = ZEILEN - 1 ;
	int maxS = 0 ;
	for ( int i = 0 ;  i < SPALTEN ;  ++i )
		if ( distanz[ ZEILEN - 1 ][ i ] < maxWert )
		{
			maxWert = distanz[ ZEILEN - 1 ][ i ] ;
			maxS = i ;
		}

	
	int summe = 0 ;

	int aktZ = ZEILEN - 1 ;
	int aktS = maxS ;
	while ( aktZ + aktS != -1 )
	{
		summe += dreieck[ aktZ ][ aktS ] ;
		aktS = vorgaenger[ aktZ ][ aktS ].at( 1 );
		--aktZ ;
	}

	cout << summe << endl ;
	return 0 ;


}