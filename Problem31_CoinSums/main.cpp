///*
//
//In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
//
//    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
//
//It is possible to make £2 in the following way:
//
//    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
//
//How many different ways can £2 be made using any number of coins?
//
//*/
//
//#include <iostream>
//#include "stoppuhr.h"
//using namespace std ;
//
//int main ()
//{
//	stoppUhr( START ) ;
//
//	int anzahl = 0 ;
//	for ( int i = 0 ;  i <= 200 ;  ++i )
//		for ( int j = 0 ;  j <= 100 - i/2 ;  ++j )
//			for ( int k = 0 ;  k <= 40 - 2*j/5 - i/5 ;  ++k )
//				for ( int l = 0 ;  l <= 20 - k/2 - j/5 - i/10 ;  ++l )
//					for ( int m = 0 ;  m <= 10 - l/2 - k/4 - j/10 - i/20 ;  ++m )
//						for ( int n = 0 ;  n <= 4 ;  ++n )
//							if ( i + 2 * j + 5 * k + 10 * l + 20 * m + 50 * n <= 200 )
//							for ( int o = 0 ;  o <= 2 ;  ++o )
//								if ( i + 2 * j + 5 * k + 10 * l + 20 * m + 50 * n + 100 * o <= 200 )
//								for ( int p = 0 ;  p <= 1 ;  ++p )
//									if ( i + 2 * j + 5 * k + 10 * l + 20 * m + 50 * n + 100 * o + 200 * p <= 200 )
//									if ( i * 1 + j * 2 + k * 5 + l * 10 + m * 20 + n * 50 + o * 100 + p * 200 == 200 )
//										++anzahl ;
//
//	cout << anzahl << " " << 73682 ;
//
//	cout << endl << stoppUhr( STOPP ) << "s" << endl ;
//	return 0 ;
//}