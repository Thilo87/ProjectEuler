/*

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,
nCr = 	
n!
r!(n−r)!
	,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?


*/

#include <iostream>
#include <cmath>
using namespace std ;

// berechnet den Binomialkoeffizienten n über k
long long nCr ( int n, int k )
{
	if ( k == 0 )
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

int main ()
{
	int anzahl = 0 ;

	for ( int n = 23 ;  n <= 100 ;  ++n )
	{
		int r = 0 ;
		while ( nCr( n, r ) <= 1000000 && r <= n )
			++r ;

		anzahl += n + 1 - 2*r ;
		//cout << r << endl ;
	}

	cout << anzahl << endl ;

	return 0 ;
}