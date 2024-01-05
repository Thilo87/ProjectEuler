#include <iostream>
#include <vector>
#include <ttmath\ttmath.h>
using namespace std ;

int main ()
{
	vector< int > nenner ;
	nenner.push_back( 2*2 ) ;
	nenner.push_back( 3*3 ) ;
	nenner.push_back( 4*4 ) ;
	nenner.push_back( 5*5 ) ;
	nenner.push_back( 7*7 ) ;
	nenner.push_back( 12*12 ) ;
	nenner.push_back( 15*15 ) ;
	nenner.push_back( 20*20 ) ;
	nenner.push_back( 28*28 ) ;
	nenner.push_back( 35*35 ) ;

	ttmath::Int< 10 > nennerProdukt = 1 ;
	for ( int i = 0 ;  i < nenner.size() ;  ++i )
		nennerProdukt *= nenner.at( i ) ;

	ttmath::Int< 10 > summe = 0 ;
	for ( int i = 0 ;  i < nenner.size() ;  ++i )
	{
		summe += ( nennerProdukt / nenner.at( i ) ) * 2 ;
	}

	cout << summe << endl ;
	cout << nennerProdukt << endl ;
	return 0 ;
}