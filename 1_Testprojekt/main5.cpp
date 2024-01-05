//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//using namespace std ;
//
//// speichert in m alle Möglichkeiten, k Elemente aus e auszuwählen ( e.size() über k )
//template< typename T >
//void k_aus_n( int k, vector< T > e, set< vector< T > >& m )
//{
//	vector< T > c ;
//	k_aus_n< T >( k, e, m, 1, -1, c ) ;
//}
//
//template< typename T >
//static 
//void k_aus_n( int k, vector< T > e, set< vector< T > >& m, int s, int j, vector< T >& c )
//{
//	for ( int i = j + 1 ;  i < e.size() ;  ++i )
//	{
//		c.push_back( e.at( i ) ) ;
//
//		if ( s == k )
//		{
//			if ( c.front() != "*" && c.front() != "/" )
//				m.insert( c ) ;
//		}
//		else
//			k_aus_n< T >( k, e, m, s + 1, i, c ) ;
//
//		c.pop_back() ;
//	}
//}
//
//int main()
//{
//	vector< string > operatoren ;
//	for ( int i = 0 ;  i < 4 ;  ++i )
//	{
//		operatoren.push_back( "+" ) ;
//		operatoren.push_back( "-" ) ;
//		operatoren.push_back( "*" ) ;
//		operatoren.push_back( "/" ) ;
//	}
//
//	set< vector< string > > kombiOperatoren ;
//	k_aus_n( 4, operatoren, kombiOperatoren ) ;
//
//	set< vector< string > > kombiBuchstaben ;
//
//	for ( int a = 'a' ;  a < 'a' + 4 ;  ++a )
//		for ( int b = 'a' ;  b < 'a' + 4 ;  ++b )
//			if ( b != a )
//				for ( int c = 'a' ;  c < 'a' + 4 ;  ++c )
//					if ( c != a && c != b )
//						for ( int d = 'a' ;  d < 'a' + 4 ;  ++d )
//							if ( d != a && d != b && d != c )
//							{
//								for ( set< vector< string > >::iterator i = kombiOperatoren.begin() ;  i != kombiOperatoren.end() ;  ++i )
//								{
//									vector< string > kombi_neu = (*i) ;
//									kombi_neu.insert( kombi_neu.begin() + 1 , string( 1, char( a ) ) ) ;
//									kombi_neu.insert( kombi_neu.begin() + 3 , string( 1, char( b ) ) ) ;
//									kombi_neu.insert( kombi_neu.begin() + 5, string( 1, char( c ) ) ) ;
//									kombi_neu.insert( kombi_neu.begin() + 7, string( 1, char( d ) ) ) ;
//
//									kombiBuchstaben.insert( kombi_neu ) ;
//								}
//							}
//
//	set< vector< string > > kombiKlammern ;
//
//	for ( int s = 0 ;  s < 5 ;  ++s )
//		for ( int e = 0 ;  e < 5 ;  ++e )
//			if ( e - s > 1 )
//				if ( 4 - e - s > 0 )
//					cout << string( s, 'x' ) << "(" << string( e - s, 'x' ) << ")" << string( 4 - e - s, 'x' ) << endl ;
//				else
//					cout << string( s, 'x' ) << "(" << string( e - s, 'x' ) << ")" << endl ;
//
//	for ( int s1 = 0 ;  s1 < 5 ;  ++s1 )
//		for ( int s2 = 0 ;  s2 < 5 ;  ++s2 )
//			for ( int e1 = 0 ;  e1 < 5 ;  ++e1 )
//				for ( int e2 = 0 ;  e2 < 5 ;  ++e2 )
//
//
//
//	for ( set< vector< string > >::iterator i = kombiBuchstaben.begin() ;  i != kombiBuchstaben.end() ;  ++i )
//	{
//		
//		//for ( int j = 0 ;  j < (*i).size() ;  ++j )
//		//	cout << (*i).at( j ) << " " ;
//		//cout << endl ;
//	}
//
//	cout << kombiBuchstaben.size() << endl ;
//	return 0 ;
//}