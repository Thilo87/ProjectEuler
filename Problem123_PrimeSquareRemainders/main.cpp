#include <iostream>
#include "primzahlen.h"
#include <ttmath\ttmath.h>
using namespace std ;

int main()
{
	typedef unsigned long long uint64 ;
	typedef ttmath::Int< 100 > BigInteger ;

	vector< int > primzahlen = primzahlliste( 1000000 ) ;

	BigInteger r = 0 ;
	uint64 n = 7037 ;
	while ( r < 10000000000 )
	{
		n += 2 ;
		BigInteger p = primzahlen.at( n - 1 ) ;
		r = p * n * 2 ;
	}

	cout << n << endl ;

	return 0 ;
}