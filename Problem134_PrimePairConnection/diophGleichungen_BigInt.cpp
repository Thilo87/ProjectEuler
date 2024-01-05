#include "diophGleichungen_BigInt.h"

// steinscher Algorithmus um den ggT( a, b ) zu berechnen
bint ggT_Stein( bint a, bint b )
{
	a = ttmath::Abs( a ) ;
	b = ttmath::Abs( b ) ;

	if ( a == 0 )
		return b ;

	bint k = 0 ;
	while ( a % 2 == 0 && b % 2 == 0 )
	{
		a /= 2 ;
		b /= 2 ;
		++k ;
	}
	
	bint t ;
	if ( a % 2 == 1 )
		t = -b ;
	else
		t = a ;

	while ( t != 0 )
	{
		while ( t % 2 == 0 )
			t /= 2 ;
		if ( t > 0 )
			a = t ;
		else
			b = -t ;

		t = a - b ;
	}

	bint potenz = 2 ;
	potenz.Pow( k ) ;
	return a * potenz ;
}

// gibt ein Tripel ( ggT( a, b ), s, t ) zurück, wobei ggT( a, b ) = s * a + t * b
std::tuple< bint, bint, bint > erwEuklidAlgo( bint a, bint b )
{
	bint s = 0, t = 1, r = ttmath::Abs( b ) ;
	bint s_alt = 1, t_alt = 0, r_alt = ttmath::Abs( a ) ;

	while ( r != 0 )
	{
		bint tmp ;
		bint q = r_alt / r ;

		tmp = r ;
		r = r_alt - q * r ;
		r_alt = tmp ;

		tmp = s ;
		s = s_alt - q * s ;
		s_alt = tmp ;

		tmp = t ;
		t = t_alt - q * t ;
		t_alt = tmp ;
	}

	// Vorzeichenkorrektur
	if ( b < 0 )
		t_alt *= -1 ;
	if ( a < 0 )
		s_alt *= -1 ;

	return std::make_tuple( r_alt, s_alt, t_alt ) ;
}

// gibt die Lösungsmenge der linearen Kongruenz ax kongruent c ( mod m ) als
// 2-Tupel ( x0, v ) zurück, wobei die Lösungsmenge L = { x0 + v * n | n ganze Zahl } ist.
std::tuple< bint, bint > lineareKongruenz( bint a, bint c, bint m )
{
	a = ttmath::Abs( a ) ;  c = ttmath::Abs( c ) ;  m = ttmath::Abs( m ) ;

	/*
		Die Berechnung der Lösungsmenge von ax kongruent c ( mod m ) erfolgt durch die Lösung der 
		linearen diophantischen Gleichung ax + my = c.
	*/

	// den erweiterten euklidischen Algorithmus anwenden, um die Lösungsmenge für
	// ggT( a, m ) = s * a + t * m zu erhalten
	std::tuple< bint, bint, bint > erg = erwEuklidAlgo( a, m ) ;

	bint g = std::get< 0 >( erg ) ;
	bint x0 = ( std::get< 1 >( erg ) * c ) / g, v = m / g ;

	return std::make_tuple( x0, v ) ;
}

// gibt die Lösungsmenge der linearen diophantischen Gleichung ax + by = c als Tupel
// ( x_speziell, v_x, y_speziell, v_y ) zurück. Dann ist die Lösungsmenge
// L = { ( x_speziell + v_x * n, y_speziell + v_y * n ) | n ganze Zahl }
std::tuple< bint, bint, bint, bint > diophGleichung( bint a, bint b, bint c )
{
	std::tuple< bint, bint, bint > erg = erwEuklidAlgo( a, b ) ;

	bint ggTab = std::get< 0 >( erg ), s = std::get< 1 >( erg ), t = std::get< 2 >( erg ) ;

	bint x_speziell = s * ( c / ggTab ) ;
	bint y_speziell = t * ( c / ggTab ) ;
	bint v_x = b / ggTab, v_y = -( a / ggTab ) ;

	return std::make_tuple( x_speziell, v_x, y_speziell, v_y ) ;
}