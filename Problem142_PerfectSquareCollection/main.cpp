#include <iostream>
#include "stoppUhr.h"
using namespace std ;

typedef unsigned long long ULL ;
int main ()
{
	stoppUhr( START ) ;

	for ( ULL x = 2 ;  x <= 5000 ;  ++x )
		for ( ULL y = 1 ;  y < x ;  ++y )
		{
			double sqrt_xpy = sqrt( double( x + y ) ) ;
			if ( sqrt_xpy == int( sqrt_xpy ) )
			{
				ULL a1_s = sqrt_xpy ;
				double sqrt_xmy = sqrt( double( x - y ) ) ;
				if ( sqrt_xmy == int( sqrt_xmy ) )
				{

					for ( ULL z = 1 ;  z < y ;  ++z )
					{

						double sqrt_xpz = sqrt( double( x + z ) ) ;
						if ( sqrt_xpz == int( sqrt_xpz ) )
						{
							double sqrt_xmz = sqrt( double( x - z ) ) ;
							if ( sqrt_xmz == int( sqrt_xmz ) )
							{
								double sqrt_ypz = sqrt( double( y + z ) ) ;
								if ( sqrt_ypz == int( sqrt_ypz ) )
								{
									//cout << x + y + z << endl ;
									double sqrt_ymz = sqrt( double( y - z ) ) ;
									if ( sqrt_ymz == int( sqrt_ymz ) )
									{
										cout << x + y + z << endl ;
									}
								}
							}
						}
					}
					}
			}
		}

	cout << stoppUhr( STOPP ) << "s" << endl ;


	//stoppUhr( START ) ;
	//int const MAX_a = 500 ;

	//for ( int a1 = 1 ;  a1 <= MAX_a ;  ++a1 )
	//{
	//	ULL a1_s	= a1 * a1 ;

	//	ULL min_x   = ceil( a1_s / 2. ) ;
	//	ULL max_x   = a1_s - 1 ;

	//	ULL max_y	= a1_s / 2 ;
	//	ULL min_y	= 1 ;

	//	for ( ULL x = min_x ;  x <= max_x ;  ++x )
	//		for ( ULL y = min_y ;  y <= max_y ;  ++y )
	//			if ( ( x + y ) == a1_s && y < x )
	//			{
	//				ULL a2_s = a1_s - 2 * y ;
	//				double sqrt_a2_s = sqrt( double( a2_s ) ) ;

	//				if ( sqrt_a2_s == int( sqrt_a2_s ) ) // x, y gefunden, so dass x + y = a1^2 und x - y = a2^2
	//				{
	//					for ( ULL a3 = 1 ;  a3 <= MAX_a ;  ++a3 )
	//					{
	//						ULL a3_s = a3 * a3 ;

	//						ULL max_z = ( a3 * a3 ) / 2 ;
	//						ULL min_z = 1 ;

	//						for ( ULL z = min_z ;  z <= max_z ;  ++z )
	//						{
	//							if ( ( x + z ) == a3_s && z < y && z < x )
	//							{
	//								double a4 = sqrt( double( x - z ) ) ;
	//								if ( a4 == int( a4 ) )
	//								{
	//									double a5 = sqrt( double( y + z ) ) ;
	//									if ( a5 == int( a5 ) )
	//									{
	//										double a6 = sqrt( double( y - z ) ) ;
	//										if ( a6 == int( a6 ) )
	//										{
	//								cout << x << " + " << y << " = " << a1_s << endl ;
	//								cout << x << " - " << y << " = " << a2_s << endl ;
	//								cout << x << " + " << z << " = " << a3_s << endl ;
	//								cout << x << " - " << z << " = " << a4*a4 << endl ;
	//								cout << y << " + " << z << " = " << a5 * a5 << endl ;
	//								cout << y << " - " << z << " = " << a6 * a6 << endl ;												
	//										}
	//									}

	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//}

	//cout << stoppUhr( STOPP ) << "s" << endl ;



	//stoppUhr( START ) ;
	//ULL it = 0 ;

	//for ( int a1 = 2 ;  a1 <= 500 ;  ++a1 ) // erstmal nur für gerade a1
	//{
	//	ULL a1_s	= a1 * a1 ; // a1^2

	//	ULL min_x   = ceil( a1_s / 2. ) ;
	//	ULL max_x   = a1_s - 1 ;

	//	ULL max_y	= a1_s / 2 ;
	//	ULL min_y	= 1 ;

	//	for ( ULL x = min_x ;  x <= max_x ;  ++x )
	//		for ( ULL y = min_y ;  y <= max_y ;  ++y )
	//			if ( ( x + y ) == a1_s && y < x ) // a1^2 gefunden!
	//			{
	//				ULL a2_s = a1_s - 2 * y ;

	//				double sqrt_a2_s = sqrt( double( a2_s ) ) ;
	//				if ( sqrt_a2_s == int( sqrt_a2_s ) )
	//				{
	//					for ( ULL z = y - 1 ;  z > 0 ;  --z )
	//					{
	//						ULL a3_s = z + ( a2_s + a1_s ) / 2 ;
	//						double sqrt_a3_s = sqrt( double( a3_s ) ) ;
	//						if ( sqrt_a3_s == int( sqrt_a3_s ) )
	//						{
	//							ULL a4_s = a1_s + a2_s - a3_s ;
	//							double sqrt_a4_s = sqrt( double( a4_s ) ) ;

	//							if ( sqrt_a4_s == int( sqrt_a4_s ) )
	//							{
	//								ULL a5_s = a3_s - a2_s ;
	//								double sqrt_a5_s = sqrt( double( a5_s ) ) ;

	//								if ( sqrt_a5_s == int( sqrt_a5_s ) )
	//								{
	//									ULL a6_s = a1_s - a3_s ;
	//									double sqrt_a6_s = sqrt( double( a6_s ) ) ;

	//									if ( sqrt_a6_s == int( sqrt_a6_s ) )
	//									{
	//										cout << x << " + " << y << " = " << a1_s << endl ;
	//										cout << x << " - " << y << " = " << a2_s << endl ;
	//										cout << x << " + " << z << " = " << a3_s << endl ;
	//										cout << x << " - " << z << " = " << a4_s << endl ;
	//										cout << y << " + " << z << " = " << a5_s << endl ;
	//										cout << y << " - " << z << " = " << a6_s << endl << endl ;
	//										++it ;
	//									}
	//								}
	//							}
	//						}
	//					}

	//					

	//				}
	//				
	//			}
	//}

	//cout << it << endl ;
	//cout << stoppUhr( STOPP ) << "s" << endl ;
	return 0 ;
}