#include <iostream>
using namespace std ;

typedef unsigned long long uint64 ;

int main()
{
	for ( uint64 x = ceil( sqrt( double( 1020304050607080900LL ) ) ) ;  x <= floor( sqrt( double( 1929394959697989990LL ) ) ) ;  ++x )
		if ( x*x % 10 == 0 )
		if ( (x*x % 1000 ) / 100 == 9 )
			if ( (x*x % 100000 ) / 10000 == 8 )
				if ( (x*x % 10000000 ) / 1000000 == 7 )
					if ( (x*x % 1000000000 ) / 100000000 == 6 )
						if ( (x*x % 100000000000 ) / 10000000000 == 5 )
							if ( (x*x % 10000000000000 ) / 1000000000000 == 4 )
								if ( (x*x % 1000000000000000 ) / 100000000000000 == 3 )
									if ( (x*x % 100000000000000000LL ) / 10000000000000000LL == 2 )
									cout << x << endl ;

	return 0 ;
}