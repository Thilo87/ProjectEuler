#include "ganzeZahl.h"

// mathematische Operationen
void ganzeZahl::addiere( long long zahl )
{

}

void ganzeZahl::addiere( ganzeZahl& zahl )
{
	int laengeZahl1 = this ->ziffernAnzahl ;
	int laengeZahl2 = zahl.getZiffernanzahl() ;

	// Die Summe zweier Zahlen hat maximal die Anzahl Ziffern: max( laenge( zahl1 ) , laenge( zahl2 ) ) + 1
	// Da an das Ende von der Summe beider Zahlen das ENDE-Zeichen gehört, muss die Dimension vom
	// dynamischen Array summe gleich max( laenge( zahl1 ) , laenge ( zahl2 ) ) + 2 sein.
	int dimSumme = max( laengeZahl1, laengeZahl2 ) + 2 ;

	// dynamisches Array für das Ergebnis der Addition allozieren
	int* summe = new int[ dimSumme ] ;

	int uebertrag = 0 ;

	// Addition von zahl1 und zahl2 nach der einfachsten Form der schriftlichen Addition durchführen:
	// beide Zahlen werden untereinander geschrieben, die jeweiligen Ziffern ( + evtl. Übertrag ) addiert,
	// die zweite Ziffer ist die jeweilige Ergebnisziffer und die erste Ziffer der Übertrag
	for ( int i = 0 ;  i < dimSumme - 1 ;  ++i )
	{
		// summe[ i ] den Übertrag aus der letzten Iteration zuweisen
		summe[ i ] = uebertrag ;

		// die einzelnen Ziffern beider Zahlen zum Übertrag aus der letzten Iteration hinzuaddieren
		// und darauf achten, die Arraygrenzen beider Zahlen nicht zu überschreiten
		if ( i < laengeZahl1 )
			summe[ i ] += this ->ziffern[ i ] ;
		if ( i < laengeZahl2 )
			summe[ i ] += zahl.getZiffer( i ) ;

		// neuen Übertrag und Ziffer von summe[ i ] berechnen
		uebertrag = summe[ i ] / 10 ;
		summe[ i ] %= 10 ;
	}

	// Überzählige Nullen am Anfang der Zahl von der Dimension abziehen
	for ( int i = dimSumme - 1 ;  i > 0 && summe[ i ] == 0 ;  --i )
		--dimSumme ;

	delete[] this ->ziffern ;
	this ->ziffernAnzahl = dimSumme ;
	this ->ziffern = summe ;
	this ->aktualisiereText() ;
}

void ganzeZahl::addiere( int ziffernAnzahl, int* ziffern )
{

}

void ganzeZahl::multipliziere( ganzeZahl& zahl )
{

}

// aktualisiert die Zahl alsText, wenn ziffernAnzahl und ziffern schon aktualisiert worden sind
void ganzeZahl::aktualisiereText()
{
	delete[] this ->alsText ;

	// Zahl als Text speichern ( char* )
	if ( this ->istNegativ ) // ist die Zahl negativ, muss zusätzlich noch das Vorzeichen als Text gespeichert werden
	{
		alsText = new char[ this ->ziffernAnzahl + 2 ] ;
		alsText[ 0 ] = '-' ;

		for ( int i = 1 ;  i < this ->ziffernAnzahl + 1 ;  ++i )
			this ->alsText[ this ->ziffernAnzahl + 1 - i ] = ziffern[ i - 1 ] + '0' ;

		alsText[ this ->ziffernAnzahl + 1 ] = '\0' ;
	}
	else
	{
		alsText = new char[ this ->ziffernAnzahl + 1 ] ;

		for ( int i = 0 ;  i < this ->ziffernAnzahl ;  ++i )
			this ->alsText[ this ->ziffernAnzahl - i - 1 ] = ziffern[ i ] + '0' ;

		alsText[ this ->ziffernAnzahl ] = '\0' ;
	}
}

// Konstruktoren
ganzeZahl::ganzeZahl( long long zahl )
{
	// initialisiere die Zahl mit 0
	if ( zahl == 0 )
	{
		this ->ziffernAnzahl = 1 ;
		this ->istNegativ = false ;

		this ->ziffern = new int[ 1 ] ;
		this ->ziffern[ 0 ] = 0 ;

		this ->alsText = new char[ 1 ] ;
		this ->alsText[ 0 ] = '0' ;
		this ->alsText[ 1 ] = '\0' ;

		return ;
	}

	int laenge = 0 ;

	// Ziffernanzahl von zahl ermitteln. log10( double( zahl ) ) + 1 wird nicht verwendet, um die eventuell
	// problematische Umwandlung von long long in double zu vermeiden
	long long temp = zahl ;
	for ( ; temp != 0 ;  ++laenge )
		temp /= 10 ;

	// Ziffernanzahl speichern
	this ->ziffernAnzahl = laenge ;

	// Array für die Ziffern allozieren
	this ->ziffern = new int[ laenge ] ;

	// speichern, ob die Zahl positiv oder negativ ist
	if ( zahl < 0 )
		this ->istNegativ = true ;
	else
		this ->istNegativ = false ;

	// Ziffern von zahl im Array ziffern speichern
	zahl = abs( zahl ) ;
	for ( int i = 0 ;  i < laenge ;  ++i )
	{
		this ->ziffern[ i ] = zahl % 10 ;

		zahl -= ziffern[ i ] ;
		zahl /= 10 ;
	}

	// Zahl als Text speichern ( char* )
	if ( istNegativ ) // ist die Zahl negativ, muss zusätzlich noch das Vorzeichen als Text gespeichert werden
	{
		alsText = new char[ laenge + 2 ] ;
		alsText[ 0 ] = '-' ;

		for ( int i = 1 ;  i < laenge + 1 ;  ++i )
			this ->alsText[ laenge + 1 - i ] = ziffern[ i - 1 ] + '0' ;

		alsText[ laenge + 1 ] = '\0' ;
	}
	else
	{
		alsText = new char[ laenge + 1 ] ;

		for ( int i = 0 ;  i < laenge ;  ++i )
			this ->alsText[ laenge - i - 1 ] = ziffern[ i ] + '0' ;

		alsText[ laenge ] = '\0' ;
	}
}

ganzeZahl::ganzeZahl( ganzeZahl const& rhs )
{
	this ->ziffernAnzahl = rhs.ziffernAnzahl ;
	this ->istNegativ = rhs.istNegativ ;

	// Zahl als Text kopieren
	if ( rhs.istNegativ )
	{
		this ->alsText = new char[ rhs.ziffernAnzahl + 2 ] ;

		for ( int i = 0 ;  i < rhs.ziffernAnzahl + 2 ;  ++i )
			this ->alsText[ i ] = rhs.alsText[ i ] ;

		this ->alsText[ rhs.ziffernAnzahl + 1 ] = '\0' ;
	}
	else
	{
		this ->alsText = new char[ rhs.ziffernAnzahl + 1 ] ;

		for ( int i = 0 ;  i < rhs.ziffernAnzahl + 1 ;  ++i )
			this ->alsText[ i ] = rhs.alsText[ i ] ;

		this ->alsText[ rhs.ziffernAnzahl ] = '\0' ;
	}
	
	// Ziffern kopieren
	this ->ziffern = new int[ rhs.ziffernAnzahl ] ;
	for ( int i = 0 ;  i < rhs.ziffernAnzahl ;  ++i )
		ziffern[ i ] = rhs.ziffern[ i ] ;
} ;

ganzeZahl::ganzeZahl( int ziffernAnzahl, bool istNegativ, int* ziffern )
{
	this ->ziffernAnzahl = ziffernAnzahl ;
	this ->istNegativ = istNegativ ;
	this ->ziffern = ziffern ;
	
	// Zahl als Text speichern ( char* )
	if ( istNegativ ) // ist die Zahl negativ, muss zusätzlich noch das Vorzeichen als Text gespeichert werden
	{
		alsText = new char[ this ->ziffernAnzahl + 2 ] ;
		alsText[ 0 ] = '-' ;

		for ( int i = 1 ;  i < this ->ziffernAnzahl + 1 ;  ++i )
			this ->alsText[ this ->ziffernAnzahl + 1 - i ] = ziffern[ i - 1 ] + '0' ;

		alsText[ this ->ziffernAnzahl + 1 ] = '\0' ;
	}
	else
	{
		alsText = new char[ this ->ziffernAnzahl + 1 ] ;

		for ( int i = 0 ;  i < this ->ziffernAnzahl ;  ++i )
			this ->alsText[ this ->ziffernAnzahl - i - 1 ] = ziffern[ i ] + '0' ;

		alsText[ this ->ziffernAnzahl ] = '\0' ;
	}


}

ganzeZahl::ganzeZahl()
{
	this ->istNegativ = false ;
	this ->ziffernAnzahl = 1 ;

	this ->ziffern = new int[ 1 ] ;
	this ->ziffern[ 0 ] = 0 ;

	this ->alsText = new char[ 2 ] ;
	this ->alsText[ 0 ] = '0' ;
	this ->alsText[ 1 ] = '\0' ;
}



const ganzeZahl ganzeZahl::operator-()
{
	ganzeZahl neu( *this ) ;

	return neu ;
}

const ganzeZahl operator+( ganzeZahl& lhs )
{
	ganzeZahl kopie( lhs ) ;
	kopie.addiere( lhs ) ;

	return kopie ;
}

ganzeZahl::~ganzeZahl()
{
	delete[] alsText ;
	delete[] ziffern ;
}