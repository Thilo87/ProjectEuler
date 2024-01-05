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
	int* summe = zuZahl( "0" ) ;

	ifstream fin( "zahlen.txt" ) ;

	fin >> skipws ;

	char c[50] ;

	while ( fin >> c )
	{
		int* temp = addiere( summe, zuZahl( c ) ) ;
		delete[] summe ;
		summe = temp ;
	}

	fin.close() ;

	for ( int i = laenge( summe ) - 1 ;  i >= laenge( summe) - 10 ;  --i )
		cout << summe[ i ] ;

	return 0 ;
}