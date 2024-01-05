//#include <iostream>
//#include <ttmath\ttmath.h>
//using namespace std ;
//
//typedef ttmath::Int< 30 > BigInteger ;
//typedef unsigned long long uint64 ;
//
//// enhaltener 5-er Exponent in der n!-Fakultät, gleich der Anzahl der endenden Nullen der n!-Fakultät
//int ex( uint64 n )
//{
//	int e = 0 ;
//	for ( uint64 i = 5 ;  i <= n ;  i *= 5 )
//		e += n / i ;
//
//	return e ;
//}
//
//void fak( int n )
//{
//	BigInteger f = 1 ;
//	for ( int i = 2 ;  i <= n ;  ++i )
//		f *= i ;
//
//	cout << f << endl ;
//}
//
//double const log5 = log( 5. ) ;
//double const PI = 3.14159265358979323846 ;
//double const E = 2.718281828459045235 ;
//
//typedef unsigned long long uint64 ;
//
//int main()
//{
//	//cout << ex( 1000000000000 ) << endl ;
//
//	uint64 n = 10 ;
//
//	ttmath::Big< 10, 10 > ln10 = 10 ;
//	ln10 = ttmath::Ln( ln10 ) ;
//
//	double p = n / E ;
//	ttmath::Big< 10, 10 > a = 1 ;
//	a *= sqrt( 2*PI*n ) ;
//
//	int z = ( ttmath::Floor( ttmath::Ln( a ) / ln10 ) + 1 ).ToInt() ;
//	a /= pow( 10., z ) ;
//	ttmath::Int< 10 > b ;
//
//	int abgeschnitten = 0 ;
//	for ( int i = 0 ;  i < n ;  ++i )
//	{
//		a *= p ;
//		
//		/*a = a.ToInt() % 100000 ;*/
//		if ( abgeschnitten != 891896829 && i % 5 == 0 )
//		{
//			a /= 10. ;
//			++abgeschnitten ;
//		}
//
//		a.ToInt( b ) ;
//		a = b % 10000000 ;
//		
//	}
//
//	
//	
//	a.ToInt( b ) ;
//	//b %= 100000 ;
//	cout << b << endl ;
//
//
//
//
//
//
//
//
//
//
//
//	//uint64 n = 10000000 ;
//
//	//BigInteger f = 1 ;
//	//for ( uint64 i = 0 ;  i < n ;  i += 5 )
//	//{
//	//	for ( uint64 j = i + 1 ;  j <= i + 5 ;  ++j )
//	//	{
//	//		//f *= j ;
//
//	//		if ( j <= i + 4 )
//	//			f *= j % 100000 ;
//	//		else
//	//			f *= j ;
//	//	}
//
//	//	f /= (2*5) ;
//
//	//	if ( i != 0 )
//	//	{
//	//		uint64 ip5 = i + 5 ;
//	//		uint64 e = 2 ;
//	//		uint64 m = 25 ;
//	//		while ( m <= ip5 )
//	//		{
//	//			++e ;
//	//			m *= 5 ;
//	//		}
//
//	//		if ( m > ip5 )
//	//		{
//	//			m /= 5 ;
//	//			--e ;
//	//		}
//
//	//		while ( true )
//	//			if ( ip5 % m == 0 )
//	//			{
//	//				f /= uint64( pow( 2*5, double( e - 1 ) ) ) ;
//	//				break ;
//	//			}
//	//			else
//	//			{
//	//				m /= 5 ;
//	//				--e ;
//	//			}
//	//	}
//
//	//	f %= 100000 ;
//	//}
//
//	//cout << f << endl ;
//
//	////fak( n ) ;
//
//	return 0 ;
//}