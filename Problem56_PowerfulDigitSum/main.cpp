#include <iostream>
#include "natuerlicheZahl.h"
using namespace std ;

int main ()
{
	int maxZiffernsumme = 0 ;
	for ( int a = 1 ;  a < 100 ;  ++a )
	{
		natuerlicheZahl a_nat = a ;
		for ( int b = 1 ;  b < 100 ;  ++b )
		{
			natuerlicheZahl potenz( 1 ) ;
			for ( int k = 1 ;  k < b ;  ++k )
				potenz = potenz * a_nat ;
			
			int aktuelleZiffernsumme = 0 ;
			for ( int k = 0 ;  k < potenz.getZiffernanzahl() ;  ++k )
				aktuelleZiffernsumme += potenz.getZiffer( k ) ;

			if ( aktuelleZiffernsumme > maxZiffernsumme )
				maxZiffernsumme = aktuelleZiffernsumme ;
		}
	}

	cout << maxZiffernsumme << endl ;

	return 0 ;
}