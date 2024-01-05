#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

int main ()
{
	for ( int n1 = 1 ;  n1 <= 10 ;  ++n1 )
		for ( int n6 = 1 ;  n6 <= 10 ;  ++n6 )
			if ( n6 != n1 )
				for ( int n2 = 1 ;  n2 <= 10 ;  ++n2 )
					if ( n2 != n1 && n2 != n6 )
						for ( int n8 = 1 ;  n8 <= 10 ;  ++n8 )
							if ( n8 != n1 && n8 != n2 && n8 != n6 )
								if ( n1 + n6 == n2 + n8 )
									for ( int n5 = 1 ;  n5 <= 10 ;  ++n5 )
										if ( n5 != n1 && n5 != n6 && n5 != n2 && n5 != n8 )
											for ( int n9 = 1 ;  n9 <= 10 ;  ++n9 )
												if ( n9 != n1 && n9 != n2 && n9 != n8 && n9 != n6 && n9 != n5 )
													for ( int n4 = 1 ;  n4 <= 10 ;  ++n4 )
														if ( n4 != n9 && n4 != n5 && n4 != n8 && n4 != n2 && n4 != n6 && n4 != n1 )
															if ( n5 + n6 == n9 + n4 )
																for ( int n3 = 1 ;  n3 <= 10 ;  ++n3 )
																	if ( n3 != n9 && n3 != n5 && n3 != n8 && n3 != n2 && n3 != n6 && n3 != n1 && n3 != n4 )
																		for ( int n7 = 1 ;  n7 <= 10 ;  ++n7 )
																			if ( n7 != n9 && n7 != n5 && n7 != n8 && n7 != n2 && n7 != n6 && n7 != n1 && n7 != n4 && n7 != n3 )
																				if ( n3 + n9 == n2 + n7 )
																					for ( int n10 = 1 ;  n10 <= 10 ;  ++n10 )
																						if ( n10 != n9 && n10 != n5 && n10 != n8 && n10 != n2 && n10 != n6 && n10 != n1 && n10 != n4 && n10 != n3 && n10 != n7 )
																							if ( n3 + n8 == n4 + n10 )
																								if ( n5 + n10 == n1 + n7 )
																							{
																								ttmath::Int< 100 > zahl = ( n1 * 100 + n6 * 10 + n7 ) ;
																								zahl *= 1000 ;
																								zahl += ( n2 * 100 + n7 * 10 + n8 ) ;
																								zahl *= 1000 ;
																								zahl += ( n3 * 100 + n8 * 10 + n9 ) ;
																								zahl *= 1000 ;
																								zahl += ( n4 * 100 + n9 * 10 + n10 ) ;
																								zahl *= 1000 ;
																								zahl += ( n5 * 100 + n10 * 10 + n6 ) ;
																								if ( zahl / 1000000000000000 > 0 )
																									cout << zahl << endl ;
																							}
	return 0 ;
}