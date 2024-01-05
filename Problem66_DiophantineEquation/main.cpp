/*

Consider quadratic Diophantine equations of the form:

x2 – Dy2 = 1

For example, when D=13, the minimal solution in x is 6492 – 13×1802 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

32 – 2×22 = 1
22 – 3×12 = 1
92 – 5×42 = 1
52 – 6×22 = 1
82 – 7×32 = 1

Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

*/


#include <iostream>
#include <vector>
#include "natuerlicheZahl.h"
using namespace std ;

// gibt den Zaehler der n-ten Näherung des Kettenbruches mit den Teilnennern teilnenner zurück
natuerlicheZahl naeherung_zaehler( vector< int > const& teilnenner, int n )
{
	natuerlicheZahl pn, pn_m1( 1 ), pn_m2 ;

	int z = 0 ;
	for ( int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= teilnenner.size() )
			i = 1 ;

		natuerlicheZahl bn( teilnenner.at( i ) );

		pn = bn * pn_m1 + pn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		pn_m2 = pn_m1 ;
		pn_m1 = pn ;
	}

	return pn ;
}

// gibt den Nenner der n-ten Näherung des Kettenbruches mit den Teilnennern teilnenner zurück
natuerlicheZahl naeherung_nenner( vector< int > const& teilnenner, int n )
{
	natuerlicheZahl qn, qn_m1, qn_m2( 1 ) ;

	int z = 0 ;
	for ( int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= teilnenner.size() )
			i = 1 ;

		natuerlicheZahl bn( teilnenner.at( i ) );

		qn = bn * qn_m1 + qn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		qn_m2 = qn_m1 ;
		qn_m1 = qn ;
	}

	return qn ;
}

// gibt die Teilnenner der Kettenbruchentwicklung von sqrt( n ) zurück. Die Periodenlänge beträgt dann
// kettenbruch_sqrt( int n ).size() - 1
vector< int > kettenbruch_sqrt( int n )
{
	vector< int > teilnenner ;

	double sqrt_n = sqrt( double( n ) ) ;
	int a0 = floor( sqrt_n ) ;

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
			a_neu = floor( ( sqrt_n + q_alt ) / p_neu ) ;
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

int main ()
{
	int const D_MAX = 1000 ;
	
	natuerlicheZahl max_x ;
	int max_D = 0 ;

	for ( int D = 2 ;  D <= D_MAX ;  ( D == 2 ) ? ++D : D += 2 )
		if ( sqrt( double( D ) ) != int( sqrt( double( D ) ) ) ) // es gibt keine Lösungen für x^2 - Dy^2 = 1, wenn
																 // D eine Quadratzahl ist
		{
			vector< int > teilnenner = kettenbruch_sqrt( D ) ;

			for ( int k = 1 ;  k <= 10 ;  ++k )
			{
				natuerlicheZahl z = naeherung_zaehler( teilnenner, ( teilnenner.size() - 1 ) * k ) ;
				natuerlicheZahl n = naeherung_nenner( teilnenner, ( teilnenner.size() - 1 ) * k ) ;

				if ( ( z * z ) == D * ( n * n ) + 1 )
				{
					if ( z > max_x )
					{
						max_x = z ;
						max_D = D ;
					}

					break ;
				}
			}
		}

		cout << max_D << endl ;

	return 0 ;
}