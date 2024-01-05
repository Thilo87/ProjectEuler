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
	int* zwei = zuZahl( "2" ) ;
	int* zahl = potenz( zwei, 1000 ) ;

	int summe = 0 ;
	for ( int i = 0 ;  i < laenge( zahl ) ;  ++i )
		summe += zahl[ i ] ;

	cout << summe ;

	delete[] zahl ;

	return 0 ;
}