///*
//
//It is possible to write five as a sum in exactly six different ways:
//
//4 + 1
//3 + 2
//3 + 1 + 1
//2 + 2 + 1
//2 + 1 + 1 + 1
//1 + 1 + 1 + 1 + 1
//
//How many different ways can one hundred be written as a sum of at least two positive integers?
//
//*/
//
//#include <iostream>
//using namespace std ;
//
//// gibt die Anzahl der Möglichkeiten an, n in genau k Summanden zu zerlegen
//unsigned long long P( int n, int k )
//{
//	if ( k > n )
//		return 0 ;
//	if ( k == n )
//		return 1 ;
//	if ( k == 0 )
//		return 0 ;
//	return P( n - 1, k - 1 ) + P( n - k, k ) ;
//}
//
//int main ()
//{
//	unsigned long long moeglichkeiten = 0 ;
//	for ( int i = 2 ;  i <= 100 ;  ++i )
//		moeglichkeiten += P( 100, i ) ;
//
//	cout << moeglichkeiten << endl ;
//	return 0 ;
//}