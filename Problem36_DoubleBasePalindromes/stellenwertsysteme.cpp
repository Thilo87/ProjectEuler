#include "stellenwertsysteme.h"

// wandelt eine Dezimalzahl in eine Binärzahl um
char* dez_in_bin( unsigned long long n )
{
	if ( n == 0 ) // Sonderfall
	{
		char* binaerzahl = new char[ 1 ] ;
		binaerzahl[ 0 ] = '0' ;
		binaerzahl[ 1 ] = '\0' ;
		return binaerzahl ;
	}

	// Ziffernanzahl der nach der Umwandlung resultierenden Binärzahl bestimmen
	int binaerzahlZiffern = int( floor( log( double( n ) ) / log( 2. ) ) + 1 ) ;

	// +1 wegen dem Nullzeichen
	char* binaerzahl = new char[ binaerzahlZiffern + 1 ] ;

	// Umwandeln nach der Modulo-Methode
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = n % 2 ;
		binaerzahl[ binaerzahlZiffern - i - 1 ] = ziffer + '0' ;
		n /= 2 ;
	}

	binaerzahl[ binaerzahlZiffern ] = '\0' ;

	return binaerzahl ;
}

vector< int > dez_in_bin_v( unsigned long long n )
{
	if ( n == 0 ) // Sonderfall
	{
		vector< int > binaerzahl ;
		binaerzahl.push_back( 0 ) ;
		return binaerzahl ;
	}

	// Ziffernanzahl der nach der Umwandlung resultierenden Binärzahl bestimmen
	int binaerzahlZiffern = int( floor( log( double( n ) ) / log( 2. ) ) + 1 ) ;

	// +1 wegen dem Nullzeichen
	vector< int > binaerzahl( binaerzahlZiffern ) ;

	// Umwandeln nach der Modulo-Methode
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = n % 2 ;
		binaerzahl.at( binaerzahlZiffern - i - 1 ) = ziffer ;
		n /= 2 ;
	}

	return binaerzahl ;
}



// wandelt eine Binärzahl in eine Dezimalzahl um
unsigned long long bin_in_dez( char const* n )
{
	// Ziffern der Binärzahl bestimmen
	int binaerzahlZiffern = 0 ;
	while ( n[ binaerzahlZiffern ] != '\0' )
		++binaerzahlZiffern ;


	unsigned long long dezimalzahl = 0 ;

	// in Dezimalzahl umwandeln, indem jede Ziffer mit ihrem jeweiligen Stellenwert ( Zweierpotenz ) multipliziert wird
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
		dezimalzahl += int ( ( n[ binaerzahlZiffern - i - 1 ] - '0' ) * pow( 2., i ) ) ;
	
	return dezimalzahl ;
}

unsigned long long bin_in_dez_v( vector< int > const& n )
{
	unsigned long long dezimalzahl = 0 ;

	// in Dezimalzahl umwandeln, indem jede Ziffer mit ihrem jeweiligen Stellenwert ( Zweierpotenz ) multipliziert wird
	for ( int i = 0 ;  i < signed( n.size() ) ;  ++i )
		dezimalzahl += int ( n.at( n.size() - i - 1 ) * pow( 2., i ) ) ;
	
	return dezimalzahl ;
}