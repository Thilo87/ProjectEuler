#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

typedef ttmath::Int< 100 > BigInteger ;
typedef unsigned long long uint64 ;

int main ()
{
	BigInteger Ln = -1 ;
	BigInteger bn = 0 ;

	BigInteger Ln_2 = 1 ;
	BigInteger bn_2 = 0 ;

	BigInteger summe = 0 ;
	int N = 0 ;

	while ( N < 12 )
	{
		BigInteger Ln_neu = Ln*(-9) + bn*(-10) - 8 ;
		BigInteger bn_neu = Ln*(-8) + bn*(-9) - 8 ;

		BigInteger Ln_2_neu = Ln_2*(-9) + bn_2*(-10) + 8 ;
		BigInteger bn_2_neu = Ln_2*(-8) + bn_2*(-9) + 8 ;
		
		Ln = Ln_neu ;
		bn = bn_neu ;

		Ln_2 = Ln_2_neu ;
		bn_2 = bn_2_neu ;

		if ( bn > 0 && Ln * Ln - bn * bn / 4 >= 0 )
		{
			BigInteger L = ( bn * bn * 5 ) / 4 + bn*2 + 1 ;
			L.Sqrt() ;

			summe += L ;
			++N ;
		}

		if ( bn_2 > 0 && Ln_2 * Ln_2 - bn_2 * bn_2 / 4 >= 0 )
		{
			BigInteger L = ( bn_2 * bn_2 * 5 ) / 4 - bn_2*2 + 1 ;
			L.Sqrt() ;

			summe += L ;
			++N ;
		}
	}

	cout << summe << endl ;


	return 0 ;
}