#include <iostream>
#include <cmath>
using namespace std ;

typedef unsigned long long ull ;

int main ()
{
	
	ull n = 2 ;
	while ( true )
	{
		if ( n % 10 != 0 && n % 5 != 0 && n % 2 != 0 )
		{
			ull mod = 1 ;
			ull summe = 0 ;
			ull An ;

			for ( int i = 0 ;  true ;  ++i )
			{
				summe += mod ;
				if ( summe % n == 0 )
				{
					An = i + 1 ;
					break ;
				}

				mod *= 10 ;
				mod %= n ;
			}

			if ( An > 1000000 )
			{
				cout << n << endl ;
				break ;
			}
		}

		++n ;
	}

	return 0 ;
}