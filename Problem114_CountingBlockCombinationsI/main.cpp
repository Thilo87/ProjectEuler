#include <iostream>
using namespace std ;

int const MIN_B = 10 ;

void ways( int L, unsigned long long& n )
{
	for ( int b = MIN_B ;  b <= L ;  ++b )
		for ( int pos = 0 ;  pos <= L - MIN_B ;  ++pos )
		{
			int r = L - pos - b - 1 ;
			if ( r >= -1 )
			{
				++n ;
				if ( r >= MIN_B )
					ways( r, n ) ;
			}
		}
}

int main ()
{
	int L = 56 ;
	unsigned long long n = 1 ;

	ways( L, n ) ;
	cout << n << endl ;

	return 0 ;
}