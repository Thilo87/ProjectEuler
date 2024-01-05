#include <iostream>
#include <set>
using namespace std ;

bool istPalindrom( int n )
{
	int rev = 0 ;
	int n_kpi = n ;
	while ( n_kpi > 0 )
	{
		rev = rev * 10 + n_kpi % 10 ;
		n_kpi /= 10 ;
	}

	return n == rev ;
}

int main ()
{
	int const LIMIT = 100000000 ;
	double LIMIT_sqrt = sqrt( double( LIMIT ) ) ;

	unsigned long long summe = 0 ;
	set< unsigned long long > liste ;

	for ( int i = 1 ;  i <= LIMIT_sqrt ;  ++i )
	{
		unsigned long long zahl = i * i ;
		for ( int j = i + 1 ;  j <= LIMIT_sqrt ;  ++j )
		{
			zahl += j * j ;
			if ( zahl > LIMIT )
				break ;

			if ( istPalindrom( zahl ) && liste.count( zahl ) == 0 )
			{
				summe += zahl ;
				liste.insert( zahl ) ;
			}
		}
	}

	cout << summe << endl ;

	return 0 ;
}