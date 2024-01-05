/*

Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include <iostream>
#include <vector>
using namespace std ;

// berechnet den Binomialkoeffizienten n über k
long long binom ( int n, int k )
{
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

int main ()
{
	cout << binom( 40, 20 ) << endl ;

	return 0 ;
}