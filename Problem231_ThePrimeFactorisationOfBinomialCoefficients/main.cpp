#include <iostream>
#include <vector>
#include <map>
#include "primzahlen.h"
using namespace std ;

typedef unsigned long long uint64 ;

map< uint64, uint64 > faktorisieren( int n, vector< int >& primzahlen )
{
	map< uint64, uint64 > primfaktoren ;

	for ( int i = 0 ;  primzahlen.at( i ) <= n ;  ++i )
	{
		uint64 e = 0 ;
		for ( uint64 p = primzahlen.at( i ) ;  p <= n ;  p *= primzahlen.at( i ) )
			e += n / p ;

		primfaktoren[ primzahlen.at( i ) ] = e ;
	}

	return primfaktoren ;
}

int main()
{
	vector< int > primzahlen = primzahlliste( 20500000 ) ;


	int n = 20000000, k = 15000000 ;
	map< uint64, uint64 > n_pf = faktorisieren( n, primzahlen ) ;
	map< uint64, uint64 > k_pf = faktorisieren( k, primzahlen ) ;
	map< uint64, uint64 > nmk_pf = faktorisieren( n - k, primzahlen ) ;



	for ( map< uint64, uint64 >::iterator i = k_pf.begin() ;  i != k_pf.end() ;  ++i )
		n_pf[ (*i).first ] -= (*i).second ;

	for ( map< uint64, uint64 >::iterator i = nmk_pf.begin() ;  i != nmk_pf.end() ;  ++i )
		n_pf[ (*i).first ] -= (*i).second ;

	uint64 summe = 0 ;
	for ( map< uint64, uint64 >::iterator i = n_pf.begin() ;  i != n_pf.end() ;  ++i )
		if ( (*i).second != 0 )
			summe += (*i).first * (*i).second ;

	cout << summe << endl ;

	return 0 ;
}