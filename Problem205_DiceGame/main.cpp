#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std ;

int main ()
{
	srand( time( NULL ) ) ;

	int spiele = 0, peter = 0, colin = 0 ;

	for ( ;  spiele < 1000000000 ;  ++spiele )
	{
		// rolle Pyramiden
		int summePyramiden = 0 ;
		for ( int n = 0 ;  n < 9 ;  ++n )
			summePyramiden += rand() % 4 + 1 ;
	
		// rolle Würfel
		int summeWuerfel = 0 ;
		for ( int n = 0 ;  n < 6 ;  ++n )
			summeWuerfel += rand() % 6 + 1 ;

		if ( summePyramiden > summeWuerfel )
			++peter ;
		else if ( summePyramiden < summeWuerfel )
			++colin ;
		else
		{
			++colin ;
			++peter ;
		}
	}

	cout << fixed << setprecision( 7 ) ;
	cout << double( peter ) / spiele << endl ;


	system( "PAUSE" ) ;
	return 0 ;
}