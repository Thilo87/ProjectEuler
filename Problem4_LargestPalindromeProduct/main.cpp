#include <iostream>
#include <cmath>
using namespace std ;

// returns i-th digit of n
int iteZiffer( int i, long long n )
{
	return int( ( n % int( pow(10., i) ) ) / pow( 10., i-1 ) ) ;
}

// returns count of digits of n
int ziffernanzahl( long long n )
{
	return int( log10( double( n ) ) ) + 1 ;
}

// is n a palindrome?
bool istPalindrom( long long n )
{
	int ziffern = ziffernanzahl( n ) ;

	for ( int i = 1 ;  i <= ziffern / 2 ;  ++i )
		if ( iteZiffer( i, n ) != iteZiffer( ziffern - i + 1, n ) )
			return false ;
	return true ;
}

int main ()
{
	long long groesstesPalindrom = 0 ; // largest palindrome
	for ( long long i = 100 ;  i < 999 ;  ++i )
		for ( long long j = 100 ;  j < 999 ;  ++j )
			if ( i * j > groesstesPalindrom )
				if ( istPalindrom( i * j ) )
					groesstesPalindrom = i * j ;

	cout << groesstesPalindrom ;


	return 0 ;
}