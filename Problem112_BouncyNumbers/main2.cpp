#include <iostream>
using namespace std ;

bool istBouncyNumber( int n )
{
	int* ziffern = new int[ int( log10( double( n ) ) ) + 1 ] ;

	bool u = false, d = false ;
	for ( int i = 0 ;  n > 0 ;  ++i )
	{
		ziffern[ i ] = n % 10 ;
		if ( i > 0 )
			if ( ziffern[ i - 1 ] < ziffern[ i ] )
				u = true ;
			else if ( ziffern[ i - 1 ] > ziffern[ i ] )
				d = true ;

		if ( u == true && d == true )
			return true ;

		n /= 10 ;
	}

	delete[] ziffern ;
	return false ;
}

int main ()
{
	int N = 0 ;
	
	for ( int i = 100 ;  true ;  ++i )
	{
		if ( istBouncyNumber( i ) )
			++N ;

		double prop = N / double( i ) ;
		if ( prop >= 0.99 )
		{
			cout << i << endl ;
			break ;
		}
	}

	return 0 ;
}