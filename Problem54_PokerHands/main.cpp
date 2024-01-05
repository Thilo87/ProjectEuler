#include <iostream>
#include <algorithm>
#include <fstream>
#include "stoppuhr.h"
using namespace std ;

typedef unsigned long long uint64 ;

bool istRoyalFlush( uint64 kartenwert, uint64 farbenwert ) ;
int istStraightFlush( uint64 kartenwert, uint64 farbenwert ) ;
int istVierling( uint64 kartenwert ) ;
pair< int, int > istFullHouse( uint64 kartenwert ) ;
bool istFlush( uint64 farbenwert ) ;
int istStrasse( uint64 kartenwert ) ;
int istDrilling( uint64 kartenwert ) ;
pair< int, int > istZweiPaare( uint64 kartenwert ) ;
int istPaar( uint64 kartenwert ) ;


// Werte für				2, 3, 4, 5, 6,  7,  8,  9,  T,  J,  D,  K,  A
const int KARTENWERTE[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 } ;

// Werte für				H, D, S, C
const int FARBENWERTE[] = { 2, 3, 5, 7 } ;

const int iFALSCH = -1 ;
const pair< int, int > pFALSCH( iFALSCH, iFALSCH ) ;




uint64 kartenwert( char karten[ 5 ] )
{
	uint64 wert = 1 ;
	for ( int i = 0 ;  i < 5 ;  ++i )
	{
		if ( karten[ i ] >= '2' && karten[ i ] <= '9' )
			wert *= KARTENWERTE[ karten[ i ] - '0' - 2 ] ;
		else
		{
			switch ( karten[ i ] )
			{
			case 'T':
				wert *= KARTENWERTE[ 8 ] ;
				break ;
			case 'J':
				wert *= KARTENWERTE[ 9 ] ;
				break ;
			case 'Q':
				wert *= KARTENWERTE[ 10 ] ;
				break ;
			case 'K':
				wert *= KARTENWERTE[ 11 ] ;
				break ;
			case 'A':
				wert *= KARTENWERTE[ 12 ] ;
				break ;
			}
		}
	}

	return wert ;
}

uint64 farbenwert( char farben[ 5 ] )
{
	uint64 wert = 1 ;
	for ( int i = 0 ;  i < 5 ;  ++i )
		switch ( farben[ i ] )
		{
		case 'H':
			wert *= FARBENWERTE[ 0 ] ;
			break ;
		case 'D':
			wert *= FARBENWERTE[ 1 ] ;
			break ;
		case 'S':
			wert *= FARBENWERTE[ 2 ] ;
			break ;
		case 'C':
			wert *= FARBENWERTE[ 3 ] ;
			break ;
		}
	
	return wert ;
}




// gibt true / false
bool istRoyalFlush( uint64 kartenwert, uint64 farbenwert )
{
	if ( kartenwert == 23*29*31*37*41 )
		if ( istFlush( farbenwert ) )
			return true ;

	return false ;
}

// gibt höchste Straight-Flush-Karte
int istStraightFlush( uint64 kartenwert, uint64 farbenwert )
{
	int hoechsteKarte = istStrasse( kartenwert ) ;
	if ( hoechsteKarte != iFALSCH )
		if ( istFlush( farbenwert ) )
			return hoechsteKarte ;

	return iFALSCH ;
}

// gibt Vierling
int istVierling( uint64 kartenwert )
{
	if ( kartenwert % ( 2*2*2*2 ) == 0 )
		return 2 ;
	if ( kartenwert % ( 3*3*3*3 ) == 0 )
		return 3 ;
	if ( kartenwert % ( 5*5*5*5 ) == 0 )
		return 5 ;
	if ( kartenwert % ( 7*7*7*7 ) == 0 )
		return 7 ;
	if ( kartenwert % ( 11*11*11*11 ) == 0 )
		return 11 ;
	if ( kartenwert % ( 13*13*13*13 ) == 0 )
		return 13 ;
	if ( kartenwert % ( 17*17*17*17 ) == 0 )
		return 17 ;
	if ( kartenwert % ( 19*19*19*19 ) == 0 )
		return 19 ;
	if ( kartenwert % ( 23*23*23*23 ) == 0 )
		return 23 ;
	if ( kartenwert % ( 29*29*29*29 ) == 0 )
		return 29 ;
	if ( kartenwert % ( 31*31*31*31 ) == 0 )
		return 31 ;
	if ( kartenwert % ( 37*37*37*37 ) == 0 )
		return 37 ;
	if ( kartenwert % ( 41*41*41*41 ) == 0 )
		return 41 ;

	return iFALSCH ;
}

// gibt pair< Paar, Drilling >
pair< int, int > istFullHouse( uint64 kartenwert )
{
	int paar = 0, drilling = 0 ;

	// finde Drilling
	for ( int i = 0 ;  i < 13 ;  ++i )
		if ( kartenwert % ( KARTENWERTE[ i ] * KARTENWERTE[ i ] * KARTENWERTE[ i ] ) == 0 )
		{
			drilling = KARTENWERTE[ i ] ;
			break ;
		}

	// finde Paar
	for ( int i = 0 ;  i < 13 ;  ++i )
		if ( kartenwert % ( KARTENWERTE[ i ] * KARTENWERTE[ i ] ) == 0 )
			if ( KARTENWERTE[ i ] != drilling )
			{
				paar = KARTENWERTE[ i ] ;
				break ;
			}

	if ( paar != 0 && drilling != 0 )
		return pair< int, int >( paar, drilling ) ;

	return pFALSCH ;
}

// gibt true / false
bool istFlush( uint64 farbenwert )
{
	switch( farbenwert )
	{
	case 2*2*2*2*2:
	case 3*3*3*3*3:
	case 5*5*5*5*5:
	case 7*7*7*7*7:
		return true ;
	}

	return false ;
}

// gibt höchste Strassen-Karte
int istStrasse( uint64 kartenwert )
{
	switch( kartenwert )
	{
	case 41*2*3*5*7: // ?!
		return 41 ;
	case 2*3*5*7*11:
		return 11 ;
	case 3*5*7*11*13:
		return 13 ;
	case 5*7*11*13*17:
		return 17 ;
	case 7*11*13*17*19:
		return 19 ;
	case 11*13*17*19*23:
		return 23 ;
	case 13*17*19*23*29:
		return 29 ;
	case 17*19*23*29*31:
		return 31 ;
	case 19*23*29*31*37:
		return 37 ;
	case 23*29*31*37*41:
		return 41 ;
	}

	return iFALSCH ;
}

// gibt Drilling
int istDrilling( uint64 kartenwert )
{
	if ( kartenwert % ( 2*2*2 ) == 0 )
		return 2 ;
	if ( kartenwert % ( 3*3*3 ) == 0 )
		return 3 ;
	if ( kartenwert % ( 5*5*5 ) == 0 )
		return 5 ;
	if ( kartenwert % ( 7*7*7 ) == 0 )
		return 7 ;
	if ( kartenwert % ( 11*11*11 ) == 0 )
		return 11 ;
	if ( kartenwert % ( 13*13*13 ) == 0 )
		return 13 ;
	if ( kartenwert % ( 17*17*17 ) == 0 )
		return 17 ;
	if ( kartenwert % ( 19*19*19 ) == 0 )
		return 19 ;
	if ( kartenwert % ( 23*23*23 ) == 0 )
		return 23 ;
	if ( kartenwert % ( 29*29*29 ) == 0 )
		return 29 ;
	if ( kartenwert % ( 31*31*31 ) == 0 )
		return 31 ;
	if ( kartenwert % ( 37*37*37 ) == 0 )
		return 37 ;
	if ( kartenwert % ( 41*41*41 ) == 0 )
		return 41 ;

	return iFALSCH ;
}

// gibt pair< erstesPaar, zweitesPaar >
pair< int, int > istZweiPaare( uint64 kartenwert )
{
	int erstesPaar = 0, zweitesPaar = 0 ;

	int n = 0 ;
	for ( int i = 0 ;  i < 13 ;  ++i )
		if ( kartenwert % ( KARTENWERTE[ i ] * KARTENWERTE[ i ] ) == 0 )
			if ( n == 0 )
			{
				erstesPaar = KARTENWERTE[ i ] ;
				++n ;
			}
			else
				zweitesPaar = KARTENWERTE[ i ] ;

	if ( erstesPaar != 0 && zweitesPaar != 0 && erstesPaar != zweitesPaar )
		return pair< int, int >( erstesPaar, zweitesPaar ) ;

	return pFALSCH ;
}

// gibt Paar
int istPaar( uint64 kartenwert )
{
	if ( kartenwert % ( 2*2 ) == 0 )
		return 2 ;
	if ( kartenwert % ( 3*3 ) == 0 )
		return 3 ;
	if ( kartenwert % ( 5*5 ) == 0 )
		return 5 ;
	if ( kartenwert % ( 7*7 ) == 0 )
		return 7 ;
	if ( kartenwert % ( 11*11 ) == 0 )
		return 11 ;
	if ( kartenwert % ( 13*13 ) == 0 )
		return 13 ;
	if ( kartenwert % ( 17*17 ) == 0 )
		return 17 ;
	if ( kartenwert % ( 19*19 ) == 0 )
		return 19 ;
	if ( kartenwert % ( 23*23 ) == 0 )
		return 23 ;
	if ( kartenwert % ( 29*29 ) == 0 )
		return 29 ;
	if ( kartenwert % ( 31*31 ) == 0 )
		return 31 ;
	if ( kartenwert % ( 37*37 ) == 0 )
		return 37 ;
	if ( kartenwert % ( 41*41 ) == 0 )
		return 41 ;

	return iFALSCH ;
}

int* inWerteUmwandeln( char karten[ 5 ] )
{
	int* werte = new int[ 5 ] ;

	for ( int i = 0 ;  i < 5 ;  ++i )
	{
		if ( karten[ i ] >= '2' && karten[ i ] <= '9' )
			werte[ i ] = KARTENWERTE[ karten[ i ] - '0' - 2 ] ;
		else
		{
			switch ( karten[ i ] )
			{
			case 'T':
				werte[ i ] = KARTENWERTE[ 8 ] ;
				break ;
			case 'J':
				werte[ i ] = KARTENWERTE[ 9 ] ;
				break ;
			case 'Q':
				werte[ i ] = KARTENWERTE[ 10 ] ;
				break ;
			case 'K':
				werte[ i ] = KARTENWERTE[ 11 ] ;
				break ;
			case 'A':
				werte[ i ] = KARTENWERTE[ 12 ] ;
				break ;
			}
		}
	}

	sort( werte, werte + 5 ) ;

	return werte ;
}

// gibt
// 0: unentschieden
// 1: Spieler 1 hat gewonnen
// 2: Spieler 2 hat gewonnen
int gewinner( char karten1[ 5 ], char farben1[ 5 ], char karten2[ 5 ], char farben2[ 5 ] )
{
	uint64 kartenwert1 = kartenwert( karten1 ) ;
	uint64 farbenwert1 = farbenwert( farben1 ) ;
	uint64 kartenwert2 = kartenwert( karten2 ) ;
	uint64 farbenwert2 = farbenwert( farben2 ) ;



	// Royal Flush
	bool royalflush1 = istRoyalFlush( kartenwert1, farbenwert1 ) ;
	bool royalflush2 = istRoyalFlush( kartenwert2, farbenwert2 ) ;
	if ( royalflush1 && !royalflush2 )
		return 1 ;
	else if ( !royalflush1 && royalflush2 )
		return 2 ;
	else if ( royalflush1 && royalflush2 )
		return 0 ;
	


	// Straight Flush
	int straightflush1 = istStraightFlush( kartenwert1, farbenwert1 ) ;
	int straightflush2 = istStraightFlush( kartenwert2, farbenwert2 ) ;
	if ( straightflush1 != iFALSCH && straightflush2 == iFALSCH )
		return 1 ;
	else if ( straightflush1 == iFALSCH && straightflush2 != iFALSCH )
		return 2 ;
	else if ( straightflush1 != iFALSCH && straightflush2 != iFALSCH )
	{
		if ( straightflush1 > straightflush2 )
			return 1 ;
		else if ( straightflush2 > straightflush1 )
			return 2 ;
		else
			return 0 ;
	}


	int* iKarten1 = inWerteUmwandeln( karten1 ) ;
	int* iKarten2 = inWerteUmwandeln( karten2 ) ;

	if ( istDrilling( kartenwert1 ) != iFALSCH || istDrilling( kartenwert2 ) != iFALSCH )
	{
	// Vierling
	int vierling1 = istVierling( kartenwert1 ) ;
	int vierling2 = istVierling( kartenwert2 ) ;
	if ( vierling1 != iFALSCH && vierling2 == iFALSCH )
		return 1 ;
	else if ( vierling1 == iFALSCH && vierling2 != iFALSCH )
		return 2 ;
	else if ( vierling1 != iFALSCH && vierling2 != iFALSCH )
	{
		if ( vierling1 > vierling2 )
			return 1 ;
		else if ( vierling2 > vierling1 )
			return 2 ;
		else // beide haben einen Vierling
		{
			for ( int i = 4 ;  i >= 0 ;  --i )
				if ( iKarten1[ i ] > iKarten2[ i ] )
					return 1 ;
				else if ( iKarten2[ i ] > iKarten1[ i ] )
					return 2 ;

			return 0 ;
		}
	}


	// Full House
	pair< int, int > fullhouse1 = istFullHouse( kartenwert1 ) ;
	pair< int, int > fullhouse2 = istFullHouse( kartenwert2 ) ;
	if ( fullhouse1.first != iFALSCH && fullhouse2.first == iFALSCH )
		return 1 ;
	else if ( fullhouse1.first == iFALSCH && fullhouse2.first != iFALSCH )
		return 2 ;
	else if ( fullhouse1.first != iFALSCH && fullhouse2.first != iFALSCH )
	{
		if ( fullhouse1.second > fullhouse2.second )
			return 1 ;
		else if ( fullhouse2.second > fullhouse1.second )
			return 2 ;
		else
		{
			if ( fullhouse1.first > fullhouse2.first )
				return 1 ;
			else if ( fullhouse2.first > fullhouse1.first )
				return 2 ;
			else
				return 0 ;
		}
	}
	}

	// Flush
	bool flush1 = istFlush( farbenwert1 ) ;
	bool flush2 = istFlush( farbenwert2 ) ;
	if ( flush1 && !flush2 )
		return 1 ;
	else if ( !flush1 && flush2 )
		return 2 ;
	else if ( flush1 && flush2 )
	{
		for ( int i = 4 ;  i >= 0 ;  --i )
			if ( iKarten1[ i ] > iKarten2[ i ] )
				return 1 ;
			else if ( iKarten2[ i ] > iKarten1[ i ] )
				return 2 ;

		return 0 ;
	}


	// Strasse
	int strasse1 = istStrasse( kartenwert1 ) ;
	int strasse2 = istStrasse( kartenwert2 ) ;
	if ( strasse1 != iFALSCH && strasse2 == iFALSCH )
		return 1 ;
	else if ( strasse1 == iFALSCH && strasse2 != iFALSCH )
		return 2 ;
	else if ( strasse1 != iFALSCH && strasse2 != iFALSCH )
	{
		if ( strasse1 > strasse2 )
			return 1 ;
		else if ( strasse2 > strasse1 )
			return 2 ;
		else
			return 0 ;
	}
	

	// Drilling
	int drilling1 = istDrilling( kartenwert1 ) ;
	int drilling2 = istDrilling( kartenwert2 ) ;
	if ( drilling1 != iFALSCH && drilling2 == iFALSCH )
		return 1 ;
	else if ( drilling1 == iFALSCH && drilling2 != iFALSCH )
		return 2 ;
	else if ( drilling1 != iFALSCH && drilling2 != iFALSCH )
	{
		for ( int i = 4 ;  i >= 0 ;  --i )
			if ( iKarten1[ i ] > iKarten2[ i ] )
				return 1 ;
			else if ( iKarten2[ i ] > iKarten1[ i ] )
				return 2 ;

		return 0 ;
	}


	// Zwei Paare
	pair< int, int > zweipaare1 = istZweiPaare( kartenwert1 ) ;
	pair< int, int > zweipaare2 = istZweiPaare( kartenwert2 ) ;
	if ( zweipaare1.first != iFALSCH && zweipaare2.first == iFALSCH )
		return 1 ;
	else if ( zweipaare1.first == iFALSCH && zweipaare2.first != iFALSCH )
		return 2 ;
	else if ( zweipaare1.first != iFALSCH && zweipaare2.first != iFALSCH )
	{
		for ( int i = 4 ;  i >= 0 ;  --i )
			if ( iKarten1[ i ] > iKarten2[ i ] )
				return 1 ;
			else if ( iKarten2[ i ] > iKarten1[ i ] )
				return 2 ;

		return 0 ;
	}
	
	// ein Paar
	int paar1 = istPaar( kartenwert1 ) ;
	int paar2 = istPaar( kartenwert2 ) ;
	if ( paar1 != iFALSCH && paar2 == iFALSCH )
		return 1 ;
	else if ( paar1 == iFALSCH && paar2 != iFALSCH )
		return 2 ;
	else if ( paar1 != iFALSCH && paar2 != iFALSCH )
	{
		if ( paar1 > paar2 )
			return 1 ;
		else if ( paar2 > paar1 )
			return 2 ;
		else
		{
			for ( int i = 4 ;  i >= 0 ;  --i )
				if ( iKarten1[ i ] > iKarten2[ i ] )
					return 1 ;
				else if ( iKarten2[ i ] > iKarten1[ i ] )
					return 2 ;

			return 0 ;
		}
	}

	// High Card
	for ( int i = 4 ;  i >= 0 ;  --i )
		if ( iKarten1[ i ] > iKarten2[ i ] )
			return 1 ;
		else if ( iKarten2[ i ] > iKarten1[ i ] )
			return 2 ;

	delete[] iKarten1 ;
	delete[] iKarten2 ;

	

	return 0 ;
}

int main ()
{
	stoppUhr( START ) ;
	ifstream fin( "poker.txt" ) ;

	int anzahlGewinner1 = 0 ;
	for ( int i = 0 ;  i < 100000 ;  ++i )
	{
		char karten1[ 5 ], farben1[ 5 ] ;
		for ( int j = 0 ;  j < 5 ;  ++j )
		{
			fin >> karten1[ j ] ;
			fin >> farben1[ j ] ;
		}

		char karten2[ 5 ], farben2[ 5 ] ;
		for ( int j = 0 ;  j < 5 ;  ++j )
		{
			fin >> karten2[ j ] ;
			fin >> farben2[ j ] ;
		}

		int gew = gewinner( karten1, farben1, karten2, farben2 ) ;
		if ( gew == 1 )
			++anzahlGewinner1 ;
	}

	fin.close() ;

	cout << anzahlGewinner1 << endl ;
	cout << stoppUhr( STOPP ) << "s" << endl ;

	return 0 ;
}