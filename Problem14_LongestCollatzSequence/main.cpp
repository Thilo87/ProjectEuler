#include <iostream>
#include <cmath>
using namespace std ;

// gibt die Anzahl der Schritte zurück, die benötigt werden, um bei der 1 anzukommen.
int collatzSchritte( long long n )
{
	int schritte = 1 ;

	long long i = n ;
	while ( i != 1 )
	{
		if ( i % 2 == 0 )
			i /= 2 ;
		else
			i = 3*i + 1 ;
		++schritte ;
	}

	return schritte ;
}

int main ()
{
	int hoechsteAnzahlSchritte = 0 ;
	int startnummer = 0 ;
	for ( int i = 1 ;  i < 1000000 ;  ++i )
	{
		int schritte = collatzSchritte( i ) ;
		if ( schritte > hoechsteAnzahlSchritte )
		{
			hoechsteAnzahlSchritte = schritte ;
			startnummer = i ;
		}
	}

	cout << startnummer ;
	return 0 ;
}