//#include <iostream>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std ;
//
//int main()
//{
//	typedef unsigned long long uint64 ;
//	uint64 const LIMIT = 10000000000 ;
//	//int N1 = 0 ;
//	//for ( int i = 0 ;  i <= LIMIT ;  i += 10 )
//	//{
//	//	for ( int j = i / 10 + i / 100 + i / 1000 + i / 10000 + i / 100000 + i / 1000000 + i / 10000000 + i / 100000000 + i / 1000000000 ;  j <= 9 + ( i / 100 ) * 10 + ( i / 1000 ) * 10  + ( i / 10000 ) * 10 + ( i / 100000 ) * 10 + ( i / 1000000 ) * 10 + ( i / 10000000 ) * 10 + ( i / 100000000 ) * 10 + ( i / 1000000000 ) * 10 ;  ++j )
//	//		if ( j+i <= LIMIT )
//	//			++N1 ;
//	//}
//	//cout << N1 - 1 << endl ;
//
//	//int N = 0 ;
//	//for ( int i = 0 ;  i <= LIMIT ;  i += 10 )
//	//{
//	//	int tmp = i ;
//	//	int s = 0 ;
//	//	while ( tmp > 0 )
//	//	{
//	//		tmp /= 10 ;
//	//		s += tmp ;
//	//	}
//
//	//	//cout << i << " " << s << " " << endl ;
//
//	//	for ( int j = s ;  j <= 9 + ( s - i / 10 ) * 10 ;  ++j )
//	//		if ( j + i <= LIMIT )
//	//			++N ;
//	//}
//	//cout << N - 1 << endl ;
//
//
//
//	int N4 = 0 ;
//	uint64 s = 0 ;
//	for ( uint64 i = 0 ;  i <= LIMIT ;  i += 10 )
//	{
//		if ( i != 0 )
//		{
//			uint64 m = 100 ;
//			while ( i % m == 0 && m <= i )
//			{
//				m *= 10 ;
//				++s ;
//			}
//		}
//		
//
//		//cout << i << " " << s << " " << s2 << endl ;
//		
//		for ( uint64 j = s ;  j <= 9 + 10*s - i + i % 10 ;  ++j )
//			if ( j + i <= LIMIT )
//				++N4 ;
//
//		++s ;
//	}
//	cout << N4 - 1 << endl ;
//
//	return 0 ;
//}