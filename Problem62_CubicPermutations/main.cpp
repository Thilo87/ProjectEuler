/*

The cube, 41063625 (3453), can be permuted to produce two other cubes:
56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has
exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

*/

#include <iostream>
#include <cmath>
#include <ttmath\ttmath.h>
#include <vector>
using namespace std ;

// ordnet jeder Ziffer einer natürlichen Zahl n eine Primzahl zu und gibt das Produkt der zugeordneten Primzahlen
// zurück. Damit erhält jede Zahl ein individuelles Produkt. Wenn zwei Zahlen dasselbe Produkt besitzen,
// besitzen sie dieselben Zahlen, sind also eine Permutation voneinander
int const ziffernPrimErsatz[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 } ;
ttmath::Int< 100 > ziffernPrimIdent( ttmath::Int< 100 > n )
{
	ttmath::Int< 100 > primIdent = 1 ;
	while ( n > 0 )
	{
		primIdent *= ziffernPrimErsatz[ ( n % 10 ).ToInt() ] ;
		n /= 10 ;
	}

	return primIdent ;
}

int main ()
{
	int const MAX_KUBIKZAHL = 10000 + 1 ;
	
	vector< ttmath::Int< 100 > > ident( MAX_KUBIKZAHL ) ;
	for ( int i = 0 ;  i < MAX_KUBIKZAHL ;  ++i )
	{
		ttmath::Int< 100 > z = i ;
		z.Pow( 3 ) ;
		ident.at( i ) = ziffernPrimIdent( z ) ;
	}

	for ( int i = 0 ;  i < MAX_KUBIKZAHL ;  ++i )
		for ( int j = i + 1 ;  j < MAX_KUBIKZAHL ;  ++j )
			if ( ident.at( i ) == ident.at( j ) )
				for ( int k = j + 1 ;  k < MAX_KUBIKZAHL ;  ++k )
					if ( ident.at( i ) == ident.at( k ) )
						for ( int l = k + 1 ;  l < MAX_KUBIKZAHL ;  ++l )
							if ( ident.at( i ) == ident.at( l ) )
								for ( int m = l + 1 ;  m < MAX_KUBIKZAHL ;  ++m )
									if ( ident.at( i ) == ident.at( m ) )
										cout << i << " " << j << " " << k << " " << l << " " << m << endl ;
	return 0 ;
}