#include <iostream>
using namespace std ;

void wege( int L, unsigned long long& n, int b )
{
	if ( L < b )
		return ;

	n += L - b + 1 ;

	for ( ;  L >= b ;  --L )
	{
		wege( L - b, n, b ) ;
	}
}

//void wege( int L, unsigned long long& n, int b )
//{
//	if ( L < b )
//		return ;
//
//	for ( ;  L >= b ;  --L )
//	{
//		++n ;
//		wege( L - b, n, b ) ;
//	}
//}

int main ()
{
	unsigned long long n = 0 ;
	wege( 50, n, 2 ) ;
	wege( 50, n, 3 ) ;
	wege( 50, n, 4 ) ;

	cout << n << endl ;
	return 0 ;
}