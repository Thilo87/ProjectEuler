#include "string_math.h"

typedef unsigned long long uint64 ;

// ist lhs > rhs ?
bool operator>( string& lhs, string& rhs )
{
	if ( lhs.size() > rhs.size() )
		return true ;
	
	if ( lhs.size() < rhs.size() )
		return false ;

	// ziffernweise vergleichen
	for ( int i = 0 ;  i < lhs.size() ;  ++i )
	{
		if ( lhs.at( i ) - '0' > rhs.at( i ) - '0' )
			return true ;
		else if ( lhs.at( i ) - '0' < rhs.at( i ) - '0' )
			return false ;
	}

	return false ;
}

// ist lhs < rhs ?
bool operator<( string& lhs, string& rhs )
{
	if ( lhs.size() > rhs.size() )
		return false ;
	
	if ( lhs.size() < rhs.size() )
		return true ;

	// ziffernweise vergleichen
	for ( int i = 0 ;  i < lhs.size() ;  ++i )
	{
		if ( lhs.at( i ) - '0' > rhs.at( i ) - '0' )
			return false ;
		else if ( lhs.at( i ) - '0' < rhs.at( i ) - '0' )
			return true ;
	}

	return false ;
}

// ist lhs = rhs ?
bool operator==( string& lhs, string& rhs )
{
	if ( lhs.size() > rhs.size() )
		return false ;
	
	if ( lhs.size() < rhs.size() )
		return false ;

	// ziffernweise vergleichen
	for ( int i = 0 ;  i < lhs.size() ;  ++i )
		if ( lhs.at( i ) - '0' != rhs.at( i ) - '0' )
			return false ;

	return true ;
}

// ist lhs >= rhs ?
bool operator>=( string& lhs, string& rhs )
{
	if ( lhs.size() > rhs.size() )
		return true ;
	
	if ( lhs.size() < rhs.size() )
		return false ;

	// ziffernweise vergleichen
	for ( int i = 0 ;  i < lhs.size() ;  ++i )
	{
		if ( lhs.at( i ) - '0' > rhs.at( i ) - '0' )
			return true ;
		else if ( lhs.at( i ) - '0' < rhs.at( i ) - '0' )
			return false ;
	}

	return true ;
}

// ist lhs <= rhs ?
bool operator<=( string& lhs, string& rhs )
{
	if ( lhs.size() > rhs.size() )
		return false ;
	
	if ( lhs.size() < rhs.size() )
		return true ;

	// ziffernweise vergleichen
	for ( int i = 0 ;  i < lhs.size() ;  ++i )
	{
		if ( lhs.at( i ) - '0' > rhs.at( i ) - '0' )
			return false ;
		else if ( lhs.at( i ) - '0' < rhs.at( i ) - '0' )
			return true ;
	}

	return true ;
}



// Berechnet minuend - subtrahend, wobei minuend >= subtrahend sein muss
string sub( string minuend, string subtrahend )
{
	string ergebnis ;

	int uebertrag = 0 ;
	for ( int i = 0 ;  i < minuend.size() ;  ++i )
	{
		int zifferMinuend = minuend.at( minuend.size() - i - 1 ) - '0' ;
		int zifferSubtrahend = ( signed( subtrahend.size() - i - 1 ) >= 0 ) ?
								 subtrahend.at( subtrahend.size() - i - 1 ) - '0' : 0 ;

		zifferSubtrahend += uebertrag ;
		uebertrag = 0 ;

		int zifferErgebnis ;
		if ( zifferMinuend < zifferSubtrahend )
		{
			zifferErgebnis = zifferMinuend + 10 - zifferSubtrahend ;
			uebertrag = 1 ;
		}
		else
			zifferErgebnis = zifferMinuend - zifferSubtrahend ;

		ergebnis.push_back( zifferErgebnis + '0' ) ;
	}

	while ( ergebnis.back() == '0' )
		ergebnis.pop_back() ;

	reverse( ergebnis.begin(), ergebnis.end() ) ;
	if ( ergebnis.size() == 0 )
		ergebnis = "0" ;
	
	return ergebnis ;
}

// Berechnet ersterSummand + zweiterSummand
string add( string ersterSummand, string zweiterSummand )
{
	string summe ;

	string& obererSummand = ( ersterSummand.size() > zweiterSummand.size() ) ? ersterSummand : zweiterSummand ;
	string& untererSummand = ( ersterSummand.size() > zweiterSummand.size() ) ? zweiterSummand : ersterSummand ;

	int uebertrag = 0 ;
	for ( int i = 0 ;  i < obererSummand.size() ;  ++i )
	{
		int obereZiffer = obererSummand.at( obererSummand.size() - i - 1 ) - '0' ;
		int untereZiffer = ( signed( untererSummand.size() - i - 1 ) >= 0 ) ? untererSummand.at( untererSummand.size() - i - 1 ) - '0' : 0 ;
		
		int ergebnisZiffer = obereZiffer + untereZiffer + uebertrag ;
		uebertrag = 0 ;
		if ( ergebnisZiffer >= 10 )
		{
			ergebnisZiffer -= 10 ;
			uebertrag = 1 ;
		}

		summe.push_back( ergebnisZiffer + '0' ) ;
	}

	if ( uebertrag != 0 )
		summe.push_back( uebertrag + '0' ) ;

	reverse( summe.begin(), summe.end() ) ;

	return summe ;
}

// Führt eine Division mit Rest dividend / divisior aus, wobei pair< Ganzzahliger Anteil, Rest > ausgegeben wird
pair< string, string > div( string dividend, string divisor )
{
	pair< string, string > ergebnis ;

	string rest( dividend ) ; // pair.second
	string originalDivisor( divisor ) ;

	string vielfaches = "0" ; // pair.first
	string multiplikator = "1" ;
	
	if ( signed( dividend.size() - divisor.size() - 1 ) >= 0 )
	{
		multiplikator.append( dividend.size() - divisor.size() - 1, '0' ) ;
		divisor.append( dividend.size() - divisor.size() - 1, '0' ) ;
	}
	
	while ( rest >= originalDivisor )
	{
		
		while ( rest >= divisor )
		{
			rest = sub( rest, divisor ) ;
			vielfaches = add( vielfaches, multiplikator ) ;
		}

		while ( divisor.size() >= rest.size() && divisor.size() > originalDivisor.size() )
		{
			divisor.pop_back() ;
			multiplikator.pop_back() ;
		}
	}

	ergebnis.first = vielfaches ;
	ergebnis.second = rest ;
	
	return ergebnis ;
}