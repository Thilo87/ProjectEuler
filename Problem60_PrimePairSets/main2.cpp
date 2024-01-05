#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "primzahlen.h"
#include <map>
using namespace std ;

template< typename T >
set< T > schnittmenge( set< T > const& A, set< T > const& B )
{
	set< T > schnittmenge ;
	for ( set< T >::iterator it = A.begin() ;  it != A.end() ;  ++it )
		if ( B.count( *it ) > 0  )
			schnittmenge.insert( *it ) ;
	
	return schnittmenge ;
}



int main ()
{
	int const N = 15000000 ;
	

	bool* istPrim = siebEratosthenes( N ) ;
	vector< int > primzahlen ;

	for ( int i = 0 ;  i <= N ;  ++i )
		if ( istPrim[ i ] )
			primzahlen.push_back( i ) ;


	map< int, set< int > > sigma ;


	int const MAX_PRIMZAHL = 100 ;
	for ( int i = 0 ;  i <= MAX_PRIMZAHL ;  ++i )
		for ( int j = i + 1 ;  j <= MAX_PRIMZAHL ;  ++j )
		{
			int irechts = primzahlen.at( j ) * pow( 10., int( log10( double( primzahlen.at( i ) ) ) ) + 1 ) + primzahlen.at( i ) ;
			if ( istPrim[ irechts ] )
			{
				int ilinks = primzahlen.at( i ) * pow( 10., int( log10( double( primzahlen.at( j ) ) ) ) + 1 ) + primzahlen.at( j ) ;
				if ( istPrim[ ilinks ] )
				{
					sigma[ primzahlen.at( i ) ].insert( primzahlen.at( j ) ) ;
					sigma[ primzahlen.at( j ) ].insert( primzahlen.at( i ) ) ;
				}
			}
		}


	for ( map< int, set< int > >::iterator it = sigma.begin() ;  it != sigma.end() ;  ++it )
	{
		cout << (*it).first << ": { " ;
		for ( set< int >::iterator its = (*it).second.begin() ;  its != (*it).second.end() ;  ++its )
			cout << (*its) << " " ;
		cout << "}" << endl ;
	}

	int summe = INT_MAX ;
	for ( map< int, set< int > >::iterator it = sigma.begin() ;  it != sigma.end() ;  ++it )
	{
		for ( set< int >::iterator its = (*it).second.begin() ;  its != (*it).second.end() ;  ++its )
		{
			set< int > c = schnittmenge( sigma[ (*its) ], (*it).second ) ;
			if ( c.size() == 3 )
			{
				cout << (*it).first << " " << (*its) << " " ;
				int tmpSumme = (*it).first + (*its) ;
				for ( set< int >::iterator itc = c.begin() ;  itc != c.end() ;  ++itc )
				{
					cout << (*itc) << " " ;
					tmpSumme += (*itc) ;
				}
				cout << " = " << tmpSumme <<  endl ;

				if ( tmpSumme < summe )
					summe = tmpSumme ;
			}
	
		}
	}

	cout << summe << endl ;

	return 0 ;
}