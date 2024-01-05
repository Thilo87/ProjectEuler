#include "primzahlen.h"


// erstellt alle Werte von phi( n ) bis zur Grenze MAX ( SEHR SCHNELL! )
vector< int > eulerschePhiFunktion( int const MAX )
{
	vector< int > phi( MAX + 1, 0 ) ;
	for ( int i = 0 ;  i < MAX + 1 ;  ++i )
		phi.at( i ) = i ;

	for ( int i = 2 ;  i < MAX + 1  ;  ++i )
		if ( phi.at( i ) == i )
			for ( unsigned int j = i ;  j < MAX + 1 ;  j += i )
				phi.at( j ) -= phi.at( j ) / i ;

	return phi ;
}

// gibt ein bool-Array zurück, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( unsigned int n )
{
	bool* istPrim = new bool[ n + 1 ] ;

	// alle Zahlen von 0 bis n sind potenzielle Primzahlen
	for ( unsigned int i = 0 ;  i < n + 1 ;  ++i )
		istPrim[ i ] = true ;

	// 1 und 0 sind per Definition keine Primzahlen
	istPrim[ 0 ] = false ;
	istPrim[ 1 ] = false ;

	// gehe alle Zahlen von 2 bis inklusive sqrt( n + 1 ) durch, ob sie als prim markiert sind
	for ( int i = 2 ;  i <= sqrt( double( n + 1 ) ) ;  ++i )
	{
		if ( istPrim[ i ] )
			// markiere alle Vielfachen von der Primzahl i, beginnend mit i^2, als nicht prim
			for ( unsigned int j = i * i ;  j < n + 1 ;  j += i )
				istPrim[ j ] = false ;
	}

	return istPrim ;
}

// gibt in einem Vector die Primzahlen, die von 2 bis n vorkommen, zurück
// verwendet dabei das Sieb des Eratosthenes
vector< int > primzahlliste( unsigned int n )
{
	bool* istPrim = siebEratosthenes( n ) ;

	vector< int > liste ;
	for ( unsigned int i = 2 ;  i <= n ;  ++i )
		if ( istPrim[ i ] )
			liste.push_back( i ) ;

	delete[] istPrim ;

	return liste ;
}



// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schließlich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n )
{
	if ( n == 1 )
		return 1 ;
	if ( n == 0 )
		return -1 ;

	int wurzel_n = int( sqrt( double( n ) ) ) ;

	// mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ) + 1 erstellen
	bool* istPrim = siebEratosthenes( wurzel_n + 1 ) ;

	// dynamisches Array für die Exponenten der Primfaktoren allozieren
	int* exponenten = new int[ wurzel_n + 1 ] ;
	for ( int i = 0 ;  i < wurzel_n + 1 ;  ++i )
		exponenten[ i ] = 0 ;


	int teiler = 1 ; // die Zahl n selber ist schon inbegriffen

	int i = 2 ;
	while ( i <= wurzel_n )
	{
		// alle Zahlen von 2 bis < sqrt( n ) auf ihre Primzahleigenschaft testen
		if ( istPrim[ i ] )
		{
			// Exponent des vermeintlichen Primfaktors bestimmen
			while ( n % i == 0 )
			{
				++exponenten[ i ] ;
				n /= i ;
			}

			// Teileranzahl erhöhen
			teiler *= ( exponenten[ i ] + 1 ) ;

			// n ist bereits in alle seine Primfaktoren zerlegt
			if ( n == 1 )
				break ;

			// Ausnahme: Jede Primzahl bis auf die 2 ist ungerade und das Inkrement in der Schleife ist i += 2,
			// also muss, wenn i == 2, die 3 in der nächsten Iteration geprüft werden
			if ( i == 2 )
				--i ;
		}

		i += 2 ;
	}

	delete[] exponenten ;
	delete[] istPrim ;

	if ( n != 1 )
		teiler *= 2 ;

	return teiler ;
}

unsigned long long teilersumme( unsigned long long n )
{
	if ( n == 1 )
		return 1 ;
	if ( n == 0 )
		return -1 ;

	int wurzel_n = int( sqrt( double( n ) ) ) ;

	// mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ) + 1 erstellen
	bool* istPrim = siebEratosthenes( wurzel_n + 1 ) ;

	// dynamisches Array für die Exponenten der Primfaktoren allozieren
	int* exponenten = new int[ n + 1 ] ;
	for ( int i = 0 ;  i < n + 1 ;  ++i )
		exponenten[ i ] = 0 ;

	// wird später noch gebraucht
	unsigned long long alt_n = n ;

	int i = 2 ;
	while ( i <= wurzel_n )
	{
		// alle Zahlen von 2 bis < sqrt( n ) auf ihre Primzahleigenschaft testen
		if ( istPrim[ i ] )
		{
			// Exponent des vermeintlichen Primfaktors bestimmen
			while ( n % i == 0 )
			{
				++exponenten[ i ] ;
				n /= i ;
			}

			// n ist bereits in alle seine Primfaktoren zerlegt
			if ( n == 1 )
				break ;

			// Ausnahme: Jede Primzahl bis auf die 2 ist ungerade und das Inkrement in der Schleife ist i += 2,
			// also muss, wenn i == 2, die 3 in der nächsten Iteration geprüft werden
			if ( i == 2 )
				--i ;
		}

		i += 2 ;
	}
	
	if ( n != 1 )
		++exponenten[ n ] ;

	// Teilersumme bestimmen
	unsigned long long summe = 1 ;
	for ( int i = 0 ;  i <= alt_n ;  ++i )
	{
		unsigned long long exponentenSumme = 0 ;
		if ( exponenten[ i ] > 0 )
			for ( int j = 0 ;  j <= exponenten[ i ] ;  ++j )
				exponentenSumme += pow( i, double( j ) ) ;
		
		if ( exponentenSumme != 0 )
			summe *= exponentenSumme ;
	}
	
	delete[] exponenten ;
	delete[] istPrim ;

	return summe ;
}

unsigned long long echteTeilersumme( unsigned long long n )
{
	if ( n == 1 )
		return 1 ;
	if ( n == 0 )
		return -1 ;

	int wurzel_n = int( sqrt( double( n ) ) ) ;

	// mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ) + 1 erstellen
	bool* istPrim = siebEratosthenes( wurzel_n + 1 ) ;

	// dynamisches Array für die Exponenten der Primfaktoren allozieren
	int* exponenten = new int[ n + 1 ] ;
	for ( int i = 0 ;  i < n + 1 ;  ++i )
		exponenten[ i ] = 0 ;

	// wird später noch gebraucht
	unsigned long long alt_n = n ;

	int i = 2 ;
	while ( i <= wurzel_n )
	{
		// alle Zahlen von 2 bis < sqrt( n ) auf ihre Primzahleigenschaft testen
		if ( istPrim[ i ] )
		{
			// Exponent des vermeintlichen Primfaktors bestimmen
			while ( n % i == 0 )
			{
				++exponenten[ i ] ;
				n /= i ;
			}

			// n ist bereits in alle seine Primfaktoren zerlegt
			if ( n == 1 )
				break ;

			// Ausnahme: Jede Primzahl bis auf die 2 ist ungerade und das Inkrement in der Schleife ist i += 2,
			// also muss, wenn i == 2, die 3 in der nächsten Iteration geprüft werden
			if ( i == 2 )
				--i ;
		}

		i += 2 ;
	}
	
	if ( n != 1 )
		++exponenten[ n ] ;

	// Teilersumme bestimmen
	unsigned long long summe = 1 ;
	for ( int i = 0 ;  i <= alt_n ;  ++i )
	{
		unsigned long long exponentenSumme = 0 ;
		if ( exponenten[ i ] > 0 )
			for ( int j = 0 ;  j <= exponenten[ i ] ;  ++j )
				exponentenSumme += pow( i, double( j ) ) ;
		
		if ( exponentenSumme != 0 )
			summe *= exponentenSumme ;
	}

	// ... ohne die Zahl n selber
	summe -= alt_n ;
	
	delete[] exponenten ;
	delete[] istPrim ;

	return summe ;
}




/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zurück, falls n als zusammengesetzt erkannt wird
// gibt false zurück, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( unsigned long long a, unsigned long long n )
{
	// finde s, d, so dass d ungerade ist und n - 1 = 2^s * d
	int s = 0, d = n - 1 ;
	for ( ;  d % 2 == 0 ;  ++s )
		d /= 2 ;


	if ( binModExponentiation( a, d, n ) != 1 )
	{
		for ( int r = 0 ;  r < s ;  ++r )
			if ( binModExponentiation( a, binExponentiation( 2, r ) * d, n ) == n - 1 )
				return false ;

		return true ;
	}
	else
		return false ;
}

// berechnet die Potenz n^e mod m, wobei auch sehr große n und e zugelassen sind
// verwendet dabei den Square & Multiply-Algorithmus mit einer Modifikation für den Modulo
unsigned long long binModExponentiation( unsigned long long basis, unsigned long long exponent, unsigned int modul )
{
	int binaerzahlZiffern = int( log( double( exponent ) ) / log( 2. ) ) + 1 ;
	char* anweisungsfolge = new char[ binaerzahlZiffern ] ;


	unsigned long long exponent_kopie = exponent ;

	// den Exponenten e nach der Modulo-Methode in eine Binärzahl umwandeln, dabei direkt die Anweisungsfolge
	// erstellen
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = exponent_kopie % 2 ;
		if ( ziffer == 1 )
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'R' ; // R steht für QM, also Quadrieren und Multiplizieren
		else
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'S' ; // S steht für Q, also Quadrieren

		exponent_kopie /= 2 ;
	}

	unsigned long long ergebnis = basis ;

	// binäre Modulo-Exponentiation durchführen
	for ( int i = 1 ;  i < binaerzahlZiffern ;  ++i )
		if ( anweisungsfolge[ i ] == 'S' ) // Quadrieren
		{
			ergebnis *= ergebnis ;
			ergebnis %= modul ; // Änderung gegenüber reinem Square-&-Multiply-Algorithmus
		}
		else // Quadrieren und Multiplizieren
		{
			ergebnis *= ergebnis ;
			ergebnis *= basis ;
			ergebnis %= modul ; // Änderung gegenüber reinem Square-&-Multiply-Algorithmus
		}

	delete[] anweisungsfolge ;

	return ergebnis ;
}

// berechnet die Potenz n^e, wobei auch sehr große n und e zugelassen sind
unsigned long long binExponentiation( unsigned long long basis, unsigned long long exponent )
{
	if ( exponent == 0 )
		return 1 ;

	int binaerzahlZiffern = int( log( double( exponent ) ) / log( 2. ) ) + 1 ;
	char* anweisungsfolge = new char[ binaerzahlZiffern ] ;


	unsigned long long exponent_kopie = exponent ;

	// den Exponenten e nach der Modulo-Methode in eine Binärzahl umwandeln, dabei direkt die Anweisungsfolge
	// erstellen
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = exponent_kopie % 2 ;
		if ( ziffer == 1 )
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'R' ; // R steht für QM, also Quadrieren und Multiplizieren
		else
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'S' ; // S steht für Q, also Quadrieren

		exponent_kopie /= 2 ;
	}

	unsigned long long ergebnis = basis ;

	// binäre Modulo-Exponentiation durchführen
	for ( int i = 1 ;  i < binaerzahlZiffern ;  ++i )
		if ( anweisungsfolge[ i ] == 'S' ) // Quadrieren
			ergebnis *= ergebnis ;
		else // Quadrieren und Multiplizieren
		{
			ergebnis *= ergebnis ;
			ergebnis *= basis ;
		}

	delete[] anweisungsfolge ;

	return ergebnis ;
}

// gibt sicher zurück, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
bool istPrim_MRD( unsigned long long n )
{
	if ( n < 2 )
		return false ;

	if ( n <= 3 )
		return true ;

	if ( n % 2 == 0 )
		return false ;

	if ( n < 1373653 )
	{
		if ( !zeuge( 2, n ) )
			if ( !zeuge( 3, n ) )
				return true ;

		return false ;
	}

	if ( n < 9080191 )
	{
		if ( !zeuge( 31, n ) )
			if ( !zeuge( 73, n ) )
				return true ;

		return false ;
	}

	if ( n < 4759123141 )
	{
		if ( !zeuge( 2, n ) )
			if ( !zeuge( 7, n ) )
				if ( !zeuge( 61, n ) )
					return true ;

		return false ;
	}

	if ( n < 2152302898747 )
	{
		if ( !zeuge( 2, n ) )
			if ( !zeuge( 3, n ) )
				if ( !zeuge( 5, n ) )
					if ( !zeuge( 7, n ) )
						if ( !zeuge( 11, n ) )
							return true ;
		
		return false ;
	}

	if ( n < 3474749660383 )
	{
		if ( !zeuge( 2, n ) )
			if ( !zeuge( 3, n ) )
				if ( !zeuge( 5, n ) )
					if ( !zeuge( 7, n ) )
						if ( !zeuge( 11, n ) )
							if ( !zeuge( 13, n ) )
								return true ;

		return false ;
	}

	if ( n < 341550071728321 )
	{
		if ( !zeuge( 2, n ) )
			if ( !zeuge( 3, n ) )
				if ( !zeuge( 5, n ) )
					if ( !zeuge( 7, n ) )
						if ( !zeuge( 11, n ) )
							if ( !zeuge( 13, n ) )
								if ( !zeuge( 17, n ) )
									return true ;

		return false ;
	}

	cerr << "Fehler: Der deterministische Miller-Rabin-Primzahltest prueft nur Zahlen bis 341.550.071.728.320" << endl ;

	return false ;
}


// gibt die Anzahl der zu n teilerfremden Zahlen <= n zurück
// es ist phi( m * n ) = phi( m ) * phi( n )
unsigned long long eulerschePhiFunktion( unsigned long long n )
{
	if ( n == 0 )
		return 0 ;

	if ( n <= 2 )
		return 1 ;

	if ( istPrim_MRD( n ) ) // zu einer Primzahl p gibt es p - 1 teilerfremde Zahlen
		return n - 1 ;


	unsigned long long teilerfremdeZahlen = n ;

	if ( n % 2 == 0 )
		teilerfremdeZahlen -= teilerfremdeZahlen / 2 ;

	// das Sieb ist hier besser geeignet als der Miller-Rabin-Test, da alle Primzahlen von 0 bis max. n
	// durchgegangen werden müssen, ob sie Teiler der Zahl n sind
	bool* istPrim = siebEratosthenes( n ) ;

	for ( int p = 3 ;  p <= n ;  p += 2 )
		if ( istPrim[ p ] )
			if ( n % p == 0 )
			{
				teilerfremdeZahlen -= teilerfremdeZahlen / p ;

				while ( n % p == 0 )
					n /= p ;
			}

	return teilerfremdeZahlen ;
}

// gibt die Anzahl der zu n teilerfremden Zahlen <= n zurück
// es ist phi( m * n ) = phi( m ) * phi( n )
// dabei wird das Sieb des Eratosthenes verwendet. Bei vielen Aufrufen der Phi-Funktion sollte
// man besser eine istPrim-Liste erstellen und diese an die Funktion weitergeben, damit sie
// nicht jedes mal neu erstellt werden muss
unsigned long long eulerschePhiFunktion( unsigned long long n, bool const* istPrim )
{
	if ( n == 0 )
		return 0 ;

	if ( n <= 2 )
		return 1 ;

	if ( istPrim[ n ] ) // zu einer Primzahl p gibt es p - 1 teilerfremde Zahlen
		return n - 1 ;


	unsigned long long teilerfremdeZahlen = n ;

	if ( n % 2 == 0 )
		teilerfremdeZahlen -= teilerfremdeZahlen / 2 ;

	for ( int p = 3 ;  p <= n ;  p += 2 )
		if ( istPrim[ p ] )
			if ( n % p == 0 )
			{
				teilerfremdeZahlen -= teilerfremdeZahlen / p ;

				while ( n % p == 0 )
					n /= p ;
			}

	return teilerfremdeZahlen ;
}