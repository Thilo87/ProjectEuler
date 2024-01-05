/*

By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

Although there exists no rectangular grid that contains exactly two million rectangles,
find the area of the grid with the nearest solution.

*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std ;

int main ()
{
	int minD = INT_MAX ;

	int maxN = 0 ;
	int maxh = 0 ;
	int maxb = 0 ;

	for ( int h = 1 ;  h < 300 ;  ++h )
		for ( int b = h ;  b < 300 ;  ++b )
		{
			int N = 0 ;
			for ( int hR = 1 ;  hR <= h ;  ++hR )
				for ( int bR = 1 ;  bR <= b ;  ++bR )
					N += ( h - hR + 1 ) * ( b - bR + 1 ) ;

			int D = abs( 2000000 - N ) ;
			if ( D < minD )
			{
				minD = D ;
				maxN = N ;
				maxh = h ;
				maxb = b ;
			}
		}

	cout << "maxN = " << maxN << ", maxh * maxb = " << maxh * maxb << endl ;
	return 0 ;
}