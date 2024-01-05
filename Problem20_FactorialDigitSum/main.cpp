/*
	Autoren:
	Thilo Noll, 809067
	Inga Hopf, 808628
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "natuerlich.h"

using namespace std ;

/*** symbolische Konstanten für die Operatoren ***/
char const OP_PLUS		= '+' ;
char const OP_MINUS		= '-' ;
char const OP_MAL		= '*' ;
char const OP_POTENZ	= '^' ;

// beide Operatoren (...)_1 und (...)_2 sind verschiedene Schreibweisen für dieselbe Operation
char const OP_GGT_1		= 'g' ; // größter gemeinsamer Teiler
char const OP_GGT_2		= 'G' ;

int main ( int narg, char* argv[] )
{
	int* fakultaet = zuZahl( "1" ) ;
	int* zaehler = zuZahl( "1" ) ;

	for ( int i = 1 ;  i < 100 ;  ++i )
	{
		int* temp = addiere( zaehler, dieEins ) ;
		delete[] zaehler ;
		zaehler = temp ;

		int* temp2 = multipliziere( fakultaet, zaehler ) ;
		delete[] fakultaet ;
		fakultaet = temp2 ;
	}

	int ziffernSumme = 0 ;
	for ( int i = 0 ;  i < laenge( fakultaet ) ;  ++i )
		ziffernSumme += fakultaet[ i ] ;

	cout << ziffernSumme ;

	return 0 ;
}