#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include "primzahlen.h"
using namespace std ;

typedef unsigned long long uint64 ;

int const EINSEN = 3 ;
void zahl( int ziffern, int einsen, string z )
{

}

// gibt alle n-ziffrigen Zahlen zurück, die genau m-mal die Ziffer d enthalten
vector< uint64 > zahlen( int n, int m, int d )
{
	vector< uint64 > zahlen ;
	string a = "111232" ;
	do
	{
		cout << a << endl ;
	}
	while ( next_permutation( a.begin(), a.end() ) ) ;

	cout << a << endl ;

	return zahlen ;
}

int main()
{

	//int const MAX_PRIMZAHL = 10000 ;

	//vector< int > primzahlen = primzahlliste( MAX_PRIMZAHL ) ;

	//int N = 0 ;
	//for ( long long i = pow( 10., 10 ) - 1 ;  true ;  --i )
	//	if ( istPrim_MRD( i ) )
	//	{
	//		++N ;
	//		cout << i << endl ;
	//		
	//	}
	//cout << N << endl ;

	//// Berechne M(n,d)
	//int n = 4 ;
	//int d = 1 ;

	//map< int, int > M ;
	//
	//for ( int i = 0 ;  i < primzahlen.size() ;  ++i )
	//{
	//	if ( int( log10( double( primzahlen.at( i ) ) ) ) + 1 == n )
	//	{
	//		int k = primzahlen.at( i ) ;
	//		int ziffernAnzahl[ 10 ] = { 0 } ;
	//		while ( k > 0 )
	//		{
	//			++ziffernAnzahl[ k % 10 ] ;
	//			k /= 10 ;
	//		}

	//		if ( ziffernAnzahl[ 2 ] == 3 )
	//			cout << primzahlen.at( i ) << endl ;
	//	}
	//}

	return 0 ;
}