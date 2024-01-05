#include <iostream>
#include <cmath>
#include <set>
#include "stoppuhr.h"
#include <vector>
using namespace std ;

int main ()
{
	stoppUhr( START ) ;

	int M = 1 ;
	int MIN_LOESUNGEN = 1000000 ;

	int loesungen = 0 ;
	for ( int b = 1 ;  true ;  ++b )
	{
		for ( int t = 1 ;  t <= b ;  ++t )
			for ( int h = 1 ;  h <= t ;  ++h )
			{
				unsigned long long min_s_sqr = b*b + t*t + h*h + 2*t*h ;
				double min_s = sqrt( double( min_s_sqr ) ) ;

				if ( min_s == int( min_s ) )
					++loesungen ;
			}

		if ( loesungen > MIN_LOESUNGEN )
			break ;
		else
			++M ;
	}

	cout << M << " " << loesungen << endl ;
	cout << stoppUhr( STOPP ) << "s" << endl ;
	
	return 0 ;
}