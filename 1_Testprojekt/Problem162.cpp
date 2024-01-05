//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std ;
//
//typedef unsigned long long uint64 ;
//char const HEX_ZIFFERN[ 6 ] = { 'A', 'B', 'C', 'D', 'E', 'F' } ;
//
//string inHex( uint64 n )
//{
//	string ergebnis ;
//	if ( n == 0 )
//	{
//		ergebnis.push_back( 0 + '0' ) ;
//		return ergebnis ;
//	}	
//
//	while ( n > 0 )
//	{
//		int z = n % 16 ;
//		if ( z >= 10 )
//			ergebnis.push_back( HEX_ZIFFERN[ z % 10 ] ) ;
//		else
//			ergebnis.push_back( z + '0' ) ;
//		n /= 16 ;
//	}
//	reverse( ergebnis.begin(), ergebnis.end() ) ;
//	return ergebnis ;
//}
//
//// Wieviele Zahlen mit maximal n Ziffern gibt es, die mindestens einmal die Ziffer d enthalten?
//// Gültig für Ziffern von 1 bis 9
//long long u( int n )
//{
//	long long a_n = 1 ;
//	for ( int i = 1 ;  i < n - 1 ;  ++i )
//		a_n = a_n * 10 + pow( 9., i ) ;
//	return a_n ;
//}
//
//// Wieviele Zahlen mit maximal n, n >= 4 Ziffern gibt es, die zwei bestimmte Ziffern enthalten?
//long long v( int n )
//{
//	return pow( 10., ( n - 4 ) ) * 488 ;
//}
//
//long long MitA( int d )
//{
//	return pow( 16., d ) - pow( 15., d ) ;
//}
//
//long long Mit1( int d )
//{
//	return pow( 16., d ) - pow( 15., d ) ;
//}
//
//long long Mit0( int d )
//{
//	return pow( 16., d ) - 1 - ( pow( 15., d + 1 ) - 15 ) / 14 ;
//}
//int main()
//{
//	int mitAund1 = 0 ;
//
//	for ( int i = 1 ;  i < 16*16*16*16*16 ;  ++i )
//	{
//		string hex = inHex( i ) ;
//		if ( hex.find( 'A' ) != -1 && hex.find( '1' ) != -1 && hex.find( '0' ) != -1 )
//			++mitAund1 ;
//		//if ( hex.find( '0' ) != -1 )
//		//	++mit0 ;
//		//if ( hex.find( '1' ) != -1 )
//		//	++mit1 ;
//
//		if ( i == 16 - 1 )
//		{
//			cout << "1 Ziffer: " << mitAund1 << " " << MitA( 1 )<< " "<< Mit0( 1 )  << endl ;
//		}
//		if ( i == 16*16 - 1 )
//		{
//			cout << "2 Ziffer: " << mitAund1 << " " << MitA( 2 )<< " "<< Mit0( 2 )  << endl ;
//		}
//		if ( i == 16*16*16 - 1 )
//			cout << "3 Ziffer: " << mitAund1 << " " << MitA( 3 )<< " "<< Mit0( 3 )  << endl ;
//		if ( i == 16*16*16*16 - 1 )
//			cout << "4 Ziffer: " << mitAund1 << " " << MitA( 4 )<< " "<< Mit0( 4 )  << endl ;
//		if ( i == 16*16*16*16*16 - 1 )
//			cout << "5 Ziffer: " << mitAund1 << " " << MitA( 5 )<< " "<< Mit0( 5 )  << endl ;
//	}
//	return 0 ;
//}