#include "natuerlicheZahl.h"
#include <iostream>
using namespace std ;

int main ()
{
	natuerlicheZahl a( 1 ) ;
	natuerlicheZahl b( 1 ) ;

	int i = 2 ;
	while ( a.getZiffernanzahl() != 1000 && b.getZiffernanzahl() != 1000 )
	{
		if ( i % 2 == 0 )
			a.addiere( b ) ;
		else
			b.addiere( a ) ;
		++i ;
	}

	cout << i ;
}