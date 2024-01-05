#include <iostream>
using namespace std ;

bool istReversibel( int n )
{
	if ( n % 10 == 0 )
		return false ;

	int umgedrehteZahl = 0 ;
	int n_kpi = n ;
	while ( n_kpi > 0 )
	{
		umgedrehteZahl *= 10 ;
		umgedrehteZahl += n_kpi % 10 ;
		n_kpi /= 10 ;
	}

	int summe = n + umgedrehteZahl ;
	while ( summe > 0 )
	{
		if ( summe % 2 == 0 )
			return false ;
		summe /= 10 ;
	}

	return true ;
}

int main ()
{
	int N = 0 ;
	for ( int i = 1 ;  i < 1000000000 ;  ++i )
		if ( istReversibel( i ) )
			++N ;

	cout << N << endl ;
	return 0 ;
}