/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters
and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is
in compliance with British usage.

*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std ;

// übersetzt eine Zahl in Englisch
string aufEnglisch( unsigned long long n )
{
	string const NULL_BIS_NEUNZEHN[ 20 ] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
											 "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
											 "sixteen", "seventeen", "eighteen", "nineteen" } ;

	string const ZEHNERSCHRITTE[ 11 ] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
										  "eighty", "ninety" } ;

	string const HUNDERT = "hundred" ;
	string const TAUSEND = "thousand" ;
	string const MILLION = "million" ;
	string const MILLIARDE = "billion" ;

	if ( n == 0 || n <= 19 )
		return NULL_BIS_NEUNZEHN[ n ] ;


	if ( n == 20 || n <= 99 )
	{
		string uebersetzung ;
		uebersetzung += ZEHNERSCHRITTE[ n / 10 ] ;

		if ( n % 10 != 0 )
			uebersetzung += "-" + aufEnglisch( n % 10 ) ;

		return uebersetzung ;
	}


	int ziffernanzahl = int( log10( double( n ) ) ) + 1 ;
	string uebersetzung ;

	switch ( ziffernanzahl )
	{
	case 3:
		uebersetzung += aufEnglisch( n / 100 ) + " " ;
		uebersetzung += HUNDERT ;
		if ( n % 100 != 0 )
			uebersetzung += " and " + aufEnglisch( n % 100 ) ;
		break ;

	case 4: case 5: case 6:
		uebersetzung += aufEnglisch( n / 1000 ) + " " ;
		uebersetzung += TAUSEND ;
		if ( n % 1000 != 0 )
			uebersetzung += " and " + aufEnglisch( n % 1000 ) ;
		break ;

	case 7: case 8: case 9:
		uebersetzung += aufEnglisch( n / 1000000 ) + " " ;
		uebersetzung += MILLION ;
		if ( n % 1000000 != 0 )
			uebersetzung += " and " + aufEnglisch( n % 1000000 ) ;
		break ;

	default:
		uebersetzung += aufEnglisch( n / 1000000000 ) + " " ;
		uebersetzung += MILLIARDE ;
		if ( n % 1000000000 != 0 )
			uebersetzung += " and " + aufEnglisch( n % 1000000000 ) ;
	}

	return uebersetzung ;
}



int main ()
{
	long long anzahl = 0 ;
	for ( int i = 1 ;  i <= 1000 ;  ++i )
	{
		string zahl = aufEnglisch( i ) ;

		int buchstabenanzahl = 0 ;
		for ( int j = 0 ;  j < zahl.size() ;  ++j )
			if ( zahl.at( j ) != ' ' && zahl.at( j ) != '-' )
				++buchstabenanzahl ;

		anzahl += buchstabenanzahl ;
	}

	cout << anzahl << endl ;
	cout << aufEnglisch( anzahl ) << endl ;
	return 0 ;
}