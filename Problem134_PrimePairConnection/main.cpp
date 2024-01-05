#include <iostream>
#include "primzahlen.h"
#include "diophGleichungen_BigInt.h"
using namespace std ;

int main ()
{
	int const MAX_P = 1001000 ;
	vector< int > primzahlen = primzahlliste( MAX_P ) ;

	bint summe = 0 ;
	for ( int i = 2 ;  i < primzahlen.size() - 1 ;  ++i )
	{

		bint p1 = primzahlen.at( i ) ;
		if ( p1 <= 1000000 )
		{
			bint p2 = primzahlen.at( i + 1 ) ;

			bint zehn = 10 ;
			zehn.Pow( p1.ToString().size() ) ;
			tuple< bint, bint > erg = lineareKongruenz( p2, p1, zehn ) ;

			ttmath::Big< 100, 100 > x_sp = get< 0 >( erg ) ;
			ttmath::Big< 100, 100 > n = - ( x_sp / get< 1 >( erg ) ) ;
			bint v2 = ttmath::Ceil( n ).ToInt() ;

			summe += ( get< 0 >( erg ) + v2 * get< 1 >( erg ) ) * p2 ;
		}
	}

	cout << summe << endl ;

	return 0 ;
}