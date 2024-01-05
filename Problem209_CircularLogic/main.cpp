#include <iostream>
#include <bitset>
#include <cmath>
using namespace std ;

int main()
{
	int N = 0 ;

	bitset< 6 > t1 ;
	for ( int i = 0 ;  i < pow( 2., 6 ) ;  ++i )
	{
		t1.reset() ;
		t1 ^= i ;

		bitset< 6 > t2 ;
		t2 = t1 << 1 ;
		t2[ 0 ] = t1[ 5 ] ^ ( t1[ 4 ] & t1[ 3 ] ) ;
	
		bitset< 6 > t3 = t1 & t2 ;
		cout << t3 << endl ;

	}

	cout << N << endl ;
	return 0 ;
}