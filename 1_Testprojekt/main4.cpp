//#include <iostream>
//using namespace std ;
//
//int N( int d1, int d2, int z )
//{
//	int N = 0 ;
//	for ( int i = 1 ;  i < pow( 10., z ) ;  ++i )
//	{
//		int i_kpi = i ;
//		bool d1e = false, d2e = false ;
//		while ( i_kpi > 0 )
//		{
//			if ( i_kpi % 10 == d1 )
//			{
//				d1e = true ;
//
//			}
//			if ( i_kpi % 10 == d2 )
//				d2e = true ;
//
//			i_kpi /= 10 ;
//		}
//
//		if ( d1e && d2e )
//			++N ;
//	}
//
//	return N ;
//}
//
//// Wieviele Zahlen mit maximal n Ziffern gibt es, die mindestens einmal die Ziffer d enthalten?
//// Gültig für Ziffern von 1 bis 9
//long long a( int d, int n )
//{
//	long long a_n = 1 ;
//	for ( int i = 1 ;  i < n ;  ++i )
//		a_n = a_n * 10 + pow( 9., i ) ;
//	return a_n ;
//}
//
//int main()
//{
//	
//	return 0 ;
//}