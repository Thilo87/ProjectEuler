/*

The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.

*/

#include <iostream>
#include <cmath>
#include <ttmath\ttmath.h>
using namespace std ;

int main ()
{
	ttmath::Int< 500 > summe = 0 ;
	for ( int i = 1 ;  i <= 1000 ;  ++i )
	{
		ttmath::Int< 500 > potenz = i ;
		potenz.Pow( i ) ;
		summe += potenz ;
	}

	cout << summe << endl ;
	return 0 ;
}