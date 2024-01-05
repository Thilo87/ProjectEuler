#include <iostream>
#include <set>
using namespace std ;

int main()
{
	int const PRIMZAHLEN = 25 ;
	int primzahl[ 25 ] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 } ;

	int const LIMIT = 1000000000 ;

	int N = 3 ;
	for ( int i = 4 ;  i <= LIMIT ;  ++i )
	{
		int n = i ;
		for ( int j = 0 ;  j < PRIMZAHLEN && n != 1 ;  ++j )
			while ( n % primzahl[ j ] == 0 )
				n /= primzahl[ j ] ;
	
		if ( n == 1 )
			++N ;
	}


	cout << N << endl ;



	/*for ( int i = 0 ;  i <= LIMIT ;  ++i )
		zahlen[ i ] = i ;

	for ( int i = 2 ;  i <= LIMIT ;  ++i )
	{
		
		for ( int j = 0 ;  j < PRIMZAHLEN ;  ++j )
		{
			int p = primzahl[ j ] ;
			int p_pot = 1 ;
			while ( zahlen[ i ] % p == 0 )
			{
				zahlen[ i ] /= p ;
				p_pot *= p ;
			}
			
			for ( int k = 2*i ;  k <= LIMIT ;  k += i )
				if ( zahlen[ k ] % p_pot == 0 )
					zahlen[ k ] /= p_pot ;
		}
	}

	int N = 0 ;
	for ( int i = 1 ;  i <= LIMIT ;  ++i )
		if ( zahlen[ i ] == 1 )
		{
			++N ;
		}

	cout << N << endl ;*/

	return 0 ;
}