#include <iostream>
using namespace std ;

int main()
{
	int r = 0 ;
	for ( int a = 3 ;  a <= 1000 ;  ++a )
		r += 2*a*( (a-1)/2 ) ;

	cout << r << endl ;

	return 0 ;
}