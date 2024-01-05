//#include <iostream>
//#include <cmath>
//#include <ttmath\ttmath.h>
//using namespace std ;
//
//bool istPalindrom( int n )
//{
//	int rev = 0 ;
//	int n_kpi = n ;
//	while ( n_kpi > 0 )
//	{
//		rev = rev * 10 + n_kpi % 10 ;
//		n_kpi /= 10 ;
//	}
//
//	return n == rev ;
//}
//
//
//int const LIMIT = 100000000 ;
//bool darstellbar[ LIMIT ] = { false } ;
//
//
//
//int main ()
//{
//	for ( int a = 1 ;  true ;  ++a )
//	{
//		if ( 2*a*a - 2*a + 1 >= LIMIT )
//			break ;
//
//		ttmath::Int< 10 > a_qs = a ;
//		a_qs *= ( a + 1 ) ;
//		a_qs *= ( 2 * a + 1 ) ;
//		a_qs /= 6 ;
//
//		for ( int b = a - 2 ;  b >= 0 ;  --b )
//		{
//			ttmath::Int< 10 > b_qs = b ;
//			b_qs *= ( b + 1 ) ;
//			b_qs *= ( 2 * b + 1 ) ;
//			b_qs /= 6 ;
//
//			if ( a_qs - b_qs >= LIMIT )
//				break ;
//
//			darstellbar[ ( a_qs - b_qs ).ToInt() ] = true ;
//		}
//	}
//
//	unsigned long long summe = 0 ;
//	for ( int z = 0 ;  z < 8 ;  ++z )
//		for ( int i = pow( 10., z ) ;  i < pow( 10., z + 1 ) ;  ++i )
//		{
//			if ( z % 2 == 1 && i % 11 != 0 )
//				continue ;
//
//			if ( istPalindrom( i ))
//				if ( darstellbar[ i ] )
//					summe += i ;
//		}
//
//	cout << summe << endl ;
//
//	
//	return 0 ;
//}