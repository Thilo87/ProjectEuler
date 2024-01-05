#include <iostream>
using namespace std ;

int main ()
{
	for ( int i = 40 ;  true ;  ++i )
	{
		bool teilbar = true ;
		for ( int j = 1 ;  j <= 20 ;  ++j )
			if ( i % j != 0 )
			{
				teilbar = false ;
				break ;
			}

		if ( teilbar )
		{
			cout << i ;
			break ;
		}
	}
	return 0 ;
}