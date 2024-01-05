/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

#include <iostream>
using namespace std ;

int const MONTAG		= 1 ;
int const DIENSTAG		= 2 ;
int const MITTWOCH		= 3 ;
int const DONNERSTAG	= 4 ;
int const FREITAG		= 5 ;
int const SAMSTAG		= 6 ;
int const SONNTAG		= 7 ;

// gibt den Wochentag von T.M.J zurück
int wochentag( int T, int M, int J )
{
	int N_T = T % 7 ;
	int J_h = J / 100 ;
	int J_z = J % 100 ;

	int N_M ;
	switch ( M )
	{
	case 1: case 10:
		N_M = 0 ;
		break ;
	case 2: case 3: case 11:
		N_M = 3 ;
		break ;
	case 4: case 7:
		N_M = 6 ;
		break ;
	case 5:
		N_M = 1 ;
		break ;
	case 6:
		N_M = 4 ;
		break ;
	case 8:
		N_M = 2 ;
		break ;
	case 9: case 12:
		N_M = 5 ;
		break ;
	}

	int N_J_z = ( J_z + ( J_z / 4 ) ) % 7 ;
	int N_J_h = ( 3 - ( J_h % 4 ) ) * 2 ;

	int N_S_j = 0 ;
	if ( M == 1 || M == 2 )
		if ( J % 400 == 0 )
			N_S_j = 6 ;
		else if ( J % 100 == 0 )
			true ;
		else if ( J % 4 == 0 )
			N_S_j = 6 ;

	int W = ( N_T + N_M + N_J_h + N_J_z + N_S_j ) % 7 ;

	switch ( W )
	{
	case 0:
		return SONNTAG ;
	case 1:
		return MONTAG ;
	case 2:
		return DIENSTAG ;
	case 3:
		return MITTWOCH ;
	case 4:
		return DONNERSTAG ;
	case 5:
		return FREITAG ;
	case 6:
		return SAMSTAG ;
	}
}


int main ()
{
	int anzahlSonntage = 0 ;
	for ( int J = 1901 ;  J <= 2000 ;  ++J )
		for ( int M = 1 ;  M <= 12 ;  ++M )
			if ( wochentag( 1, M, J ) == SONNTAG )
				++anzahlSonntage ;

	cout << anzahlSonntage << endl ;

	return 0 ;
}