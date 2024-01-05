#include <iostream>
using namespace std ;

void ways( int L, unsigned long long& n, int const MIN_B )
{
	for ( int b = MIN_B ;  b <= L ;  ++b )
		for ( int pos = 0 ;  pos <= L - MIN_B ;  ++pos )
		{
			int r = L - pos - b - 1 ;
			if ( r >= -1 )
			{
				++n ;
				if ( r >= MIN_B )
					ways( r, n, MIN_B ) ;
			}
		}
}

unsigned long long F( int MIN_B, int L )
{
	unsigned long long n = 1 ;
	ways( L, n, MIN_B ) ;
	return n ;
}

int main ()
{
	for ( int n = 50 ;  true ;  ++n )
		if ( F( 50, n ) > 1000000 )
		{
			cout << n << endl ;
			break ;
		}

	return 0 ;
}