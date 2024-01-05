#include "stoppuhr.h"

// gibt die Zeit in Sekunden zurück, die zwischen startUhr( START ) und startUhr( STOPP ) vergangen ist
double stoppUhr ( bool start )
{
	static double zeitAlt = 0 ;

	if ( start )
	{
		zeitAlt = clock() ;
		return 0 ;
	}
	else
	{
		return ( clock() - zeitAlt ) / CLOCKS_PER_SEC ;
	}
}