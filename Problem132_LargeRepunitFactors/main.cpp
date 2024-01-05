//*
//
//A number consisting entirely of ones is called a repunit. We shall define R(k) to be a repunit of length k.
//
//For example, R(10) = 1111111111 = 11×41×271×9091, and the sum of these prime factors is 9414.
//
//Find the sum of the first forty prime factors of R(109).
//
//*/
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <iomanip>
//#include <ttmath\ttmath.h>
//#include <tuple>
//#include <algorithm>
//#include <string>
//#include "primzahlen.h"
//using namespace std ;
//
//typedef unsigned long long uint64 ;
//typedef ttmath::Int< 4000 > bInt ;
//
//// gibt die Primfaktoren von n zurück
//vector< pair< int, int > > primfaktoren( bInt n, vector< int > const& primzahlen )
//{
//	// Primfaktoren berechnen
//	vector< pair< int, int > > primfaktoren ;
//
//	int p = 0 ;
//	for ( ;  n > 1 ;  ++p )
//	{
//		if ( p >= 100000 )
//			return primfaktoren ;
//
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
//
//
//bInt repunitZahl( unsigned int n )
//{
//	bInt z = 0 ;
//	bInt zehn = 1 ;
//	for ( int i = 0 ;  i < n ;  ++i )
//	{
//		z += zehn ;
//		zehn *= 10 ;
//	}
//
//	return z ;
//}
//
//
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
//
//
//	int const MAX_PRIMZAHL = 1000000000 ;
//	vector< int > primzahlen = primzahlliste( MAX_PRIMZAHL ) ;
//	
//
//	// enthält tuple< n, bekannte Primfaktoren, unbekannter Rest >
//	typedef tuple< uint64, vector< uint64 >, uint64 > RTabEintr ;
//
//	vector<  RTabEintr  > RTabelle ;
//	for ( int i = 0 ;  i < T10e9.size() ;  ++i )
//		RTabelle.push_back( RTabEintr( T10e9.at( i ), vector< uint64 >( 0 ),  0 ) ) ;
//
//
//
//	for ( int i = 1 ;  i < 85 ;  ++i )
//	{
//		cout << i << endl ;
//		uint64 R = get< 0 >( RTabelle.at( i ) ) ;
//		vector< uint64 > p = get< 1 >( RTabelle.at( i ) ) ;
//		bInt rest = get< 2 >( RTabelle.at( i ) ) ;
//		if ( rest == 0 )
//		{
//			rest = repunitZahl( R ) ;
//			for ( int j = 0 ;  j < p.size() ;  ++j )
//				rest /= p.at( j ) ;
//		}
//
//		//if ( rest > MAX_PRIMZAHL * 2 || rest < 0 )
//		//	continue ;
//
//		//cout << rest << endl ;
//
//		// Primfaktoren der restlichen Repunit-Zahl zur Tabelle hinzufügen
//		vector< pair< int, int > > pf = primfaktoren( rest, primzahlen ) ;
//
//
//		for ( int j = 0 ;  j < pf.size() ;  ++j )
//			get< 1 >( RTabelle.at( i ) ).push_back( pf.at( j ).first ) ;
//
//		for ( int j = i + 1 ;  j < RTabelle.size() ;  ++j )
//			if ( get< 0 >( RTabelle.at( j ) ) % R == 0 )
//				for ( int k = 0 ;  k < pf.size() ;  ++k )
//					get< 1 >( RTabelle.at( j ) ).push_back( pf.at( k ).first ) ; 
//
//		get< 2 >( RTabelle.at( i ) ) = 1 ;
//		
//		
//	}
//
//	sort( get< 1 >( RTabelle.at( RTabelle.size() - 1 ) ).begin(), get< 1 >( RTabelle.at( RTabelle.size() - 1 ) ).end() ) ;
//	
//	int summe = 0 ;
//	for ( int i = 0 ;  i < get< 1 >( RTabelle.at( RTabelle.size() - 1 ) ).size() ;  ++i )
//	{
//		if ( i <= 39 )
//			summe += get< 1 >( RTabelle.at( RTabelle.size() - 1 ) ).at( i ) ;
//		cout << get< 1 >( RTabelle.at( RTabelle.size() - 1 ) ).at( i ) << endl ;
//	}
//
//	cout << endl << endl ;
//	cout << summe ;
//	//cout << left ;
//	//for ( int i = 1 ;  i < RTabelle.size() ;  ++i )
//	//{
//	//	cout << "R(" << get< 0 >( RTabelle.at( i ) ) << ")" << "\t" ;
//	//	for ( int j = 0 ;  j < get< 1 >( RTabelle.at( i ) ).size() ;  ++j )
//	//		cout << get< 1 >( RTabelle.at( i ) ).at( j ) << ", " ;
//	//	cout << endl ;
//	//}
//
//
//	
//
//
//	return 0 ;
//}