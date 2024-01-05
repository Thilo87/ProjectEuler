//#include <iostream>
//#include <vector>
//using namespace std ;
//
//static
//	void expo( int n, vector< int > E, int& N, double& og )
//{
//	if ( E.size() - 1 > og )
//		return ;
//
//	if ( E.size() > N )
//		return ;
//
//	if ( E.back() == n )
//	{
//		if ( E.size() < N )
//			N = E.size() ;
//		
//		return ;
//	}
//	
//
//	for ( int j = 0 ;  j < E.size() ;  ++j )
//	{
//		vector< int > E_neu = E ;
//		E_neu.push_back( E.back() + E.at( j ) ) ;
//		expo( n, E_neu, N, og ) ;
//	}
//}
//
//int expo( int n )
//{
//	vector< int > e ;
//	e.push_back( 1 ) ;
//
//	
//	double og = ( 4/3. ) * floor( log( double( n ) ) / log( 2. ) ) + 2 ;
//	int N = ceil( og ) ;
//	expo( n, e, N, og ) ;
//	return N - 1 ;
//}
//
//
//
//int main()
//{
//	int summe = 0 ;
//	for ( int i = 1 ;  i <= 200 ;  ++i )
//	{
//		summe += expo( i ) ;
//		cout << i << endl ;
//	}
//
//	cout << summe << endl ;
//	return 0 ;
//}