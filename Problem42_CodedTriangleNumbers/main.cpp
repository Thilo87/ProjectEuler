/*

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its
alphabetical position and adding these values we form a word value.
For example, the word value for SKY is 19 + 11 + 25 = 55 = t10.
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K
text file containing nearly two-thousand common English words, how many are triangle words?

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std ;

// gibt den "Wortwert" eines Wortes zurück, also die Summe der alphabetischen Positionen der einzelnen Buchstaben
int wortWert( string wort )
{
	int wert = 0 ;
	for ( int i = 0 ;  i < wort.size() ;  ++i )
	{
		char buchstabe = wort.at( i ) ;
		if ( buchstabe >= 'A' && buchstabe <= 'Z' )
			wert += wort.at( i ) - 'A' + 1 ;
		else if ( buchstabe >= 'a' && buchstabe <= 'z' )
			wert += wort.at( i ) - 'a' + 1 ;
	}

	return wert ;
}

int main ()
{
	int const MAX_DREIECKSZAHL = 1000 ;
	bool istDreieckszahl[ ( MAX_DREIECKSZAHL * ( MAX_DREIECKSZAHL + 1 ) / 2 ) + 1 ] = { false } ;

	for ( int i = 1 ;  i <= MAX_DREIECKSZAHL ;  ++i )
		istDreieckszahl[ i * ( i + 1 ) / 2 ] = true ;



	vector< string > woerter ;
	

	fstream fin( "words.txt" ) ;

	char c ;
	string aktuellesWort ;
	while ( fin >> c )
	{
		if ( c == ',' )
		{
			woerter.push_back( aktuellesWort ) ;
			aktuellesWort.clear() ;
		}
		else
			aktuellesWort.append( 1, c ) ;
		
	}

	// letztes Wort hinzufügen ( hinter dem kein Komma folgt )
	woerter.push_back( aktuellesWort ) ;

	fin.close() ;



	int dreieckswoerter = 0 ;
	for ( int i = 0 ;  i < woerter.size() ;  ++i )
		if ( istDreieckszahl[ wortWert( woerter.at( i ) ) ] )
			++dreieckswoerter ;

	cout << dreieckswoerter << endl ;
	
	return 0 ;
}