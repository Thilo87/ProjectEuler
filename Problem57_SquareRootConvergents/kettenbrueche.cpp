#include "kettenbrueche.h"

// gibt den Zähler der n-ten Konvergente der regulären Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zurück
ttmath::Int< 100 > konvergente_p( vector< int > const& b, unsigned int n )
{
	ttmath::Int< 100 > pn = 0, pn_m1 = 1, pn_m2 = 0 ;

	unsigned int z = 0 ;
	for ( unsigned int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= b.size() )
			i = 1 ;

		pn = pn_m1 * b.at( i ) + pn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		pn_m2 = pn_m1 ;
		pn_m1 = pn ;
	}

	return pn ;
}

// gibt den Nenner der n-ten Konvergente der regulären Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zurück
ttmath::Int< 100 > konvergente_q( vector< int > const& b, unsigned int n )
{
	ttmath::Int< 100 > qn = 0, qn_m1 = 0, qn_m2 = 1 ;

	unsigned int z = 0 ;
	for ( unsigned int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= b.size() )
			i = 1 ;

		qn = qn_m1 * b.at( i ) + qn_m2 ; // q_n = b_n * q_(n-1) + q_(n-2)

		qn_m2 = qn_m1 ;
		qn_m1 = qn ;
	}

	return qn ;
}

// gibt die Teilnenner der Kettenbruchentwicklung von sqrt( n ) zurück. Dabei wird bei nicht-quadratischen Zahlen
// die Periode nur einmal angegeben, womit die Periodenlänge gleich die Länge des Vectors - 1 ist.
vector< int > kettenbruch_sqrt( unsigned int n )
{
	vector< int > teilnenner ;

	double sqrt_n = sqrt( double( n ) ) ;
	int a0 = int( floor( sqrt_n ) ) ;

	int p_alt = 1 ;
	int a_alt = a0 ;
	int q_alt = -a_alt ;
	teilnenner.push_back( a_alt ) ;

	if ( sqrt_n != int( sqrt_n ) ) // wenn n keine Quadratzahl ist
	{
		int a_neu, p_neu, q_neu ;
		do
		{
			q_alt *= -1 ;
			p_neu = ( n - q_alt * q_alt ) / p_alt ;
			a_neu = int( floor( ( sqrt_n + q_alt ) / p_neu ) ) ;
			q_neu = q_alt - a_neu * p_neu ;

			teilnenner.push_back( a_neu ) ;

			p_alt = p_neu ;
			a_alt = a_neu ;
			q_alt = q_neu ;
		}
		while ( a_neu != 2 * a0 ) ;		
	}

	return teilnenner ;
}