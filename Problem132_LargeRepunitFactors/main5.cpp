#include "primzahlen.h"
#include "string_math.h"
#include <ttmath\ttmath.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std ;

typedef unsigned long long uint64 ;

// gibt die Repunit R( n ) zurück
string repunitZahl( uint64 n )
{
	return string( n, '1' ) ;
}

int main ()
{
	int const MAX_PRIMZAHL = 1000 ;
	int const MAX_TEILER = 100 ;

	// Teiler von 10^9 einlesen
	vector< int > T10e9 ;
	ifstream fin( "teiler10hoch9.txt" ) ;

	unsigned long long t ;
	while ( fin >> t )
		T10e9.push_back( t ) ;

	fin.close() ;


	// Liste mit Primzahlen
	vector< int > primzahlen = primzahlliste( MAX_PRIMZAHL ) ;

	// vector.at( R_n ).first: bekannte Primfaktoren von R_n
	// vector.at( R_n ).second: unfaktorisierter Rest von R_n
	vector< pair< vector< int >, string > > tabelle ;

	// Tabelle mit den Repunits der Teiler von 10^9 füllen
	for ( int i = 1 ;  i <= MAX_TEILER ;  ++i )
	{
		pair< vector< int >, string > R_n( vector< int >( 0 ), string( "0" ) ) ;
		tabelle.push_back( R_n ) ;
	}

	/*
	// ausnutzen, dass p | R( p - 1 ) für p >= 7, p prim
	// also alle Teiler t von 10^9 durchgehen und sehen, ob t + 1 prim ist, dann gilt t + 1 | R( t )
	for ( int i = 3 ;  i < T10e9.size() ;  ++i )
		if ( istPrim_MRD( T10e9.at( i ) + 1 ) )
			for ( int j = 0 ;  j < T10e9.size() ;  ++j )
				if ( T10e9.at( j ) % T10e9.at( i ) == 0 )
					tabelle.at( j ).first.push_back( T10e9.at( i ) + 1 ) ;
	*/

	set< uint64 > R10e9_Primfaktoren ;

	for ( int i = 1 ;  i < 60 ;  ++i )
	{
		ttmath::Int< 10000 > R_n ;
		R_n.FromString( string( T10e9.at( i ), '1' ) ) ;
		cout << T10e9.at( i ) << ": " ;

		uint64 k = T10e9.at( i ) + 1 ;
		while ( R_n >= k && k < 1000000 )
		{
			if ( istPrim_MRD( k ) )
				if ( R_n % k == 0 )
				{
					cout << k << " " ;
					R10e9_Primfaktoren.insert( k ) ;
					R_n /= k ;
				}

			k += T10e9.at( i ) ;
		}

		cout << endl ;
	}

	//sort( R10e9_Primfaktoren.begin(), R10e9_Primfaktoren.end() ) ;
	cout << "10e9: " ;
	uint64 summe = 0 ;
	int i = 0 ;
	for ( set< uint64 >::iterator it = R10e9_Primfaktoren.begin() ;  it != R10e9_Primfaktoren.end() ;  ++it, ++i )
	{
		if ( i <= 39 )
			summe += (*it) ;
		cout << (*it) << " " ;
	}
	cout << endl ;
	cout << "Erste 40: " << ": " << summe << endl ;
	//uint64 n = 17 ;
	//string s( n, '1' ) ;
	//a.FromString( s ) ;
	//
	//for ( int i = 1 ;  true ;  ++i )
	//	if ( istPrim_MRD( i * n + 1 ) )
	//	{
	//		if ( a % ( i * n + 1 ) == 0 )
	//		{
	//			cout << i * n + 1 << endl ;
	//			break ;
	//		}
	//		//cout << a % ( i * 3125 + 1 ) << endl ;
	//		//break ;
	//	}
	//cout << istPrim_MRD( i * 1000000000LL + 1 ) << endl ;

	//for ( int i = 99 ;  i < tabelle.size() ;  ++i )
	//{
	//	cout << T10e9.at( i ) << " : " ;
	//	for ( int j = 0 ;  j < tabelle.at( i ).first.size() ;  ++j )
	//		cout << tabelle.at( i ).first.at( j ) << ", " ;
	//	cout << endl ;
	//}

	return 0 ;
}