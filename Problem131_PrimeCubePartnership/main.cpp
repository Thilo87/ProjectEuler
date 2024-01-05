#include <iostream>
#include <cmath>
#include "primzahlen.h"
using namespace std ;

int main ()
{
	int count = 0 ;
	for ( int b = 1 ;  b < 1000 ;  ++b )
		for ( int c = 1 ;  c < b ;  ++c )
		{
			int p = b * b * b - c * c * c ;
			if ( p < 1000000 && istPrim_MRD( p ) )
				++count ;
		}

	cout << count << endl ;
	return 0 ;
}