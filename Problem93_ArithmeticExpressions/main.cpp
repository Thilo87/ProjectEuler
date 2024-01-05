#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main ()
{
	int N = 0 ;

	// erzeuge alle möglichen Kombinationen 4 verschiedener Ziffern von 0 bis 9 mit a < b < c < d
	vector< vector< int > > zifferMengen ;
	for ( int z1 = 0 ;  z1 <= 9 ;  ++z1 )
		for ( int z2 = z1 + 1 ;  z2 <= 9 ;  ++z2 )
			for ( int z3 = z2 + 1 ;  z3 <= 9 ;  ++z3 )
				for ( int z4 = z3 + 1 ;  z4 <= 9 ;  ++z4 )
				{
					vector< int > ziffernMenge( 4 ) ;
					ziffernMenge.at( 0 ) = z1 ;
					ziffernMenge.at( 1 ) = z2 ;
					ziffernMenge.at( 2 ) = z3 ;
					ziffernMenge.at( 3 ) = z4 ;

					zifferMengen.push_back( ziffernMenge ) ;
				}

	
	


	return 0 ;
}