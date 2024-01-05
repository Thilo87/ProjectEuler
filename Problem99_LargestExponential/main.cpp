#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std ;

// -1 : a^x < b^y
//  0 : a^x = b^y
//  1 : a^x > b^y
int vergleiche( unsigned long long a, unsigned long long x, unsigned long long b, unsigned long long y )
{
	double const EPSILON = 1e-10 ;

	if ( x == y )
		if ( a < b )
			return -1 ;
		else if ( a > b )
			return 1 ;
		else if ( a == b )
			return 0 ;

	if ( x > y )
		if ( a > b )
			return 1 ;
		else if ( a == b )
			return 1 ;
		else
		{
			double lgq = log( double( b ) ) / log( double( a ) ) ;
			double qu = x / double( y ) ;

			if ( abs( lgq - qu ) < EPSILON )
				return 0 ;
			else if ( lgq > qu )
				return -1 ;
			else if ( lgq < qu )
				return 1 ;
		}

	if ( x < y )
		if ( a < b )
			return -1 ;
		else if ( a == b )
			return -1 ;
		else
		{
			double lgq = log( double( b ) ) / log( double( a ) ) ;
			double qu = x / double( y ) ;

			if ( abs( lgq - qu ) < EPSILON )
				return 0 ;
			else if ( lgq > qu )
				return -1 ;
			else if ( lgq < qu )
				return 1 ;
		}
}

int main ()
{
	vector< int > basis ;
	vector< int > exponent ;

	fstream fin( "zahlen.txt" ) ;
		for ( int i = 0 ;  i < 1000 ;  ++i )
		{
			int b ;
			fin >> b ;

			char c ;
			fin >> c ;

			int e ;
			fin >> e ;

			basis.push_back( b ) ;
			exponent.push_back( e ) ;
		}

	fin.close() ;

	
	// größte Zahl finden
	int linienzahl = 0 ;
	unsigned long long groessteBasis = basis.at( 0 ) ;
	unsigned long long groessterExponent = exponent.at( 0 ) ;

	for ( int i = 0 ;  i < basis.size() ;  ++i )
		if ( vergleiche( groessteBasis, groessterExponent, basis.at( i ), exponent.at( i ) ) == -1 )
		{
			linienzahl = i ;
			groessteBasis = basis.at( i ) ;
			groessterExponent = exponent.at( i ) ;
		}

	cout << linienzahl + 1 << endl ;

	cout << vergleiche( 632382, 518061, 519432, 525806 ) << endl ;
	return 0 ;
}