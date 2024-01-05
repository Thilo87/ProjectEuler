#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std ;

int main ()
{
	ifstream fin( "zahl.txt" ) ;

	char zahl[ 1001 ] ;

	if ( !fin )
		return -1 ;
	else
	{
		int zeichenGesamt = 0 ;

		char z[ 1000 ] ;
		while ( fin >> z )
		{
			for ( int i = 0 ;  i < 50 ;  ++i )
				zahl[ i + zeichenGesamt ] = z[ i ] ;

			zeichenGesamt += 50 ;
		}

		zahl[ zeichenGesamt + 1 ] = '\0' ;
	}
	
	fin.close() ;


	int groesstesProdukt = 0 ;
	for ( int i = 0 ;  i < 995 ;  ++i )
	{
		int produkt = 1 ;
		for ( int j = 0 ;  j < 5 ;  ++j )
			produkt *= zahl[ i + j ] - '0' ;

		if ( produkt > groesstesProdukt )
			groesstesProdukt = produkt ;
	}

	cout << groesstesProdukt ;

	return 0 ;
}