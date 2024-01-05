#include <iostream>
#include <vector>
#include "natuerlicheZahl.h"
using namespace std ;

// gibt den Nenner der n-ten Näherung des Kettenbruches mit den Teilnennern teilnenner zurück
natuerlicheZahl naeherung_nenner( vector< int > const& teilnenner, int n )
{
	natuerlicheZahl pn, pn_m1( 1 ), pn_m2 ;

	for ( int i = 0 ;  i < n ;  ++i )
	{
		natuerlicheZahl bn( teilnenner.at( i ) );

		pn = bn * pn_m1 + pn_m2 ; // p_n = b_n * p_(n-1) + p_(n-2)

		pn_m2 = pn_m1 ;
		pn_m1 = pn ;
	}

	return pn ;
}

int main ()
{
	vector< int > teilnenner_e ;
	teilnenner_e.push_back( 2 ) ;
	teilnenner_e.push_back( 1 ) ;

	for ( int i = 2 ; i <= 100 ;  i += 2 )
	{
		teilnenner_e.push_back( i ) ;
		teilnenner_e.push_back( 1 ) ;
		teilnenner_e.push_back( 1 ) ;
	}

	natuerlicheZahl naeherung = naeherung_nenner( teilnenner_e, 100 ) ;

	int ziffernSumme = 0 ;
	for ( int i = 0 ;  i < naeherung.getZiffernanzahl() ;  ++i )
		ziffernSumme += naeherung.getZiffer( i ) ;

	cout << ziffernSumme << endl ;

	return 0 ;
}