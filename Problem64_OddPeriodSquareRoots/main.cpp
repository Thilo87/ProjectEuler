#include <iostream>
#include <vector>
#include <cmath>
#include "stoppuhr.h"
using namespace std ;



// gibt die (endliche) reguläre Kettenbruchdarstellung von einer rationalen Zahl p/q zurück
vector< int > kettenbruchdarstellung( int p, int q )
{
	vector< int > darstellung ;

	// euklidischer Algorithmus
	while ( q != 0 )
	{
		darstellung.push_back( p / q ) ;

		int tmp = q ;
		q = p % q ;
		p = tmp ;
	}

	return darstellung ;
}


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
	stoppUhr( START ) ;
	int anzahl = 0 ;
	for ( int i = 2 ;  i <= 10000 ;  ++i )
	{
		vector< int > kettenbruch = kettenbruch_sqrt( i ) ;
		if ( ( kettenbruch.size() - 1 ) % 2 == 1 )
			++anzahl ;
	}

	cout << anzahl << endl ;
	cout << stoppUhr( STOPP ) << "s" << endl ;

	return 0 ;
}