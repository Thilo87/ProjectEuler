//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <set>
//using namespace std ;
//
//bool bouncy( string z, int pos, set< int >& bouncyNumbers )
//{
//	if ( pos == z.size() )
//	{
//		
//		int bn = 0 ;
//		int zp = z.size() - 3 ;
//		for ( int i = 0 ;  i < z.size() ;  ++i )
//		{
//			if ( z.at( i ) == 'r' || z.at( i ) == 'h' )
//				continue ;
//
//			bn += ( z.at( i ) - '0' ) * pow( 10., zp ) ;
//			--zp ;
//		}
//
//		bouncyNumbers.insert( bn ) ;
//		
//
//		return true ;
//	}
//
//	int i = 0 ;
//	if ( pos == 0 )
//		i = 1 ;
//
//	int pos_add = 1 ;
//	if ( z.at( pos ) == 'h' )
//	{
//		i = z.at( pos - 1 ) - '0' + 1 ;
//		++pos_add ;
//
//		for ( ;  i <= 9 ;  ++i )
//		{
//			z.at( pos + pos_add - 1 ) = i + '0' ;
//			if ( !bouncy( z, pos + pos_add, bouncyNumbers ) )
//				z.at( pos + pos_add - 1 ) = '*' ;
//		}
//	}
//	else if ( z.at( pos ) == 'r' )
//	{
//		i = z.at( pos - 1 ) - '0' - 1 ;
//		++pos_add ;
//
//		for ( ;  i >= 0 ;  --i )
//		{
//			z.at( pos + pos_add - 1 ) = i + '0' ;
//			if ( !bouncy( z, pos + pos_add, bouncyNumbers ) )
//				z.at( pos + pos_add - 1 ) = '*' ;
//		}
//	}
//	else
//	{
//		for ( ;  i <= 9 ;  ++i )
//		{
//			z.at( pos + pos_add - 1 ) = i + '0' ;
//			if ( !bouncy( z, pos + pos_add, bouncyNumbers ) )
//				z.at( pos + pos_add - 1 ) = '*' ;
//		}
//	}
//
//	return false ;
//
//}
//
//int main ()
//{
//	int n = 0 ;
//	for ( int i = 3 ;  true ;  ++i )
//	{
//		set< int > bouncyNumbers ;
//
//		// Grundmuster erzeugen
//		string z ;
//		for ( int j = 0 ;  j < i ;  ++j )
//			z.push_back( '*' ) ;
//		z.push_back( 'h' ) ;
//		z.push_back( 'r' ) ;
//
//		do
//		{
//			if ( z.front() == '*' && z.back() == '*' ) // gültige Muster für Bouncy-Numbers erzeugen
//				if ( z.at( z.find( 'h' ) + 1 ) != 'r' )
//					if ( z.at( z.find( 'r' ) + 1 ) != 'h' )
//					{
//						// nach dem Muster z rekursiv alle möglichen Bouncy-Numbers erzeugen
//						bouncy( z, 0, bouncyNumbers ) ;
//					}
//		}
//		while ( next_permutation( z.begin(), z.end() ) ) ;
//
//		n += bouncyNumbers.size() ;
//		double prop = n / pow( 10., i ) ;
//		
//		if ( prop >= 0.99 )
//		{
//			cout << i << endl ;
//			break ;
//		}
//	}
//
//
//
//	return 0 ;
//}