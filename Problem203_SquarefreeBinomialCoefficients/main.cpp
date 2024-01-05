#include <iostream>
#include "primzahlen.h"
#include <map>
#include <set>
using namespace std ;

typedef unsigned long long uint64 ;

map< uint64, uint64 > faktorisieren( int n, vector< int >& primzahlen )
{
	map< uint64, uint64 > primfaktoren ;

	for ( int i = 0 ;  primzahlen.at( i ) <= n ;  ++i )
	{
		uint64 e = 0 ;
		for ( uint64 p = primzahlen.at( i ) ;  p <= n ;  p *= primzahlen.at( i ) )
			e += n / p ;

		primfaktoren[ primzahlen.at( i ) ] = e ;
	}

	return primfaktoren ;
}

bool quadratFrei( int n, int k, vector< int >& primzahlen )
{
	map< uint64, uint64 > n_pf = faktorisieren( n, primzahlen ) ;
	map< uint64, uint64 > k_pf = faktorisieren( k, primzahlen ) ;
	map< uint64, uint64 > nmk_pf = faktorisieren( n - k, primzahlen ) ;

	for ( map< uint64, uint64 >::iterator i = k_pf.begin() ;  i != k_pf.end() ;  ++i )
		n_pf[ (*i).first ] -= (*i).second ;

	for ( map< uint64, uint64 >::iterator i = nmk_pf.begin() ;  i != nmk_pf.end() ;  ++i )
		n_pf[ (*i).first ] -= (*i).second ;

	for ( map< uint64, uint64 >::iterator i = n_pf.begin() ;  i != n_pf.end() ;  ++i )
		if ( (*i).second >= 2 )
			return false ;

	return true ;
}

// berechnet den Binomialkoeffizienten n über k
long long binom ( int n, int k )
{
	if ( n == 0 && k == 0 )
		return 1 ;

	if ( k == 0 )
		return 1 ;
	if ( k == 1 )
		return n ;
	if ( n == k )
		return 1 ;

	// die Verwendung von unsigned long long, auch wenn der Rückgabewert der Funktion vom Typ long long ist,
	// ist hier legitim, da b immer nichtnegativ ist ( weil n >= k ) und beim Zurückgeben long long so oder so
	// überlaufen würde, wenn das Ergebnis größer als der Wertebereich von long long ist. Der Cast von unsigned long long
	// in long long stellt in dieser Hinsicht also kein Problem dar.
	unsigned long long b = n - k + 1 ;

	// es wurde hier der rekursive Algorithmus
	// [ n , 0 ] := 1 ;		[ n , k ] := ( ( n - k + 1 ) / k ) * [ n , k - 1 ]
	// umgesetzt.
	// Um Zwischenergebnisse klein zu halten, wurde die Reihenfolge der Fakultät im Nenner einfach umgekehrt und durch i ersetzt
	// und zusätzlich im Zähler, da ( n - k + 1 ) * ( n - ( k - 1 ) + 1 ) * ( n - ( k - 2 ) + 1 ) * ... = 
	// ( n - k + 1 ) * ( n - k + 2 ) * ( n - k + 3 ) * ... als numerischer Wert die Laufvariable i eingesetzt. 
	// Mit a := n - k ist nämlich ( a + 1 ) * ( a + 2 ) durch 2! teilbar, ( a + 1 ) * ( a + 2 ) * ( a + 3 ) durch 3! teilbar, 
	// allg. ( a + 1 ) * ... * ( a + j ) ist immer durch j! teilbar.
	// 
	// Damit ist im Folgenden b * ( n - k ) also immer durch die Laufvariable i teilbar.
	for ( int i = 2 ;  i <= k ;  ++i )
	{
		// temporäre Variablen, die für die nachfolgenden Schritte benötigt werden
		int i_temp =					i ;
		unsigned long long b_temp =		b ;
		int n_minus_k_temp =			n - k ;

		// Das Problem ist, dass b * ( n - k ) oft einen Überlauf erzeugt. Im Folgenden werden daher
		// die Faktoren von i durchlaufen und geprüft, ob b oder ( n - k ) durch diesen Faktor von i teilbar ist.
		// Es erfolgt also eine schrittweise Kürzung der Faktoren von i und b bzw. ( n - k ), was den Überlauf verhindert.
		for ( int l = 2 ;  i_temp != 1 ;  ++l ) // die Schleife terminiert, da b * ( n - k ) restlos durch i teilbar ist
		{
			if ( i_temp % l == 0 ) // ist l ein Faktor von i_temp?
			{
				if ( n_minus_k_temp % l == 0 ) // ist l ein Faktor von n_minus_k_temp?
					n_minus_k_temp /= l ;
				else // da l kein Faktor von ( n - k ) ist, muss l ein Faktor von b sein
					b_temp /= l ;

				i_temp /= l ;

				l = 1 ; // For-Schleife von Vorne beginnen !
			}
		} // for ()


		b = ( b_temp * n_minus_k_temp ) + b ;
	} // for ()
	
	return b ;
}  // binom()

int main()
{
	vector< int > primzahlen = primzahlliste( 10000 ) ;
	set< uint64 > quadratfreieBinome ;

	for ( int n = 0 ;  n < 51 ;  ++n )
		for ( int k = 0 ;  k <= n ;  ++k )
			if ( quadratFrei( n, k, primzahlen ) )
				quadratfreieBinome.insert( binom( n, k ) ) ;

	uint64 summe = 0 ;
	for ( set< uint64 >::iterator i = quadratfreieBinome.begin() ;  i != quadratfreieBinome.end() ;  ++i )
		summe += (*i) ;
	cout << summe << endl ;

	return 0 ;
}