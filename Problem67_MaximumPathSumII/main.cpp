/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route
to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes
every second it would take over twenty billion years to check them all.
There is an efficient algorithm to solve it. ;o)

*/

#include <iostream>
#include <climits>
#include <fstream>
using namespace std ;

	// Dijkstra-Algorithmus:
	// Wiederhole, bis alle Knoten besucht sind:
	// - setze den unbesuchten Knoten mit der geringsten Distanz als aktuell und besucht
	// - für alle unbesuchten Nachbarn: addiere eigene Distanz und das Kantengewicht
	//		- wenn ihre Summe geringer ist als deren aktuelle Distanz,
	//		- dann setze sie
	//		- und setze dich als ihren Vorgänger

// sucht den unbesuchten Knoten mit geringster Distanz
int* knotenGeringsterDistanz( double** distanzmatrix, bool** besuchtmatrix, int const ZEILEN, int const SPALTEN )
{
	double geringsteDistanz = DBL_MAX ;

	int* knoten = new int[ 2 ] ;
	knoten[ 0 ] = 0 ;
	knoten[ 1 ] = 0 ;

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
			if ( besuchtmatrix[ i ][ j ] == false )
				if ( distanzmatrix[ i ][ j ] < geringsteDistanz )
				{
					geringsteDistanz = distanzmatrix[ i ][ j ] ;
					knoten[ 0 ] = i ;
					knoten[ 1 ] = j ;
				}

	return knoten ;
}

int main ()
{
	ifstream fin( "dreieck.txt" ) ;

	if ( !fin )
	{
		cerr << "Fehler!" << endl ;
		return - 1 ;
	}

	int const ZEILEN = 100 ;
	int const SPALTEN = 100 ;

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


	// Distanz-, Besucht-, Vorgaengermatrix allozieren
	double** distanz = new double*[ ZEILEN ] ;
	bool** besucht = new bool*[ ZEILEN ] ;
	int*** vorgaenger = new int**[ ZEILEN ] ; // dreidimensionales Array: vorgaenger[ zeile ][ spalte ][ 0 oder 1 ]
											  // enthält den Vorgänger des Knotens aus zeile, spalte, wobei
											  // 0 für die Zeile des Vorgängers und 1 für die Spalte des Vorgängers steht

	for ( int i = 0 ;  i < ZEILEN ;  ++i )
	{
		distanz[ i ] = new double[ SPALTEN ] ;
		besucht[ i ] = new bool[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			distanz[ i ][ j ] = DBL_MAX
				;
			besucht[ i ][ j ] = false ;
		}

		vorgaenger[ i ] = new int*[ SPALTEN ] ;
		for ( int j = 0 ;  j < SPALTEN ;  ++j )
		{
			vorgaenger[ i ][ j ] = new int[ 2 ] ;
			for ( int k = 0 ;  k < 2 ;  ++k )
				vorgaenger[ i ][ j ][ k ] = -1 ; // Vorgänger noch nicht gesetzt, daher -1
		}
	}

	// Startknoten aktuell setzen
	distanz[ 0 ][ 0 ] = 0 ;
	vorgaenger[ 0 ][ 0 ][ 0 ] = 0 ;
	vorgaenger[ 0 ][ 0 ][ 1 ] = 0 ;


	for ( int k = 0 ;  k < 20000 ;  ++k )
	{
		// unbesuchten Knoten mit geringster Distanz suchen
		int* aktuellerKnoten = knotenGeringsterDistanz( distanz, besucht, ZEILEN, SPALTEN ) ;

		// Knoten als besucht markieren
		besucht[ aktuellerKnoten[ 0 ] ][ aktuellerKnoten[ 1 ] ] = true ;
		
		// - für alle unbesuchten Nachbarn: addiere eigene Distanz und das Kantengewicht
		//		- wenn ihre Summe geringer ist als deren aktuelle Distanz,
		//		- dann setze sie
		//		- und setze dich als ihren Vorgänger
		
		if ( aktuellerKnoten[ 0 ] != ZEILEN - 1 ) // die letzte Zeile hat keine benachbarten Knoten mehr
		{
			
			double eigeneDistanz = distanz[ aktuellerKnoten[ 0 ] ][ aktuellerKnoten[ 1 ] ] ;

			int nachbar1[] = { aktuellerKnoten[ 0 ] + 1, aktuellerKnoten[ 1 ] } ;
			double nachbar1Distanz = distanz[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ] ;
			double nachbar1Kantengewicht = suchdreieck[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ] ;

			int nachbar2[] = { aktuellerKnoten[ 0 ] + 1, aktuellerKnoten[ 1 ] + 1 } ;
			double nachbar2Distanz = distanz[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ] ;
			double nachbar2Kantengewicht = suchdreieck[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ] ;

			
			

			if ( !besucht[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ] )
				if ( eigeneDistanz + nachbar1Kantengewicht < nachbar1Distanz )
				{
					distanz[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ] = eigeneDistanz + nachbar1Kantengewicht ;
					vorgaenger[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ][ 0 ] = aktuellerKnoten[ 0 ] ;
					vorgaenger[ nachbar1[ 0 ] ][ nachbar1[ 1 ] ][ 1 ] = aktuellerKnoten[ 1 ] ;
				}
				

			if ( aktuellerKnoten[ 1 ] != SPALTEN - 1 )
				if ( !besucht[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ] )
					if ( eigeneDistanz + nachbar2Kantengewicht < nachbar2Distanz )
					{
						distanz[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ] = eigeneDistanz + nachbar2Kantengewicht ;
						vorgaenger[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ][ 0 ] = aktuellerKnoten[ 0 ] ;
						vorgaenger[ nachbar2[ 0 ] ][ nachbar2[ 1 ] ][ 1 ] = aktuellerKnoten[ 1 ] ;
					}
		}
		
		delete[] aktuellerKnoten ;
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
		aktS = vorgaenger[ aktZ ][ aktS ][ 1 ] ;
		--aktZ ;
	}

	cout << summe << endl ;

	return 0 ;
}