///*
//
//The primes 3, 7, 109, and 673, are quite remarkable. By taking any two
//primes and concatenating them in any order the result will always be prime.
//For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of
//these four primes, 792, represents the lowest sum for a set of four primes with this property.
//
//Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
//
//*/
//
//#include <iostream>
//#include "primzahlen.h"
//#include <stdlib.h>
//#include <time.h>
//#include <string>
//#include <ttmath\ttmath.h>
//#include <vector>
//#include <set>
//using namespace std ;
//
//unsigned long long string_zu_ULL( string const& zahl )
//{
//	unsigned long long z = 0 ;
//	for ( int i = 0 ;  i < zahl.size() ;  ++i )
//		z += ( zahl.at( i ) - '0' ) * int( pow( 10., double( zahl.size() - i - 1 ) ) ) ;
//	return z ;
//}
//
//bool suche( vector< int > const& v, int n )
//{
//	for ( int i = 0 ;  i < v.size() ;  ++i )
//		if ( v.at( i ) == n )
//			return true ;
//
//	return false ;
//}
//
//unsigned long long verbinde( unsigned long long p1_links, unsigned long long p2_rechts )
//{
//
//}
//
//int main ()
//{
//	int const MAX_N = 10000000 ;
//
//	bool* istPrim = new bool[ MAX_N + 1 ] ; // istPrim[ i ] zur Abfrage, ob i eine Primzahl ist
//	vector< int > iPrimzahlen ;				// iPrimzahlen.at( i ), um die i-te Primzahl als int zu haben
//	vector< string > sPrimzahlen ;			// sPrimzahlen.at( i ).at( j ) um die j-te Ziffer der i-ten Primzahl
//											// abzurufen
//
//
//
//
//	/**** Primzahlen bis MAX_N ermitteln ( mit dem Sieb des Eratosthenes ) ****/
//
//	// alle Zahlen von 0 bis n sind potenzielle Primzahlen
//	for ( unsigned int i = 0 ;  i < MAX_N + 1 ;  ++i )
//		istPrim[ i ] = true ;
//
//	// 1 und 0 sind per Definition keine Primzahlen
//	istPrim[ 0 ] = false ;
//	istPrim[ 1 ] = false ;
//
//	// gehe alle Zahlen von 2 bis inklusive sqrt( n + 1 ) durch, ob sie als prim markiert sind
//	for ( int i = 2 ;  i <= sqrt( double( MAX_N + 1 ) ) ;  ++i )
//	{
//		if ( istPrim[ i ] )
//			// markiere alle Vielfachen von der Primzahl i, beginnend mit i^2, als nicht prim
//			for ( unsigned int j = i * i ;  j < MAX_N + 1 ;  j += i )
//				istPrim[ j ] = false ;
//	}
//
//
//	for ( unsigned int i = 2 ;  i <= MAX_N ;  ++i )
//		if ( istPrim[ i ] )
//		{
//			iPrimzahlen.push_back( i ) ;
//
//			int nPz = int( log10( double( i ) ) ) + 2 ;
//			char* pz = new char[ nPz ] ;
//
//			int i_kpi = i ;
//			for ( int j = 0 ;  i_kpi > 0 ;  ++j )
//			{
//				pz[ nPz - j - 2 ] = ( i_kpi % 10 ) + '0' ;
//				i_kpi /= 10 ;
//			}
//
//			pz[ nPz - 1 ] = '\0' ;
//			sPrimzahlen.push_back( pz ) ;
//
//			delete[] pz ;
//		}
//
//	for ( int i = 0 ;  i < sPrimzahlen.size() ;  ++i )
//		for ( int j = i + 1 ;  i < sPrimzahlen.size() ;  ++j )
//		{
//
//		}
//
//
//	//vector< vector< int > > istLinksVon ;
//	//for ( int i = 0 ;  i < MAX_N ;  ++i )
//	//{
//	//	vector< int > tmp ;
//	//	istLinksVon.push_back( tmp ) ;
//	//}
//
//	//for ( int j = 1 ;  j < sPrimzahlen.size() ;  ++j )
//	//{
//	//	string sAktPrimzahl = sPrimzahlen.at( j ) ;
//	//
//	//	for ( int i = 1 ;  i < sAktPrimzahl.size() ;  ++i )
//	//	{
//	//		unsigned long long ullLinks = string_zu_ULL( sAktPrimzahl.substr( 0, i ) ) ;
//	//		unsigned long long ullRechts = string_zu_ULL( sAktPrimzahl.substr( i, sAktPrimzahl.size() - i ) ) ;
//
//	//		if ( istPrim[ ullLinks ] && istPrim[ ullRechts ] )
//	//		{
//	//			istLinksVon.at( ullLinks ).push_back( ullRechts ) ;
//
//	//			if ( suche( istLinksVon.at( ullRechts ) , ullLinks ) )
//	//			{
//	//				true ; 
//	//			}
//	//			//	cout << ullLinks << " " << ullRechts << endl ;
//	//			//raute.at( ullLinks ) = raute.at( ullLinks ) * ullRechts ;
//	//			//raute.at( ullRechts ) = raute.at( ullRechts ) * ullLinks ;
//	//		}
//	//		
//	//	}
//	}
//
//
//	return 0 ;
//}