#include <iostream>
using namespace std ;

int main ()
{
	int diagonalSum = 1 ;
	int currentNumber = 1 ;
	for ( int n = 2 ;  n <= 1001 ;  n += 2 )
		for ( int i = 0 ;  i < 4 ;  ++i )
		{
			currentNumber += n ;
			diagonalSum += currentNumber ;
		}

	cout << diagonalSum << endl ;

	return 0 ;
}