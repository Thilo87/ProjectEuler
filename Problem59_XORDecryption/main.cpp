#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std ;

template< typename T >
T XOR( T x, T y )
{
	return x ^ y ;
}

string entschluesseln( string text, string schluessel )
{
	string entschluesselterText ;
	for ( int i = 0 ;  i < text.size() ;  ++i )
		entschluesselterText.push_back( char( XOR( int( text.at( i ) ), int( schluessel.at( i % schluessel.size() ) ) ) ) ) ;

	return entschluesselterText ;
}

string verschluesseln( string text, string schluessel )
{
	string verschluesselterText ;
	for ( int i = 0 ;  i < text.size() ;  ++i )
		verschluesselterText.push_back( int( XOR( int( text.at( i ) ), int( schluessel.at( i % schluessel.size() ) ) ) ) ) ;

	return verschluesselterText ;
}

int main ()
{
	string text ;
	ifstream fin( "cypher1.txt" ) ;

	int n ;
	while ( fin >> n )
	{
		text.push_back( char( n ) ) ;

		char c ;
		fin >> c ; // Komma einlesen
	}

	fin.close() ;

	
	string entschluesselt ;
	bool abbruch = false ;
	for ( int i = 'a' ;  i <= 'z' && !abbruch ;  ++i )
		for ( int j = 'a' ;  j <= 'z' && !abbruch ;  ++j )
			for ( int k = 'a' ;  k <= 'z' && !abbruch ;  ++k )
			{
				string schluessel ;
				schluessel.push_back( char( i ) ) ;
				schluessel.push_back( char( j ) ) ;
				schluessel.push_back( char( k ) ) ;

				entschluesselt = entschluesseln( text, schluessel ) ;
				if ( entschluesselt.find( "the" ) != string::npos &&
					 entschluesselt.find( "to" ) != string::npos &&
					 entschluesselt.find( "and" ) != string::npos &&
					 entschluesselt.find( "that" ) != string::npos )
				{
					abbruch = true ;
				}
			}

	cout << entschluesselt << endl << endl ;

	int summe = 0 ;
	for ( int i = 0 ;  i < entschluesselt.size() ;  ++i )
		summe += int( entschluesselt.at( i ) ) ;

	cout << summe << endl ;

	return 0 ;
}