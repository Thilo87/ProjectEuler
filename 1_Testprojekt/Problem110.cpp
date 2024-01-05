//#include <iostream>
//#include <vector>
//using namespace std ;
//
//typedef unsigned long long uint64 ;
//
//void rek( vector< int > Z, int n, int s = 1 )
//{
//	if ( Z.size() > 3 )
//		return ;
//
//	// 1=1 ;  2 = 1+1 ;  3 = 2+1 = 1+1+1 ;
//	for ( int i = 0 ;  i < Z.size() ;  ++i )
//		for ( int j = 0 ;  j < Z.size() ;  ++j )
//		{
//			if ( Z.at( i ) + Z.at( j ) < n )
//			{
//				Z.push_back( Z.at( i ) + Z.at( j ) ) ;
//				for ( int k = 0 ;  k < Z.size() ;  ++k )
//					cout << Z.at( k ) << " + " ;
//				cout << endl ;
//				rek( Z, n ) ;
//				Z.pop_back() ;
//			}
//		}
//}
//
//int main()
//{
//	vector< int > Z ;
//	Z.push_back( 1 ) ;
//	rek( Z, 8 ) ;
//	return 0 ;
//}