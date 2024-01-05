#include <iostream>
#include <ttmath\ttmath.h>
#include <cmath>
using namespace std ;

typedef ttmath::Int< 100 > BigInteger ;

int main()
{
	BigInteger bn1 = 1 ;
	BigInteger yn1 = 2 ;

	BigInteger bn2 = -1 ;
	BigInteger yn2 = 2 ;

	BigInteger U_ges = 0 ;
	for ( int i = 0 ;  i < 40 ;  ++i )
	{
		BigInteger bn1_neu = bn1*(-2) + yn1*(-1) - 1 ;
		BigInteger yn1_neu = bn1*(-3) + yn1*(-2) - 1 ;

		bn1 = bn1_neu ;
		yn1 = yn1_neu ;

		BigInteger bn2_neu = bn2*(-2) + yn2*(-1) + 1 ;
		BigInteger yn2_neu = bn2*(-3) + yn2*(-2) + 1 ;

		bn2 = bn2_neu ;
		yn2 = yn2_neu ;

		if ( bn1 > 0 )
		{
			BigInteger U1 = bn1*3 - 1 ;
			if ( U1 <= 1000000000 )
				U_ges += U1 ;
		}

		if ( bn2 > 1 )
		{
			BigInteger U2 = bn2*3 + 1 ;
			if ( U2 <= 1000000000 )
				U_ges += U2 ;
		}

	}

	cout << U_ges << endl ;

	return 0 ;
}