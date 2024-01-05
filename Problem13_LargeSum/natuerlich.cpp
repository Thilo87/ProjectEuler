#include "natuerlich.h"


// Ende-Zeichen für Ziffernfolge im natuerlich-Format
int const ENDE     = -1 ;

// max. Anzahl Ziffern in der Textausgabe
int const MAX_TEXT = 10000 ;

// 0 und 1 im natuerlich-Format
int const dieNull[] = { 0, ENDE } ;
int const dieEins[] = { 1, ENDE } ;

// gib die Anzahl signifikanter Ziffern von zahl zurück
int laenge ( int const zahl[] )
{
	int n = 0 ;

	while ( zahl[ n ] != ENDE )
		++n ;

	return n ;
}


/***  Level 1  ***/

// wandle Text in eine neue Zahl um
int* zuZahl ( char const text[] )
{
	int nZiffernText = 0 ;
	
	// Anzahl der Ziffern der Zahl in text[] ermitteln
	while ( text [ nZiffernText ] != '\0' )
		++nZiffernText ;

	// +1, weil das letzte Zeichen des dynamischen Arrays das ENDE-Zeichen sein muss
	int dimZahl = nZiffernText + 1 ;

	// dynamisches Array für die Zahl allozieren
	int* zahl = new int[ dimZahl ] ;

	// text[] in das natuerlich-Format umwandeln
	for ( int i = 0 ;  i < dimZahl - 1 ;  ++i )
		zahl[ i ] = text[ dimZahl - i - 2 ] - '0' ;

	// ENDE-Zeichen setzen
	zahl[ dimZahl - 1 ] = ENDE ;

	return zahl ;
}  // zuZahl()


// wandle Zahl in statischen Text um
// Achtung: der Wert ist nur stabil bis zum nächsten Aufruf
char const* zuText ( int const zahl[] )
{
	// Dimension von zahl[] ermitteln
	int dimZahl = laenge( zahl ) + 1 ;

	static char text[ MAX_TEXT ] = { 0 } ;

	if ( dimZahl > MAX_TEXT )
	{
		cerr << "Fehler: Das Ergebnis hat mehr Ziffern als die Textausgabe zulaesst!" << endl ;
		return NULL ;
	}
	else
	{
		// zahl[] in das Textformat umwandeln
		for ( int i = 0 ;  i < dimZahl - 1 ;  ++i )
			text[ i ] = zahl[ dimZahl - i - 2 ] + '0' ;

		// Nullzeichen setzen
		text[ dimZahl - 1 ] = '\0' ;
	}
	
	return text ;
}  // zuText()


/***  Level 2  ***/

// addiere zahl1 + zahl2 zu einer neuen Zahl
int* addiere ( int const zahl1[], int const zahl2[] )
{
	int laengeZahl1 = laenge( zahl1 ) ;
	int laengeZahl2 = laenge( zahl2 ) ;

	// Die Summe zweier Zahlen hat maximal die Anzahl Ziffern: max( laenge( zahl1 ) , laenge( zahl2 ) ) + 1
	// Da an das Ende von der Summe beider Zahlen das ENDE-Zeichen gehört, muss die Dimension vom
	// dynamischen Array summe gleich max( laenge( zahl1 ) , laenge ( zahl2 ) ) + 2 sein.
	int dimSumme = max( laengeZahl1, laengeZahl2 ) + 2 ;

	// dynamisches Array für das Ergebnis der Addition allozieren
	int* summe = new int[ dimSumme ] ;

	// summe mit dem ENDE-Zeichen initialisieren
	for ( int i = 0 ;  i < dimSumme ;  ++i )
		summe[ i ] = ENDE ;


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
			summe[ i ] += zahl1[ i ] ;
		if ( i < laengeZahl2 )
			summe[ i ] += zahl2[ i ] ;

		// neuen Übertrag und Ziffer von summe[ i ] berechnen
		uebertrag = summe[ i ] / 10 ;
		summe[ i ] %= 10 ;
	}
	
	// wurde nicht die maximale Ziffernanzahl von summe erreicht, wurde summe[ dimSumme - 2 ] in der Schleife
	// auf 0 gesetzt. Diese wird hier auf das ENDE-Zeichen gesetzt.
	if ( summe[ dimSumme - 2 ] == 0 )
		summe[ dimSumme - 2 ] = ENDE ;

	return summe ;
}  // addiere()


// subtrahiere zahl1 - zahl2 zu einer neuen Zahl,
// gebe NULL zurück, wenn zahl1 < zahl2 ist
int* subtrahiere ( int const zahl1[], int const zahl2[] )
{
	// breche ab und gebe Fehlermeldung aus, wenn zahl1 < zahl2
	if ( vergleiche( zahl1, zahl2 ) == -1 )
	{
		cerr << "Fehler: Die zweite Zahl ist groesser als die erste und das Programm rechnet nur mit natuerlichen Zahlen!" << endl ;
		return NULL ;
	}



	int laengeZahl1 = laenge( zahl1 ) ;
	int laengeZahl2 = laenge( zahl2 ) ;

	// Die Differenz zweier Zahlen hat maximal die Anzahl Ziffern: max( laenge( zahl1 ) , laenge( zahl2 ) )
	// Da an das Ende von der Differenz beider Zahlen das ENDE-Zeichen gehört, muss die Dimension vom
	// dynamischen Array differenz gleich max( laenge( zahl1 ) , laenge ( zahl2 ) ) + 1 sein.
	int dimDifferenz = max( laengeZahl1, laengeZahl2 ) + 1 ;

	// dynamisches Array für das Ergebnis der Addition anlegen
	int* differenz = new int[ dimDifferenz ] ;

	// differenz mit dem ENDE-Zeichen initialisieren ( dadurch muss am Ende der
	// Funktion das ENDE-Zeichen nicht mehr gesetzt werden )
	for ( int i = 0 ;  i < dimDifferenz ;  ++i )
		differenz[ i ] = ENDE ;


	int uebertrag = 0 ;

	// die Bildung der Differenz zahl1 - zahl2 erfolgt nach der einfachsten Form der schriftlichen Subtraktion:
	// Beide Zahlen werden übereinander geschrieben, Ziffernweise wird die untere Ziffer ( + evtl. Übertrag ) von der
	// oberen Ziffer abgezogen. Wenn die obere Zahl kleiner als die untere Zahl ( + evtl. Übertrag ) ist, wird 10 addiert.
	// Das Ergebnis ist die jeweilige Ziffer der Differenz zahl1 - zahl2.
	for ( int i = 0 ;  i < dimDifferenz - 1 ;  ++i )
	{
		int untereZahl = uebertrag ; // untereZahl mit dem Übertrag initialisieren
		int obereZahl = 0 ;

		// zur unteren Zahl die jeweilige Ziffer addieren, sofern sie noch Ziffern hat. Da sie schon mit dem Übertrag
		// initialisiert wurde, muss dieser nicht addiert werden.
		// Die obere Zahl auf die jeweilige Ziffer setzen, sofern sie noch Ziffern hat
		if ( i < laengeZahl2 )
			untereZahl += zahl2[ i ] ;
		if ( i < laengeZahl1 )
			obereZahl = zahl1[ i ] ;


		uebertrag = 0 ;

		if ( obereZahl >= untereZahl )
			differenz[ i ] = obereZahl - untereZahl ;
		else
		{
			differenz[ i ] = obereZahl - untereZahl + 10 ;
			uebertrag = 1 ;
		}
	}
	
	// von der vordersten Ziffer ausgehend die Nullen durch das ENDE-Zeichen ersetzen,
	// um keine unnötigen Nullen vor den Ziffern der Differenz-Zahl stehen zu haben
	for ( int i = dimDifferenz - 2 ;  i > 0 ;  --i )
		if ( differenz[ i ] == 0 )
			differenz[ i ] = ENDE ;
		else
			break ; // die Schleife abbrechen, sobald die erste Ziffer, die nicht 0 ist, erreicht wurde

	return differenz ;
}  // subtrahiere()


/***  Level 3  ***/

// gebe neue Zahl mit demselben Wert wie zahl zurück
static
int* kopiere ( int const zahl[] )
{
	int dimKopie = laenge( zahl ) + 1 ; // +1, wegen dem ENDE-Zeichen
	int* kopie = new int[ dimKopie ] ;

	// Kopie erstellen
	for ( int i = 0 ;  i < dimKopie ;  ++i )
		kopie[ i ] = zahl[ i ] ;

	// ENDE-Zeichen setzen
	kopie[ dimKopie - 1 ] = ENDE ;

	return kopie ;
}


// vergleiche zahl1 und zahl2 nach Größe
// Antwort: -1, falls zahl1 <  zahl2
//           0, falls zahl1 == zahl2
//           1, falls zahl1 >  zahl2
int vergleiche ( int const zahl1[], int const zahl2[] )
{
	int nZiffernZahl1 = laenge( zahl1 ) ;
	int nZiffernZahl2 = laenge( zahl2 ) ;

	if ( nZiffernZahl1 > nZiffernZahl2 )
		return 1 ; // zahl1 hat mehr Ziffern als zahl2 => zahl1 > zahl2
	else if ( nZiffernZahl1 < nZiffernZahl2 )
		return -1 ; // zahl1 hat weniger Ziffern als zahl2 => zahl1 < zahl2
	else // zahl1 hat genauso viele Ziffern wie zahl2 => weitere Überprüfung notwendig
	{
		// von der vordersten Ziffer beider Zahlen ausgehend die Ziffern nacheinander miteinander vergleichen
		for ( int i = nZiffernZahl1 - 1 ;  i >= 0 ;  --i )
		{
			if ( zahl1[ i ] > zahl2[ i ] )
				return 1 ;
			else if ( zahl1[ i ] < zahl2[ i ] )
				return -1 ;
		}

		return 0 ; // alle Ziffern von zahl1 und zahl2 stimmen überein => zahl1 = zahl2
	}
}  // vergleiche()


// gib ggT( zahl1, zahl2 ) als neue Zahl zurück
int* ggT ( int const zahl1[], int const zahl2[] )
{
	if ( vergleiche( zahl1, dieNull ) == 0 || vergleiche( zahl2, dieNull ) == 0 )
	{
		cerr << "Fehler: Keine der beiden Zahlen darf 0 sein!" << endl ;
		return NULL ;
	}


	int* m = kopiere( zahl1 ) ;
	int* n = kopiere( zahl2 ) ;

	while ( true )
	{
		// vergleich: 0,  wenn m == n
		//			  1,  wenn m > n
		//			  -1, wenn m < n
		int vergleich = vergleiche( m, n ) ;
		
		if ( vergleich != 0 ) // wenn m != n
		{
			if ( vergleich == 1 ) // wenn m > n
			{
				int* temp = subtrahiere( m, n ) ;
				delete[] m ;
				m = temp ;
			}
			else
			{
				int* temp = subtrahiere( n, m ) ;
				delete[] n ;
				n = temp ;
			}
		}
		else // Schleife abbrechen, wenn m == n
			break ;
	}
	
	delete[] n ;

	return m ;
}  // ggT()


/***  Level 4 (optional)  ***/

// multipliziere zahl1 * zahl2 zu einer neuen Zahl
int* multipliziere ( int const zahl1[], int const zahl2[] )
{
	// wenn einer der beiden Faktoren gleich 0 ist, ist nichts zu berechnen: Es wird 0 zurückgegeben.
	if ( vergleiche( zahl1, dieNull ) == 0 || vergleiche( zahl2, dieNull ) == 0 )
		return kopiere( dieNull ) ;

	// auch wenn einer der beiden Faktoren die 1 ist, ist nichts zu berechnen:
	// es wird jeweils die andere Zahl zurückgegeben.
	if ( vergleiche( zahl1, dieEins ) == 0 )
		return kopiere( zahl2 ) ;
	else if ( vergleiche( zahl2, dieEins ) == 0 )
		return kopiere( zahl1 ) ;



	int nZiffernZahl1 = laenge( zahl1 ) ;
	int nZiffernZahl2 = laenge( zahl2 ) ;

	// maximale Ziffernlänge des Produktes von zahl1 und zahl2 berechnen.
	// für die Dimension des Produkt-Arrays wird noch 1 addiert, da der letzte Arrayeintrag das ENDE-Zeichen sein muss
	int dimProdukt = nZiffernZahl1 + nZiffernZahl2 + 1 ;

	// Array für das Produkt allozieren und mit dem ENDE-Zeichen initialisieren
	int* produkt = new int[ dimProdukt ] ;
	for ( int i = 0 ;  i < dimProdukt ;  ++i )
		produkt[ i ] = ENDE ;

	// Array für Zwischenergebnisse allozieren und mit dem ENDE-Zeichen initialisieren
	int* zwischenergebnis = new int[ dimProdukt ] ;
	for ( int i = 0 ;  i < dimProdukt ;  ++i )
		zwischenergebnis[ i ] = ENDE ;

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
			zwischenergebnis[ i ] = 0 ;

		int uebertrag = 0 ;

		for ( int i = 0 ;  i < nZiffernZahl1 ;  ++i )
		{
			zwischenergebnis[ i + j ] = ( zahl1[ i ] * zahl2[ j ] + uebertrag ) % 10 ;
			uebertrag = ( zahl1[ i ] * zahl2[ j ] + uebertrag ) / 10 ;
		}
	
		if ( uebertrag != 0 )
			zwischenergebnis[ nZiffernZahl1 + j ] = uebertrag ;

		int* temp = produkt ;
		produkt = addiere( zwischenergebnis, produkt ) ;
		delete[] temp ;
	}

	// Speicher freigeben
	delete[] zwischenergebnis ;
	
	return produkt ;
}  // multipliziere()


// berechne Potenz zahl hoch n in eine neue Zahl,
// gib NULL zurück, wenn Exponent negativ ist
int* potenz ( int const zahl[], int n )
{
	int* ergebnis = NULL ;

	if ( n < 0 )
	{
		cerr << "Fehler: Exponent darf nicht negativ sein!" << endl ;
		return NULL ;
	}

	// ergebnis auf 1 setzen, falls der Exponent n gleich 0 ist und ergebnis auf zahl setzen,
	// falls der Exponent n gleich 1 ist. Wenn der Exponent n > 1 ist, ergebnis auf die n-te Potenz von zahl setzen
	if ( n == 0 )
		ergebnis = kopiere( dieEins ) ;
	else if ( n == 1 )
		ergebnis = kopiere( zahl ) ;
	else
	{
		ergebnis = kopiere( zahl ) ;

		// (n-1)-mal ergebnis mit zahl multiplizieren
		for ( ;  n > 1 ;  --n )
			{
				int* temp = ergebnis ;
				ergebnis = multipliziere( ergebnis, zahl ) ;
				delete[] temp ;
			}
	}

	return ergebnis ;
}  // potenz()
