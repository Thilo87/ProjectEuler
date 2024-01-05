#include <iostream>
#include <map>
using namespace std ;



int main ()
{
	map< int, int > p ;
	p[ 0 ] = 1 ;

	int n = 1 ;
	for ( ;  true ;  ++n )
	{
		int penta = 1 ;
		for ( int i = 0 ;  true ;  ++i )
		{
			int vorzeichen = ( i % 4 > 1 ) ? -1 : 1 ;

			int j = ( i % 2 == 0 ) ? i / 2 + 1 : -( i / 2 + 1 ) ;
			penta = j * ( 3 * j - 1 ) / 2 ;

			if ( penta > n )
				break ;

			p[ n ] += vorzeichen * p[ n - penta ] ;
			p[ n ] %= 1000000 ;
		}

		if ( p[ n ] == 0 )
			break ;
	}

	cout << n << endl ;
	return 0 ;
}