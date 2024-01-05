/*

We shall say that an n-digit number is pandigital if it makes use of all
the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254,
containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product
identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

*/

#include <iostream>
using namespace std ;

// enthält n alle Ziffern von 1 bis 9 genau einmal ?
bool istPandigital19( unsigned long long faktor1, unsigned long long faktor2, unsigned long long produkt )
{
	int ziffernAnzahl[ 10 ] = { 0 } ;

	while ( faktor1 > 0 )
	{
		++ziffernAnzahl[ faktor1 % 10 ] ;
		faktor1 /= 10 ;
	}

	while ( faktor2 > 0 )
	{
		++ziffernAnzahl[ faktor2 % 10 ] ;
		faktor2 /= 10 ;
	}

	while ( produkt > 0 )
	{
		++ziffernAnzahl[ produkt % 10 ] ;
		produkt /= 10 ;
	}

	for ( int i = 1 ;  i < 10 ;  ++i )
		if ( ziffernAnzahl[ i ] == 0 || ziffernAnzahl[ i ] > 1 )
			return false ;

	if ( ziffernAnzahl[ 0 ] > 0 )
		return false ;
	
	return true ;
}

int const MAX_FAKTOR = 20000 ;
bool istPandigital[ MAX_FAKTOR * MAX_FAKTOR + 1 ] = { false } ;

int main ()
{
	for ( int i = 1 ;  i <= MAX_FAKTOR ;  ++i )
		for ( int j = 1 ;  j <= i ;  ++j )
			if ( istPandigital19( i, j, i*j ) )
				istPandigital[ i * j ] = true ;

	unsigned long long summe = 0 ;
	for ( int i = 0 ;  i < MAX_FAKTOR * MAX_FAKTOR + 1 ;  ++i )
		if ( istPandigital[ i ] == true )
			summe += i ;

	cout << summe << endl ;

	return 0 ;
}