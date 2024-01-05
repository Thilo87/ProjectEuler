#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include "kombinatorik.h"
using namespace std ;

vector< string > keys ;

void loescheZiffer( char ziffer )
{
	for ( int i = 0 ;  i < keys.size() ;  ++i )
	{
		int pos = keys.at( i ).find( ziffer ) ;
		while ( pos != string::npos )
		{
			keys.at( i ).erase( pos, 1 ) ;
			pos = keys.at( i ).find( ziffer ) ;
		}
	}
}

char findeLetzteZiffer()
{
	int erstePosition[ 10 ] ;
	for ( int i = 0 ;  i < 10 ;  ++i )
		erstePosition[ i ] = -2 ;

	char letzteZiffer ;

	for ( int i = 0 ;  i < keys.size() ;  ++i )
		for ( int j = 0 ;  j < keys.at( i ).size() ;  ++j )
			if ( erstePosition[ keys.at( i ).at( j ) - '0' ] != -1 )
				if ( erstePosition[ keys.at( i ).at( j ) - '0' ] != -2 && erstePosition[ keys.at( i ).at( j ) - '0' ] != j )
					erstePosition[ keys.at( i ).at( j ) - '0' ] = -1 ;
				else
					erstePosition[ keys.at( i ).at( j ) - '0' ] = j ;

	for ( int i = 0 ;  i < 10 ;  ++i )
	{
		if ( erstePosition[ i ] >= 0 )
		{
			letzteZiffer = i + '0' ;
			
			//cout << letzteZiffer << endl ;
		}
	}

	return letzteZiffer ;
}

int main ()
{
	// Keys einlesen
	ifstream fin( "keylog.txt" ) ;

	string key ;
	while ( fin >> key )
	{
		bool abbruch = false ;
		for ( int i = 0 ;  i < keys.size() ;  ++i )
			if ( keys.at( i ) == key )
			{
				abbruch = true ;
				break ; 
			}

		if ( !abbruch )
			keys.push_back( key ) ;
	}

	//for ( int i = 0 ;  i < keys.size() ;  ++i )
	//	cout << keys.at( i ) << endl ;

	fin.close() ;

	for ( int i = 0 ;  i < 20 ;  ++i )
	{
		char ziffer = findeLetzteZiffer() ;
		cout << ziffer ;
		loescheZiffer( ziffer ) ;
	}

	cout << endl ;

	return 0 ;
}