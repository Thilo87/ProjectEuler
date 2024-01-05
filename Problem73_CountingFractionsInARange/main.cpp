/*

Consider the fraction, n/d, where n and d are positive integers.
If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

*/

#include <iostream>
#include <vector>
using namespace std ;

vector< unsigned long long > neuerBruch( unsigned long long z, unsigned long long n )
{
	vector< unsigned long long > bruch( 2 ) ;
	bruch.at( 0 ) = z ;
	bruch.at( 1 ) = n ;
	return bruch ;
}

int main ()
{
	vector< vector< unsigned long long > > brueche ;
	
	brueche.push_back( neuerBruch( 1, 2 ) ) ;
	brueche.push_back( neuerBruch( 0, 1 ) ) ;

	int const N = 1000 ;

	while ( true )
	{
		bool bruchHinzugefuegt = false ;
		for ( int i = 0 ;  i < brueche.size() - 1 ;  i += 2 )
		{
			vector< unsigned long long > bruch = neuerBruch( brueche.at( i ).at( 0 ) + brueche.at( i + 1 ).at( 0 ),
															 brueche.at( i ).at( 1 ) + brueche.at( i + 1 ).at( 1 ) ) ;
		
			if ( bruch.at( 1 ) <= N )
			{
				brueche.insert( brueche.begin() + i + 1, bruch ) ;
				bruchHinzugefuegt = true ;
			}
		}

		if ( !bruchHinzugefuegt )
			break ;
	}


	cout << brueche.size() - 2 << endl ;
	return 0 ;
}