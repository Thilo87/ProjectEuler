/*

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

*/

#include <iostream>
#include <vector>
using namespace std ;

bool vektor_enthaelt( vector<int>& const vec , int n )
{
	for ( int i = 0 ;  i < vec.size() ;  ++i )
		if ( vec.at( i ) == n )
			return true ;

	return false ;
}

vector<char> dividiere_1durch( unsigned int divisor )
{
	vector<char> ergebnis ;

	vector<int> reste ;
	reste.push_back( 10 ) ;

	int zwischenergebnis = 1 ;
	while ( true )
	{
		zwischenergebnis *= 10 ;
		while ( true )
			if ( zwischenergebnis / divisor == 0 )
			{
				zwischenergebnis *= 10 ;
				ergebnis.push_back( '0' ) ;
			}
			else
				break ;

		ergebnis.push_back( ( zwischenergebnis / divisor ) + '0' ) ;
		zwischenergebnis = zwischenergebnis % divisor ;

		// Periode gefunden
		if ( vektor_enthaelt( reste, zwischenergebnis ) )
			break ;

		reste.push_back( zwischenergebnis ) ;
	
		// Division ist aufgegangen
		if ( zwischenergebnis == 0 )
			break ;
	}

	return ergebnis ;
}

int main ()
{
	vector<char> ergebnis = dividiere_1durch( 23 ) ;
	//for ( int i = 0 ;  i < ergebnis.size() ;  ++i )
	//	cout << ergebnis.at( i ) ;

	int laengstePeriode = 0 ;
	int zahlMitLaengsterPeriode = 0 ;
	for ( int i = 1 ;  i < 10000 ;  ++i )
	{
		ergebnis = dividiere_1durch( i ) ;
		if ( ergebnis.size() > laengstePeriode )
		{
			laengstePeriode = ergebnis.size() ;
			zahlMitLaengsterPeriode = i ;
		}
	}

	cout << zahlMitLaengsterPeriode ;

	return 0 ;
}