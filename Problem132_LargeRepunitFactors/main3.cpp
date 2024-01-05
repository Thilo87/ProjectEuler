//#include <iostream>
//#include <ttmath\ttmath.h>
//#include <vector>
//#include <fstream>
//#include "primzahlen.h"
//#include <set>
//using namespace std ;
//
//typedef unsigned long long uint64 ;
//typedef ttmath::Int< 10000 > bInt ;
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
//int main ()
//{
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
//	set< int > primfaktoren_10e9 ;
//
//	vector< int > primzahlen = primzahlliste( 1000 ) ;
//	for ( int i = 1 ;  i < 60 ;  ++i )
//	{
//		vector< pair< int, int > > primf = faktorisieren( repunitZahl( T10e9.at( i ) ), primzahlen ) ;
//		for ( int j = 0 ;  j < primf.size() ;  ++j )
//			primfaktoren_10e9.insert( primf.at( j ).first ) ;
//	}
//
//	for ( set< int >::iterator it = primfaktoren_10e9.begin() ;  it != primfaktoren_10e9.end() ;  ++it )
//		cout << (*it) << endl ;
//
//	return 0 ;
//}