#include <iostream>
using namespace std ;

// Bedingungen: a^2 + b^2 = c^2, a < b < c, a + b + c = 1000
// wegen a + b + c = 1000 folgt c = 1000 - a - b
// aus a^2 + b^2 = c^2 folgt a^2 + b^2 = ( 1000 - a - b )^2 folgt b = 1000*( a - 500 )/( a - 1000 ) > 0 folgt a < 500
// und b muss eine natuerliche Zahl sein
int main ()
{
	double a, b, c ;
	for ( int i = 1 ;  i < 500 ;  ++i )
	{
		a = i ;
		b = 1000*(a-500)/(a-1000) ;

		if ( b == int( b ) && a < b ) // hat b keine Nachkommastellen? Ist a kleiner b?
		{
			c = 1000-a-b ;
			cout << long long( a * b * c ) ;
		}

	}
}