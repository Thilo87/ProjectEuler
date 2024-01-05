//#include <iostream>
//#include "primzahlen.h"
//#include "string_math.h"
//#include <fstream>
//#include <vector>
//#include <set>
//using namespace std ;
//
//typedef unsigned long long uint64 ;
//
//// gibt die Repunit R( n ) zurück
//string repunitZahl( uint64 n )
//{
//	return string( n, '1' ) ;
//}
//
//// gibt die Primfaktoren von n zurück. Waren nicht genug Primzahlen in dem Vector vorhanden,
//// verbleibt der unfaktorisierte Rest bei n
//vector< pair< int, int > > faktorisieren( string n, vector< int > const& primzahlen )
//{
//	string const EINS = "1" ;
//
//	// Primfaktoren berechnen
//	vector< pair< int, int > > primfaktoren ;
//
//	int p = 0 ;
//	for ( ;  n > EINS && p < primzahlen.size() ;  ++p )
//	{
//		string p_str = to_string( uint64( primzahlen.at( p ) ) ) ;
//		pair< string, string > div_p = div( n, p_str ) ;
//
//		if ( div_p.second == "0" )
//			primfaktoren.push_back( pair< int, int >( primzahlen.at( p ), 0 ) ) ;
//		
//
//		//while ( div( n, p_str ).second == "0" ) // n % p == 0
//		//{
//		//	n = div( n, p_str ).first ;
//		//	++primfaktoren.at( primfaktoren.size() - 1 ).second ;
//		//}
//	}
//
//	return primfaktoren ;
//}
//
//int main ()
//{
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
//	for ( int i = 1 ;  i < T10e9.size() ;  ++i )
//	{
//		if ( istPrim_MRD( T10e9.at( i ) + 1 ) )
//			cout << T10e9.at( i ) + 1 << endl ;
//	}
//
//	//const int MAX_PRIMZAHL = 10000 ;
//	//const int MAX_TEILER = 60 ;
//
//
//	//
//	//// Liste mit Primzahlen
//	//vector< int > primzahlen = primzahlliste( MAX_PRIMZAHL ) ;
//
//	//// vector.at( R_n ).first: bekannte Primfaktoren von R_n
//	//// vector.at( R_n ).second: unfaktorisierter Rest von R_n
//	//vector< pair< vector< int >, string > > tabelle ;
//
//	//// Tabelle mit den Repunits der Teiler von 10^9 füllen
//	//for ( int i = 1 ;  i <= MAX_TEILER ;  ++i )
//	//{
//	//	pair< vector< int >, string > R_n( vector< int >( 0 ), repunitZahl( T10e9.at( i ) ) ) ;
//	//	tabelle.push_back( R_n ) ;
//	//}
//
//	//// Primfaktoren von 10^9
//	//set< int > T10e9_primfaktoren ;
//
//	//for ( int i = 0 ;  i < MAX_TEILER ;  ++i )
//	//{
//	//	int R_n = T10e9.at( i + 1 ) ;
//	//	cout << R_n << endl ;
//
//	//	vector< pair< int, int > > primfaktoren = faktorisieren( tabelle.at( i ).second, primzahlen ) ;
//	//	
//	//	for ( int j = i + 2 ;  j < tabelle.size() ;  ++j )
//	//		if ( T10e9.at( j ) % R_n == 0 )
//	//		{
//	//			for ( int k = 0 ;  k < primfaktoren.size() ;  ++k )
//	//			{
//	//				//tabelle.at( j - 1 ).second = div( tabelle.at( j - 1 ).second, to_string( uint64( primfaktoren.at( k ).first ) ) ).first ;
//	//				tabelle.at( j - 1 ).first.push_back( primfaktoren.at( k ).first ) ;
//	//				T10e9_primfaktoren.insert( primfaktoren.at( k ).first ) ;
//	//			}
//
//	//			ofstream fout( "primfaktoren4.txt" ) ;
//	//			for ( set< int >::iterator it = T10e9_primfaktoren.begin() ;  it != T10e9_primfaktoren.end() ;  ++it )
//	//			{
//	//				fout << (*it) << endl ;
//	//			}
//	//			fout.close() ;
//	//		}
//	//}
//	//
//	//cout << endl << "Primfaktoren: " << endl ;
//	//// Ausgabe des Ergebnisses
//	//int i = 0 ;
//	//uint64 summe = 0 ;
//	//for ( set< int >::iterator it = T10e9_primfaktoren.begin() ;  it != T10e9_primfaktoren.end() ;  ++it, ++i )
//	//{
//	//	if ( i <= 39 )
//	//		summe += (*it ) ;
//
//	//	cout << (*it) << endl ;
//	//}
//
//	//cout << endl << summe << endl ;
//
//	return 0 ;
//}