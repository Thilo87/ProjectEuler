#include <iostream>
#include <vector>
#include "primzahlen.h"
#include <ttmath\ttmath.h>

using namespace std ;

typedef unsigned int uint32 ;
typedef int int32 ;

int const LIMIT = 120000 ;
vector< vector< pair< uint32, uint32 > > > PF( LIMIT ) ;

bool ggT1( uint32 rad_a, uint32 b )
{
	for ( vector< pair< uint32, uint32 > >::iterator p = PF.at( b ).begin() ;  p != PF.at( b ).end() ;  ++p )
		if ( rad_a % (*p).first == 0 )
			return false ;
	
	return true ;
}

int main()
{
	vector< int32 > P = primzahlliste( LIMIT ) ;	

	uint32 rad[ LIMIT ] ;
	for ( int i = 0 ;  i < LIMIT ;  ++i )
		rad[ i ] = 1 ;

	uint32* rest = new uint32[ LIMIT ] ;
	for ( uint32 i = 0 ;  i < LIMIT ;  ++i )
		rest[ i ] = i ;

	for ( vector< int32 >::iterator p = P.begin() ;  p != P.end() ;  ++p )
		for ( uint32 j = (*p) ;  j < LIMIT ;  j += (*p) )
		{
			uint32 e = 0 ;
			while ( rest[ j ] % (*p) == 0 )
			{
				++e ;
				rest[ j ] /= (*p) ;
			}

			if ( e > 0 )
			{
				PF.at( j ).push_back( pair< uint32, uint32 >( (*p), e ) ) ;
				rad[ j ] *= (*p) ;
			}
		}

	delete[] rest ;

	unsigned long long S = 0 ;
	for ( int b = 1 ;  b < LIMIT ;  ++b )
		for ( int a = 1 ;  a < b ;  ++a )
			if ( ggT1( rad[ a ], b ) )
			{
				int c = a + b ;
				if ( c < LIMIT )
					if ( rad[ a ] < c && rad[ b ] < c && rad[ c ] < c )
					{
						ttmath::Int< 10 > radpr = rad[ a ] ;
						radpr *= rad[ b ] ;
						radpr *= rad[ c ] ;

						if ( radpr < c )
							if ( ggT1( rad[ a ], c ) && ggT1( rad[ b ], c ) )
								S += c ;
					}
			}

	cout << S << endl ;

	//int n = 504 ;
	//for ( int i = 0 ;  i < PF.at( n ).size() ;  ++i )
	//	cout << PF.at( n ).at( i ).first << "^" << PF.at( n ).at( i ).second << " " ;

	return 0 ;
}