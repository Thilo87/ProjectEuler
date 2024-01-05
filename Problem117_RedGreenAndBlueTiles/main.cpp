#include <iostream>
using namespace std ;

void wege( int L, unsigned long long& n )
{
	if ( L >= 4 )
		n += 3*L - 6 ;
	else if ( L >= 3 )
		n += 2*L - 3 ;
	else if ( L >= 2 )
		n += L - 1 ;

	for ( ;  L >= 2 ;  --L )
	{
		if ( L >= 4 )
		{
			wege( L - 4, n ) ;
			wege( L - 3, n ) ;
			wege( L - 2, n ) ;
		}
		else if ( L >= 3 )
		{
			wege( L - 3, n ) ;
			wege( L - 2, n ) ;
		}
		else
			wege( L - 2, n ) ;
	}

}

int main ()
{
	unsigned long long n = 1 ;
	wege( 50, n ) ;

	cout << n << endl ;
	return 0 ;
}