#include <iostream>
#include <vector>
using namespace std ;

int ggT( unsigned int a, unsigned int b )
{
	while ( a > 0 && b > 0 )
		if ( a > b )
			a %= b ;
		else
			b %= a ;

	return a + b ;
}

int main ()
{
	int n_fertig = 1 ;
	int d_fertig = 1 ;

	vector< int > ns ;
	vector< int > ds ;
	for ( int n = 10 ;  n <= 99 ;  ++n )
		for ( int d = 10 ;  d <= 99 ;  ++d )
		{
			// Ziffern von n und d ermitteln
			int ziffern_n[ 2 ] = { n / 10, n % 10 } ;
			int ziffern_d[ 2 ] = { d / 10, d % 10 } ;

			
			for ( int i = 0 ;  i < 4 ;  ++i )
			{
				int verschiedeneZiffern[ 4 ] = { ziffern_n[ 0 ], ziffern_n[ 1 ], ziffern_d[ 0 ], ziffern_d[ 1 ] } ;
				int aktZiffer = verschiedeneZiffern[ i ] ;
				if ( aktZiffer == 0 )
					break ;

				for ( int j = 0 ;  j < 4 ;  ++j )
					if ( verschiedeneZiffern[ j ] == aktZiffer )
						verschiedeneZiffern[ j ] = -1 ;
				
				if ( !( verschiedeneZiffern[ 0 ] == -1 && verschiedeneZiffern[ 1 ] == -1 ) &&
					 !( verschiedeneZiffern[ 2 ] == -1 && verschiedeneZiffern[ 3 ] == -1 ) )
				{
					int n_neu = 0, d_neu = 0 ;
					if ( verschiedeneZiffern[ 0 ] == -1 )
						n_neu = verschiedeneZiffern[ 1 ] ;
					if ( verschiedeneZiffern[ 1 ] == -1 )
						n_neu = verschiedeneZiffern[ 0 ] ;
					if ( verschiedeneZiffern[ 2 ] == -1 )
						d_neu = verschiedeneZiffern[ 3 ] ;
					if ( verschiedeneZiffern[ 3 ] == -1 )
						d_neu = verschiedeneZiffern[ 2 ] ;

					if ( n * d_neu == d * n_neu && n_neu != 0 && d_neu != 0 && n_neu / d_neu < 1 && d_neu != 1 )
					{
						bool vorhanden = false ;
						for ( int k = 0 ;  k < ns.size() ;  ++k )
							if ( ns.at( k ) == n && ds.at( k ) == d )
							{
								vorhanden = true ;
								break ;
							}

						if ( !vorhanden )
						{
							ns.push_back( n ) ;
							ds.push_back( d ) ;

							n_fertig *= n ;
							d_fertig *= d ;
						}
					}
				}
			}
		}

			d_fertig /= ggT( n_fertig, d_fertig ) ;
			cout << d_fertig << endl ;

	return 0 ;
}