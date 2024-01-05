#include "MRTBig.h"
// berechnet die Potenz n^e mod m, wobei auch sehr große n und e zugelassen sind
// verwendet dabei den Square & Multiply-Algorithmus mit einer Modifikation für den Modulo
BigInteger binModExponentiation( BigInteger basis, BigInteger exponent, BigInteger modul )
{
	BigFloat log2 = ttmath::Log< BigFloat >( exponent, 2 ) ;

	int binaerzahlZiffern = log2.ToInt() + 1 ;
	char* anweisungsfolge = new char[ binaerzahlZiffern ] ;
	
	BigInteger exponent_kopie = exponent ;

	// den Exponenten e nach der Modulo-Methode in eine Binärzahl umwandeln, dabei direkt die Anweisungsfolge
	// erstellen
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = ( exponent_kopie % 2 ).ToInt() ;
		if ( ziffer == 1 )
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'R' ; // R steht für QM, also Quadrieren und Multiplizieren
		else
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'S' ; // S steht für Q, also Quadrieren

		exponent_kopie /= 2 ;
	}

	BigInteger ergebnis = basis ;

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
BigInteger binExponentiation( BigInteger basis, BigInteger exponent )
{
	if ( exponent == 0 )
		return 1 ;
	
	BigFloat log2 = ttmath::Log< BigFloat >( exponent, 2 ) ;

	int binaerzahlZiffern = log2.ToInt() + 1 ;
	char* anweisungsfolge = new char[ binaerzahlZiffern ] ;

	BigInteger exponent_kopie = exponent ;

	// den Exponenten e nach der Modulo-Methode in eine Binärzahl umwandeln, dabei direkt die Anweisungsfolge
	// erstellen
	for ( int i = 0 ;  i < binaerzahlZiffern ;  ++i )
	{
		int ziffer = ( exponent_kopie % 2 ).ToInt() ;
		if ( ziffer == 1 )
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'R' ; // R steht für QM, also Quadrieren und Multiplizieren
		else
			anweisungsfolge[ binaerzahlZiffern - i - 1 ] = 'S' ; // S steht für Q, also Quadrieren

		exponent_kopie /= 2 ;
	}

	BigInteger ergebnis = basis ;

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

/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zurück, falls n als zusammengesetzt erkannt wird
// gibt false zurück, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( BigInteger a, BigInteger n )
{
	// finde s, d, so dass d ungerade ist und n - 1 = 2^s * d
	uint64 s = 0 ;
	BigInteger d = n - 1 ;
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


// gibt sicher zurück, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
BigInteger zeugen[ 7 ] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } ;
bool istPrim_MRD( BigInteger n )
{
	if ( n < 2 )
		return false ;

	if ( n <= 3 )
		return true ;

	if ( n % 2 == 0 )
		return false ;

	if ( !zeuge( zeugen[ 0 ], n ) )
		if ( !zeuge( zeugen[ 1 ], n ) )
			if ( !zeuge( zeugen[ 2 ], n ) )
				if ( !zeuge( zeugen[ 3 ], n ) )
					if ( !zeuge( zeugen[ 4 ], n ) )
						if ( !zeuge( zeugen[ 5 ], n ) )
							if ( !zeuge( zeugen[ 6 ], n ) )
								return true ;

	return false ;
}