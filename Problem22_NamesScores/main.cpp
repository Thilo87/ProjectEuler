/*

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing
over five-thousand first names, begin by sorting it into alphabetical order.
Then working out the alphabetical value for each name, multiply this value
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order,
COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in
the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
	// Vector mit allen Namen aus der Datei names.txt
	vector< string > namen ;


	/**** DATEI EINLESEN ****/
	fstream fin( "names.txt" ) ;

	string eingelesenerName ;
	char c ;
	while ( fin >> c )
		if ( c == ',' )
		{
			namen.push_back( eingelesenerName ) ;
			eingelesenerName.clear() ;
		}
		else if ( c != '\"' )
			eingelesenerName.append( 1, c ) ;

	// letzten Namen zur Liste hinzufügen ( auf den kein Komma folgt )
	namen.push_back( eingelesenerName ) ;

	fin.close() ;


	// namen in alphabetischer Reihenfolge sortieren
	sort( namen.begin(), namen.end() ) ;


	unsigned long long summe = 0 ;
	for ( int i = 0 ;  i < namen.size() ;  ++i )
		summe += wortWert( namen.at( i ) ) * ( i + 1 ) ;

	cout << summe << endl ;


	return 0 ;
}