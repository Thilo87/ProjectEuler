/*

The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link
back to 169; it turns out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain
with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?

*/

#include <iostream>
#include <vector>
using namespace std ;

unsigned int fak[ 10 ] = { 1, 1, 2, 2*3, 2*3*4, 2*3*4*5, 2*3*4*5*6,
						   2*3*4*5*6*7, 2*3*4*5*6*7*8, 2*3*4*5*6*7*8*9 } ;

unsigned long long ziffernFakultaet( unsigned int n )
{
	unsigned long long ergebnis = 0 ;
	
	while ( n > 0 )
	{
		ergebnis += fak[ n % 10 ] ;
		n /= 10 ;
	}

	return ergebnis ;
}

// suche n im Vector v und gebe true zurück, falls n gefunden wurde, sonst false
int suche( unsigned long long n, vector< unsigned long long > const& v )
{
	for ( int i = 0 ;  i < v.size() ;  ++i )
		if ( v.at( i ) == n )
			return i ;

	return -1 ;
}

int const MAX_KETTENGLIED = 200000000 ;
unsigned int kettenlaengen[ MAX_KETTENGLIED ] = { 0 } ;
unsigned int endglied[ MAX_KETTENGLIED ] = { 0 } ;

int main ()
{
	unsigned long long n ;
	for ( unsigned long long i = 1 ;  i < 1000000 ;  ++i )
	{
		n = i ;

		vector< unsigned long long > kettenglieder ;
		int periodenstelle ;
		while ( true )
		{
			kettenglieder.push_back( n ) ;
			n = ziffernFakultaet( n ) ;

			if ( kettenlaengen[ n ] != 0 )
			{
				for ( int i = 0 ;  i < kettenglieder.size() ;  ++i )
				{
					if ( endglied[ n ] == kettenglieder.at( i ) )
					{
						kettenlaengen[ kettenglieder.at( i ) ] = kettenlaengen[ n ] + kettenglieder.size() - i - 1 ;
					}
					else
						kettenlaengen[ kettenglieder.at( i ) ] = kettenlaengen[ n ] + kettenglieder.size() - i ;

					if ( kettenglieder.at( i ) != endglied[ n ] )
						endglied[ kettenglieder.at( i ) ] = endglied[ n ] ;
				}

				break ;
			}
		
			periodenstelle = suche( n, kettenglieder ) ;
			if ( periodenstelle != -1 )
			{
				for ( int i = 0 ;  i < kettenglieder.size() ;  ++i )
				{
					if ( kettenglieder.at( i ) < MAX_KETTENGLIED )
					{
						if ( kettenlaengen[ kettenglieder.at( i ) ] == 0 )
							if ( i < periodenstelle )
							{
								kettenlaengen[ kettenglieder.at( i ) ] = kettenglieder.size() - i ;
								endglied[ kettenglieder.at( i ) ] = kettenglieder.at( kettenglieder.size() - 1 ) ;
							}
							else
							{
								kettenlaengen[ kettenglieder.at( i ) ] = kettenglieder.size() - periodenstelle ;
								if ( i == periodenstelle )
									endglied[ kettenglieder.at( i ) ] = kettenglieder.at( kettenglieder.size() - 1 ) ;
								else if ( !( periodenstelle == 0 && i == 0 ) )
									endglied[ kettenglieder.at( i ) ] = kettenglieder.at( i - 1 ) ;
								else
									endglied[ kettenglieder.at( i ) ] = kettenglieder.at( periodenstelle ) ;
							}
					}
					else
						cerr << "Fehler: Ueberlauf bei Kettengliedern!" << endl ;
				}

				break ;
			}
		}
	}

	int anzahl = 0 ;
	for ( int i = 0 ;  i < MAX_KETTENGLIED ;  ++i )
		if ( kettenlaengen[ i ] == 60 )
			++anzahl ;

	cout << anzahl << endl ;

	return 0 ;
}