#include "primzahlen.h"



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

