#include <iostream>
using namespace std ;

int main ()
{
	int a = 1 ;
	int b = 2 ;
	int summe = 2 ;

	int i = 0 ;
	while ( a <= 4000000 && b <= 4000000 )
	{
		if ( i % 2 == 0 )
		{
			a += b ;
			if ( a % 2 == 0 )
				summe += a ;
		}
		else
		{
			b += a ;
			if ( b % 2 == 0 )
				summe += b ;
			
		}
		++i ;
	}
	cout << summe ;
}