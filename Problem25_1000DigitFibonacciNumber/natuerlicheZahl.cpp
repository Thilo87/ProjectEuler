#include "natuerlicheZahl.h"

// Konstruktoren
natuerlicheZahl::natuerlicheZahl()
{
	this ->ziffernanzahl = 1 ;
	this ->ziffern = new int[ 1 ] ;
	this ->ziffern[ 0 ] = 0 ;
}

natuerlicheZahl::natuerlicheZahl( natuerlicheZahl const& zahl )
{
	this ->ziffernanzahl = zahl.ziffernanzahl ;
	
	this ->ziffern = new int[ zahl.ziffernanzahl ] ;
	for ( int i = 0 ;  i < zahl.ziffernanzahl ;  ++i )
		this ->ziffern[ i ] = zahl.ziffern[ i ] ;
}

natuerlicheZahl::natuerlicheZahl( char const* zahl )
{
	int zahlLaenge = 0 ; // Anzahl der Ziffern der Zahl im Argument
	while( zahl[ zahlLaenge ] != '\0' )
		++zahlLaenge ;

	this ->ziffern = new int[ zahlLaenge ] ;
	for ( int i = 0 ;  i < zahlLaenge ;  ++i )
		this ->ziffern[ zahlLaenge - i - 1 ] = zahl[ i ] - '0' ;

	this ->ziffernanzahl = zahlLaenge ;
}

natuerlicheZahl::natuerlicheZahl( unsigned long long zahl )
{
	if ( zahl == 0 )
	{
		this ->ziffernanzahl = 1 ;
		this ->ziffern = new int[ 1 ] ;
		this ->ziffern[ 0 ] = 0 ;
		return ;
	}

	int laenge = 0 ;

	// Ziffernanzahl von zahl ermitteln. log10( double( zahl ) ) + 1 wird nicht verwendet, um die eventuell
	// problematische Umwandlung von long long in double zu vermeiden
	long long temp = zahl ;
	for ( ; temp != 0 ;  ++laenge )
		temp /= 10 ;

	// Ziffernanzahl speichern
	this ->ziffernanzahl = laenge ;

	// Array für die Ziffern allozieren
	this ->ziffern = new int[ laenge ] ;

	// Ziffern von zahl im Array ziffern speichern
	for ( int i = 0 ;  i < laenge ;  ++i )
	{
		this ->ziffern[ i ] = zahl % 10 ;

		zahl -= ziffern[ i ] ;
		zahl /= 10 ;
	}
}


// Destruktor
natuerlicheZahl::~natuerlicheZahl()
{
	delete[] this ->ziffern ;
}





// mathematische Operationen
void natuerlicheZahl::addiere( natuerlicheZahl const& zahl )
{
	int laengeZahl1 = this ->ziffernanzahl ;
	int laengeZahl2 = zahl.ziffernanzahl ;
	

	// Die Summe zweier Zahlen hat maximal die Anzahl Ziffern: max( laenge( zahl1 ) , laenge( zahl2 ) ) + 1
	// Da an das Ende von der Summe beider Zahlen das ENDE-Zeichen gehört, muss die Dimension vom
	// dynamischen Array summe gleich max( laenge( zahl1 ) , laenge ( zahl2 ) ) + 2 sein.
	int dimSumme = max( laengeZahl1, laengeZahl2 ) + 2 ;

	// dynamisches Array für das Ergebnis der Addition allozieren
	int* summe = new int[ dimSumme ] ;
	for ( int i = 0 ;  i < dimSumme ;  ++i )
		summe[ i ] = 0 ;

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
			summe[ i ] += zahl.ziffern[ i ] ;

		// neuen Übertrag und Ziffer von summe[ i ] berechnen
		uebertrag = summe[ i ] / 10 ;
		summe[ i ] %= 10 ;
	}

	// Überzählige Nullen am Anfang der Zahl von der Dimension abziehen
	for ( int i = dimSumme - 1 ;  i > 0 && summe[ i ] == 0 ;  --i )
		--dimSumme ;

	delete[] this ->ziffern ;
	this ->ziffernanzahl = dimSumme ;
	this ->ziffern = summe ;
}

void natuerlicheZahl::multipliziere( natuerlicheZahl const& zahl )
{
	// wenn einer der beiden Faktoren gleich 0 ist, ist nichts zu berechnen: Es wird 0 zurückgegeben.
	if ( zahl == 0 )
		this ->operator=( 0 );

	// auch wenn einer der beiden Faktoren die 1 ist, ist nichts zu berechnen:
	// es wird jeweils die andere Zahl zurückgegeben.
	if ( this ->istGleich( natuerlicheZahl( 1 ) ) )
		this ->operator=( zahl ) ;
	else if ( zahl == 1 )
		return ;

	int nZiffernZahl1 = this ->ziffernanzahl ;
	int nZiffernZahl2 = zahl.ziffernanzahl ;

	// maximale Ziffernlänge des Produktes von zahl1 und zahl2 berechnen.
	// für die Dimension des Produkt-Arrays wird noch 1 addiert, da der letzte Arrayeintrag das ENDE-Zeichen sein muss
	int dimProdukt = nZiffernZahl1 + nZiffernZahl2 + 1 ;

	// Array für das Produkt allozieren und mit dem ENDE-Zeichen initialisieren
	//int* produkt = new int[ dimProdukt ] ;
	//for ( int i = 0 ;  i < dimProdukt ;  ++i )
	//	produkt[ i ] = ENDE ;

	natuerlicheZahl produkt ;
	produkt.ziffernanzahl = dimProdukt ;
	delete[] produkt.ziffern ;
	produkt.ziffern = new int[ dimProdukt ] ;
	for ( int i = 0 ;  i < dimProdukt ;  ++i )
		produkt.ziffern[ i ] = 0 ;



	// Array für Zwischenergebnisse allozieren und mit dem ENDE-Zeichen initialisieren
	//int* zwischenergebnis = new int[ dimProdukt ] ;
	//for ( int i = 0 ;  i < dimProdukt ;  ++i )
	//	zwischenergebnis[ i ] = ENDE ;

	natuerlicheZahl zwischenergebnis ;
	zwischenergebnis.ziffernanzahl = dimProdukt ;
	delete[] zwischenergebnis.ziffern ;
	zwischenergebnis.ziffern = new int[ dimProdukt ] ;
	for ( int i = 0 ;  i < dimProdukt ;  ++i )
		zwischenergebnis.ziffern[ i ] = 0 ;

	// die Multiplikation beider Zahlen erfolgt nach dem bekannten Algorithmus aus der Schule:
	// 1.) beide Zahlen werden nebeneinander geschrieben, n = 1, m = 1, Übertrag = 0
	// 2.) die n-te Ziffer der ersten Zahl wird mit der m-ten Ziffer der zweiten Zahl multipliziert
	//	2.1) addiere zum Ergebnis den Übertrag aus dem letzten Durchgang von 2.)
	//	2.1) schreibe die erste Ziffer des Ergebnisses unter die (n+m-1)-te Ziffer der zweiten Zahl, notiere die
	//		 zweite Ziffer als Übertrag
	// 3.) führe 2.) so oft aus, wie die erste Zahl Ziffern hat, zähle dabei n hoch
	// 4.) setze n = 1, führe 2.) und 3.) so oft aus, wie die zweite Zahl Ziffern hat, zähle dabei m hoch
	//	   und schreibe die Ziffern jeweils eine Zeile tiefer
	// 5.) addiere alle Zahlen, die in den Zeilen untereinander stehen zum Endergebnis.
	//	   Dabei zählt eine freie Stelle als 0.
	//
	// Der einzige Unterschied im Code ist, dass jeweils zwei Zahlen, die untereinander stehen, direkt addiert werden
	// und jede zusätzliche Zahl wieder zu diesem Ergebnis addiert wird usw., was Arbeitsspeicher spart und
	// einen eventuellen Überlauf (bei wirklich riesigen Summanden) verhindert.

	for ( int j = 0 ;  j < nZiffernZahl2 ;  ++j )
	{
		// Nullen setzen
		for ( int i = 0 ;  i < j ;  ++i )
			zwischenergebnis.ziffern[ i ] = 0 ;

		int uebertrag = 0 ;

		for ( int i = 0 ;  i < nZiffernZahl1 ;  ++i )
		{
			zwischenergebnis.ziffern[ i + j ] = ( this ->ziffern[ i ] * zahl.ziffern[ j ] + uebertrag ) % 10 ;
			uebertrag = ( this ->ziffern[ i ] * zahl.ziffern[ j ] + uebertrag ) / 10 ;
		}
	
		if ( uebertrag != 0 )
			zwischenergebnis.ziffern[ nZiffernZahl1 + j ] = uebertrag ;

		produkt.addiere( zwischenergebnis ) ;
	}
	
	this ->operator=( produkt ) ;

}


// gibt die Zahl auf cout aus
void natuerlicheZahl::ausgeben()
{
	for ( int i = 0 ;  i < this ->ziffernanzahl ;  ++i )
		cout << this ->ziffern[ this ->ziffernanzahl - i - 1 ] ;
}


// Operatoren
natuerlicheZahl& natuerlicheZahl::operator=( natuerlicheZahl const& rhs ) 
{
	if ( this != &rhs )
	{
		delete[] this ->ziffern ;

		// kopiere elementweise
		this ->ziffern = new int[ rhs.ziffernanzahl ] ;
		for ( int i = 0 ;  i < rhs.ziffernanzahl ;  ++i )
			this ->ziffern[ i ] = rhs.ziffern[ i ] ;

		this ->ziffernanzahl = rhs.ziffernanzahl ;
	}

	return *this ;
}

natuerlicheZahl& natuerlicheZahl::operator=( unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;

	delete[] this ->ziffern ;

	// kopiere elementweise
	this ->ziffern = new int[ kopie_rhs.ziffernanzahl ] ;
	for ( int i = 0 ;  i < kopie_rhs.ziffernanzahl ;  ++i )
		this ->ziffern[ i ] = kopie_rhs.ziffern[ i ] ;

	this ->ziffernanzahl = kopie_rhs.ziffernanzahl ;

	return *this ;
}


// Vergleichsoperationen
bool natuerlicheZahl::istKleiner( natuerlicheZahl const& zahl )
{
	int nZiffernZahl1 = this ->ziffernanzahl ;
	int nZiffernZahl2 = zahl.ziffernanzahl ;

	if ( nZiffernZahl1 > nZiffernZahl2 )
		return false ; // zahl1 hat mehr Ziffern als zahl2 => zahl1 > zahl2
	else if ( nZiffernZahl1 < nZiffernZahl2 )
		return true ; // zahl1 hat weniger Ziffern als zahl2 => zahl1 < zahl2
	else // zahl1 hat genauso viele Ziffern wie zahl2 => weitere Überprüfung notwendig
	{
		// von der vordersten Ziffer beider Zahlen ausgehend die Ziffern nacheinander miteinander vergleichen
		for ( int i = nZiffernZahl1 - 1 ;  i >= 0 ;  --i )
		{
			if ( this ->ziffern[ i ] > zahl.ziffern[ i ] )
				return false ;
			else if ( this ->ziffern[ i ] < zahl.ziffern[ i ] )
				return true ;
		}

		return false ; // alle Ziffern von zahl1 und zahl2 stimmen überein => zahl1 = zahl2
	}
}

bool natuerlicheZahl::istKleinerGleich( natuerlicheZahl const& zahl )
{
	int nZiffernZahl1 = this ->ziffernanzahl ;
	int nZiffernZahl2 = zahl.ziffernanzahl ;

	if ( nZiffernZahl1 > nZiffernZahl2 )
		return false ; // zahl1 hat mehr Ziffern als zahl2 => zahl1 > zahl2
	else if ( nZiffernZahl1 < nZiffernZahl2 )
		return true ; // zahl1 hat weniger Ziffern als zahl2 => zahl1 < zahl2
	else // zahl1 hat genauso viele Ziffern wie zahl2 => weitere Überprüfung notwendig
	{
		// von der vordersten Ziffer beider Zahlen ausgehend die Ziffern nacheinander miteinander vergleichen
		for ( int i = nZiffernZahl1 - 1 ;  i >= 0 ;  --i )
		{
			if ( this ->ziffern[ i ] > zahl.ziffern[ i ] )
				return false ;
			else if ( this ->ziffern[ i ] < zahl.ziffern[ i ] )
				return true ;
		}

		return true ; // alle Ziffern von zahl1 und zahl2 stimmen überein => zahl1 = zahl2
	}
}

bool natuerlicheZahl::istGleich( natuerlicheZahl const& zahl )
{
	int nZiffernZahl1 = this ->ziffernanzahl ;
	int nZiffernZahl2 = zahl.ziffernanzahl ;

	if ( nZiffernZahl1 > nZiffernZahl2 )
		return false ; // zahl1 hat mehr Ziffern als zahl2 => zahl1 > zahl2
	else if ( nZiffernZahl1 < nZiffernZahl2 )
		return false ; // zahl1 hat weniger Ziffern als zahl2 => zahl1 < zahl2
	else // zahl1 hat genauso viele Ziffern wie zahl2 => weitere Überprüfung notwendig
	{
		// von der vordersten Ziffer beider Zahlen ausgehend die Ziffern nacheinander miteinander vergleichen
		for ( int i = nZiffernZahl1 - 1 ;  i >= 0 ;  --i )
		{
			if ( this ->ziffern[ i ] > zahl.ziffern[ i ] )
				return false ;
			else if ( this ->ziffern[ i ] < zahl.ziffern[ i ] )
				return false ;
		}

		return true ; // alle Ziffern von zahl1 und zahl2 stimmen überein => zahl1 = zahl2
	}
}






// Operatoren

natuerlicheZahl operator+( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	kopie_lhs.addiere( rhs ) ;
	return kopie_lhs ;
}

natuerlicheZahl operator+( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	kopie_rhs.addiere( lhs ) ;

	return kopie_rhs ;
}

natuerlicheZahl operator+( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	kopie_lhs.addiere( rhs ) ;

	return kopie_lhs ;		
}


natuerlicheZahl operator*( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	kopie_lhs.multipliziere( rhs ) ;
	return kopie_lhs ;
}

natuerlicheZahl operator*( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	kopie_rhs.multipliziere( lhs ) ;

	return kopie_rhs ;
}

natuerlicheZahl operator*( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	kopie_lhs.multipliziere( rhs ) ;

	return kopie_lhs ;	
}


natuerlicheZahl operator^( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl lhs_kopie( lhs ) ;

	if ( rhs == 0 )
		lhs_kopie = 1 ;
	else
	{
		for ( unsigned long long i = 1 ;  i < rhs ;  ++i )
			lhs_kopie.multipliziere( lhs ) ;
	}

	return lhs_kopie ;
}

// Vergleichsoperatoren

bool operator<( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	return kopie_lhs.istKleiner( rhs ) ;
}

bool operator<( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	return kopie_lhs.istKleiner( rhs ) ;		
}

bool operator<( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	natuerlicheZahl kopie_lhs( lhs ) ;

	return kopie_lhs.istKleiner( kopie_rhs ) ;	
}

bool operator==( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie( lhs ) ;
	return kopie.istGleich( rhs ) ;
}

bool operator==( unsigned long long lhs, natuerlicheZahl const& rhs ) 
{
	natuerlicheZahl kopie( lhs ) ;
	return kopie.istGleich( rhs ) ;
}

bool operator==( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	return kopie_rhs.istGleich( lhs ) ;	
}

bool operator>( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie( lhs ) ;
	return ( !kopie.istKleinerGleich( rhs ) ) ;
}

bool operator>( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie( lhs ) ;
	return ( !kopie.istKleinerGleich( rhs ) ) ;
}

bool operator>( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	natuerlicheZahl kopie_lhs( lhs ) ;

	return ( !kopie_lhs.istKleinerGleich( kopie_rhs ) ) ;	
}

bool operator!=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	return !( lhs == rhs ) ;
}

bool operator!=( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	return !( lhs == rhs ) ;
}

bool operator!=( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	return !( lhs == rhs ) ;
}

bool operator>=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	return ( kopie_rhs.istKleinerGleich( lhs ) ) ;
}

bool operator>=( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	natuerlicheZahl kopie_lhs( lhs ) ;
	return ( kopie_rhs.istKleinerGleich( kopie_lhs ) ) ;
}

bool operator>=( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	return ( kopie_rhs.istKleinerGleich( lhs ) ) ;
}

bool operator<=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	return kopie_lhs.istKleinerGleich( rhs ) ;
}

bool operator<=( unsigned long long lhs, natuerlicheZahl const& rhs )
{
	natuerlicheZahl kopie_lhs( lhs ) ;
	return kopie_lhs.istKleinerGleich( rhs ) ;
}

bool operator<=( natuerlicheZahl const& lhs, unsigned long long rhs )
{
	natuerlicheZahl kopie_rhs( rhs ) ;
	natuerlicheZahl kopie_lhs( lhs ) ;
	return kopie_lhs.istKleinerGleich( kopie_rhs ) ;
}