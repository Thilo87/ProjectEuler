/*

It is well known that if the square root of a natural number is not an integer,
then it is irrational. The decimal expansion of such square roots is infinite without
any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of the
first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital
sums of the first one hundred decimal digits for all the irrational square roots.

*/

#include <iostream>
#include <vector>
#include "ttmath\ttmath.h"
using namespace std ;

// gibt den Zaehler der n-ten Näherung des Kettenbruches mit den Teilnennern teilnenner zurück
ttmath::Int< 100 > naeherung_zaehler( vector< int > const& teilnenner, int n )
{
	ttmath::Int< 100 > pn = 0, pn_m1 = 1, pn_m2 = 0 ;

	int z = 0 ;
	for ( int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= teilnenner.size() )
			i = 1 ;

		pn = pn_m1 * teilnenner.at( i ) + pn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		pn_m2 = pn_m1 ;
		pn_m1 = pn ;
	}

	return pn ;
}

// gibt den Nenner der n-ten Näherung des Kettenbruches mit den Teilnennern teilnenner zurück
ttmath::Int< 100 > naeherung_nenner( vector< int > const& teilnenner, int n )
{
	ttmath::Int< 100 > qn = 0, qn_m1 = 0, qn_m2 = 1 ;

	int z = 0 ;
	for ( int i = 0 ;  z < n ;  ++i, ++z )
	{
		if ( i >= teilnenner.size() )
			i = 1 ;

		qn = qn_m1 * teilnenner.at( i ) + qn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

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
	int gesamtZiffernSumme = 0 ;

	for ( int j = 2 ;  j <= 100 ;  ++j )
	{
		if ( sqrt( double( j ) ) != floor( sqrt( double( j ) ) ) )
		{
			vector< int > teilnenner = kettenbruch_sqrt( j ) ;

			ttmath::Int< 100 > z = naeherung_zaehler( teilnenner, 190 ) ; // Zähler
			ttmath::Int< 100 > n = naeherung_nenner( teilnenner, 190 ) ; // Nenner

			ttmath::Int< 100 > z_ver = naeherung_zaehler( teilnenner, 191 ) ; // Zähler
			ttmath::Int< 100 > n_ver = naeherung_nenner( teilnenner, 191 ) ; // Nenner

			ttmath::Big< 100, 100 > z_durch_n = ttmath::Big< 100, 100 >( z ) / n ;
			ttmath::Big< 100, 100 > z_ver_durch_n_ver = ttmath::Big< 100, 100 >( z_ver ) / n_ver ;

			string z_durch_n_s = z_durch_n.ToString( 10 ) ;
			string z_ver_durch_n_ver_s = z_ver_durch_n_ver.ToString( 10 ) ;

			int genauigkeit = 0 ;
			int i = z_durch_n_s.find( '.' ) + 1 ;
			while ( z_durch_n_s.at( i ) == z_ver_durch_n_ver_s.at( i ) )
			{
				++genauigkeit ;
				++i ;
			}

			if ( genauigkeit < 100 )
				cout << "asdfsd" << endl ;

			int ziffernSumme = 0 ;
			for ( int i = 0 ;  i <= 100 ;  ++i )
				if ( z_durch_n_s.at( i ) != '.' )
					ziffernSumme += z_durch_n_s.at( i ) - '0' ;

			gesamtZiffernSumme += ziffernSumme ;
		}
	}

	cout << gesamtZiffernSumme << endl ;

	return 0 ;
}