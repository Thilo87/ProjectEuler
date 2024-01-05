//#include <iostream>
//#include <ttmath\ttmath.h>
//#include "primzahlen.h"
//#include <fstream>
//#include <set>
//using namespace std ;
//
//typedef ttmath::Int< 20000 > bInt ;
//typedef unsigned long long uint64 ;
//
//
//
//// gibt die Repunitzahl R( n ) zurück.
//bInt repunitZahl( uint64 n )
//{
//	static uint64 n_alt = 0 ;
//	static bInt zahl = 0 ;
//	static bInt potenz = 1 ;
//
//	if ( signed( n - n_alt ) < 0 )
//	{
//		n_alt = 0 ;
//		zahl = 0 ;
//		potenz = 1 ;
//	}
//
//	for ( int i = 0 ;  i < n - n_alt ;  ++i )
//	{
//		zahl += potenz ;
//		potenz *= 10 ;
//	}
//
//	n_alt = n ;
//
//	return zahl ;
//}
//
//// gibt die Primfaktoren von n zurück. Waren nicht genug Primzahlen in dem Vector vorhanden,
//// verbleibt der unfaktorisierte Rest bei n
//vector< pair< int, int > > faktorisieren( bInt& n, vector< int > const& primzahlen )
//{
//	// Primfaktoren berechnen
//	vector< pair< int, int > > primfaktoren ;
//
//	int p = 0 ;
//	for ( ;  n > 1 && p < primzahlen.size() ;  ++p )
//	{
//		if ( n % primzahlen.at( p ) == 0 )
//			primfaktoren.push_back( pair< int, int >( primzahlen.at( p ), 0 ) ) ;
//
//		while ( n % primzahlen.at( p ) == 0 )
//		{
//			n /= primzahlen.at( p ) ;
//			++primfaktoren.at( primfaktoren.size() - 1 ).second ;
//		}
//	}
//
//	return primfaktoren ;
//}
//
//// dividiert n durch d. Gibt zurück: pair< ganzzahliger Anteil, Rest >
//pair< int, int > dividiere( string n, string d )
//{
//	n = "1111" ;
//	d = "17" ;
//
//	string& obereZahl = ( n.size() > d.size() ) ? n : d ;
//	string& untereZahl = ( n.size() > d.size() ) ? d : n ;
//
//	for ( int j = 0 ;  true ;  ++j )
//	{
//		bool abbrechen = true ;
//		// überprüfen, ob obere Zahl noch größer untere Zahl, sonst abbruch
//		for ( int i = 0 ;  i < obereZahl.size() ;  ++i )
//		{
//			int zoben = obereZahl.at( i ) - '0' ;
//			int zunten = ( i < untereZahl.size() ) ? untereZahl.at( i ) - '0' : 0 ; // !!!
//
//			if ( zoben > zunten )
//			{
//				abbrechen = false ;
//				break ;
//			}
//			else if ( zoben < zunten )
//				break ;
//		}
//
//		if ( abbrechen )
//			break ;
//
//		int uebertrag = 0 ;
//		for ( int i = 0 ;  i < obereZahl.size() ;  ++i )
//		{
//			int zoben = obereZahl.at( obereZahl.size() - i - 1 ) - '0' ;
//			int zunten = ( signed( untereZahl.size() - i - 1 ) >= 0 ) ? untereZahl.at( untereZahl.size() - i - 1 ) - '0' : 0 ;
//			zunten += uebertrag ;
//
//			uebertrag = 0 ;
//
//			int zerg ;
//			if ( zoben < zunten )
//			{
//				zoben += 10 ;
//				zerg = zoben - zunten ;
//				uebertrag = 1 ;
//			}
//			else
//				zerg = zoben - zunten ;
//
//			obereZahl.at( obereZahl.size() - i - 1 ) = zerg + '0' ;
//		}
//
//		cout << obereZahl << endl ;
//	}
//	
//	return pair< int, int >( 0, 0 ) ;
//}
//
//int main ()
//{
//	dividiere( "", "" ) ;
//
//	const int MAX_PRIMZAHL = 1000 ;
//	const int MAX_TEILER = 0 ;
//
//	// Teiler von 10^9 einlesen
//	vector< int > T10e9 ;
//	ifstream fin( "teiler10hoch9.txt" ) ;
//
//	unsigned long long t ;
//	while ( fin >> t )
//		T10e9.push_back( t ) ;
//
//	fin.close() ;
//
//	
//	// Liste mit Primzahlen
//	vector< int > primzahlen = primzahlliste( MAX_PRIMZAHL ) ;
//
//	// vector.at( R_n ).first: bekannte Primfaktoren von R_n
//	// vector.at( R_n ).second: unfaktorisierter Rest von R_n
//	vector< pair< vector< int >, bInt > > tabelle ;
//
//	// Tabelle mit den Repunits der Teiler von 10^9 füllen
//	for ( int i = 1 ;  i <= MAX_TEILER ;  ++i )
//	{
//		pair< vector< int >, bInt > R_n( vector< int >( 0 ), repunitZahl( T10e9.at( i ) ) ) ;
//		tabelle.push_back( R_n ) ;
//	}
//
//	// Primfaktoren von 10^9
//	set< int > T10e9_primfaktoren ;
//
//	for ( int i = 0 ;  i < MAX_TEILER ;  ++i )
//	{
//		int R_n = T10e9.at( i + 1 ) ;
//		
//		vector< pair< int, int > > primfaktoren = faktorisieren( tabelle.at( i ).second, primzahlen ) ;
//		
//		for ( int j = i + 2 ;  j < tabelle.size() ;  ++j )
//			if ( T10e9.at( j ) % R_n == 0 )
//			{
//				for ( int k = 0 ;  k < primfaktoren.size() ;  ++k )
//				{
//					tabelle.at( j - 1 ).second /= primfaktoren.at( k ).first ;
//					tabelle.at( j - 1 ).first.push_back( primfaktoren.at( k ).first ) ;
//					T10e9_primfaktoren.insert( primfaktoren.at( k ).first ) ;
//				}
//			}
//	}
//	
//	// Ausgabe des Ergebnisses
//	int i = 0 ;
//	uint64 summe = 0 ;
//	for ( set< int >::iterator it = T10e9_primfaktoren.begin() ;  it != T10e9_primfaktoren.end() ;  ++it, ++i )
//	{
//		if ( i <= 39 )
//			summe += (*it ) ;
//
//		cout << (*it) << endl ;
//	}
//
//	cout << endl << summe << endl ;
//
//	return 0 ;
//}