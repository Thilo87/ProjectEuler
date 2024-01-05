/*

By replacing each of the letters in the word CARE with 1, 2, 9, and 6
respectively, we form a square number: 1296 = 362. What is remarkable
is that, by using the same digital substitutions, the anagram, RACE, 
also forms a square number: 9216 = 962. We shall call CARE (and RACE) 
a square anagram word pair and specify further that leading zeroes are
not permitted, neither may a different letter have the same digital value as another letter.

Using words.txt (right click and 'Save Link/Target As...'), a 16K 
text file containing nearly two-thousand common English words,
find all the square anagram word pairs (a palindromic word is
NOT considered to be an anagram of itself).

What is the largest square number formed by any member of such a pair?

NOTE: All anagrams formed must be contained in the given text file.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
using namespace std ;


int main ()
{
	vector< string > woerter ;

	ifstream fin( "words.txt" ) ;

	char tmp ;
	while ( fin >> tmp ) // erstes " einlesen
	{
		string s ;
		while ( true )
		{
			char c ;
			fin >> c ;

			if ( c != '"' ) // zweites " wird nicht eingelesen
				s.push_back( c ) ;
			else
				break ;
		}

		woerter.push_back( s ) ;

		fin >> tmp ; // , einlesen
	}

	fin.close() ;


	// Anagramm-Paare ermitteln
	vector< pair< string, string > > anagramme ;
	for ( int i = 0 ;  i < woerter.size() ;  ++i )
	{
		int buchstaben1[ 27 ] = { 0 } ;
		for ( int k = 0 ;  k < woerter.at( i ).size() ;  ++k )
			++buchstaben1[ woerter.at( i ).at( k ) - 'A' ] ;

		for ( int j = i + 1 ;  j < woerter.size() ;  ++j )
		{
			int buchstaben2[ 27 ] = { 0 } ;
			for ( int k = 0 ;  k < woerter.at( j ).size() ;  ++k )
				++buchstaben2[ woerter.at( j ).at( k ) - 'A' ] ;

			bool abbruch = false ;
			for ( int k = 0 ;  k < 27 ;  ++k )
				if ( buchstaben1[ k ] != buchstaben2[ k ] )
				{
					abbruch = true ;
					break ;
				}

			if ( !abbruch )
				anagramme.push_back( pair< string, string >( woerter.at( i ), woerter.at( j ) ) ) ;
		}
	}

	unsigned long long maxQuadratzahl = 0 ;
	for ( int i = 0 ;  i < anagramme.size() ;  ++i )
	{
		// verschiedene Buchstaben des Anagramm-Paares ermitteln
		set< char > buchstaben ;
		for ( int j = 0 ;  j < anagramme.at( i ).first.size() ;  ++j )
			buchstaben.insert( anagramme.at( i ).first.at( j ) ) ;
		
		for ( int j = pow( 10, double( buchstaben.size() - 1 ) ) ;  j < pow( 10, double( buchstaben.size() ) ) ;  ++j )
		{
			// Zifferkombinationen ermitteln, welche keine doppelten Ziffern haben
			int ziffern[ 10 ] = { 0 } ;
			int j_kpi = j ;
			bool abbruch = false ;
			while ( j_kpi > 0 )
			{
				++ziffern[ j_kpi % 10 ] ;
				if ( ziffern[ j_kpi % 10 ] > 1 )
				{
					abbruch = true ;
					break ;
				}
				j_kpi /= 10 ;
			}

			if ( !abbruch )
			{
				j_kpi = j ;

				// Int-Ersatz für Buchstaben
				int buchstabenersatz[ 128 + 1 ] = { 0 } ;
				set< char >::iterator it = buchstaben.begin() ;
				for ( ;  it != buchstaben.end() ;  ++it )
				{
					buchstabenersatz[ (*it) ] = j_kpi % 10 ;
					j_kpi /= 10 ;
				}

				// erster Buchstabe von Anagramm darf nicht 0 sein!
				if ( !buchstabenersatz[ anagramme.at( i ).first.at( 0 ) ] == 0 && !buchstabenersatz[ anagramme.at( i ).second.at( 0 ) ] == 0 )
				{
					unsigned long long ziffernWort1 = 0, ziffernWort2 = 0 ;
					for ( int k = 0 ;  k < anagramme.at( i ).first.size() ;  ++k )
						ziffernWort1 += buchstabenersatz[ anagramme.at( i ).first.at( k ) ] * pow( 10, double( anagramme.at( i ).first.size() - k - 1 ) ) ;

					// ist ziffernWort1 Quadratzahl?
					if ( int( sqrt( double( ziffernWort1 ) ) ) == sqrt( double( ziffernWort1 ) ) )
					{
						for ( int k = 0 ;  k < anagramme.at( i ).second.size() ;  ++k )
							ziffernWort2 += buchstabenersatz[ anagramme.at( i ).second.at( k ) ] * pow( 10, double( anagramme.at( i ).second.size() - k - 1 ) ) ;

						// ist ziffernWort2 Quadratzahl?
						if ( int( sqrt( double( ziffernWort2 ) ) ) == sqrt( double( ziffernWort2 ) ) )
						{
							maxQuadratzahl = max( maxQuadratzahl, ziffernWort1 ) ;
							maxQuadratzahl = max( maxQuadratzahl, ziffernWort2 ) ;
						}
					}
				}
			}
		}

	}

	cout << maxQuadratzahl << endl ;
	return 0 ;
}