/*

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume
that a number is Lychrel until proven otherwise. In addition you are given that for every number below
ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one,
with all the computing power that exists, has managed so far to map it to a palindrome.
In fact, 10677 is the first number to be shown to require over fifty iterations before producing
a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.


*/

#include <iostream>
#include "natuerlicheZahl.h"
using namespace std ;

// gibt die i-te Ziffer von n zurück
int iteZiffer( int i, long long n )
{
	return int( ( n % int( pow(10., i) ) ) / pow( 10., i-1 ) ) ;
}

// ist n ein Palindrom ?
bool istPalindrom( long long n )
{
	int ziffern = log10( double( n ) ) + 1 ;

	for ( int i = 1 ;  i <= ziffern / 2 ;  ++i )
		if ( iteZiffer( i, n ) != iteZiffer( ziffern - i + 1, n ) )
			return false ;
	return true ;
}

// kehrt die Ziffernreihenfolge in n um und gibt das Ergebnis zurück
long long umkehren( long long n )
{
	int ziffern = log10( double( n ) ) + 1 ;

	long long umgekehrteZahl = 0 ;
	for ( int i = 0 ;  i < ziffern ;  ++i )
		umgekehrteZahl += ( int( n / pow( 10., i ) ) % 10 ) * pow( 10., ziffern - i - 1 ) ;

	return umgekehrteZahl ;
}

natuerlicheZahl umkehren( natuerlicheZahl& const n )
{
	int ziffern = n.getZiffernanzahl() ;
	
	natuerlicheZahl umgekehrteZahl( n ) ;
	for ( int i = 0 ;  i < ziffern / 2 ;  ++i )
	{
		int tmp = umgekehrteZahl.getZiffer( ziffern - i - 1 ) ;
		umgekehrteZahl.setZiffer( ziffern - i - 1 , umgekehrteZahl.getZiffer( i ) ) ;
		umgekehrteZahl.setZiffer( i , tmp ) ;
	}

	return umgekehrteZahl ;
}

bool istPalindrom( natuerlicheZahl& const n )
{
	int ziffern = n.getZiffernanzahl() ;

	for ( int i = 0 ;  i <= ziffern / 2 ;  ++i )
		if ( n.getZiffer( i ) != n.getZiffer( ziffern - i - 1 ) )
			return false ;
	return true ;
}

bool istLychrelZahl( natuerlicheZahl& const n )
{
	natuerlicheZahl kopie( n ) ;
	for ( int iterationen = 1 ;  iterationen < 50 ;  ++iterationen )
	{
		kopie = kopie + umkehren( kopie ) ;
		if ( istPalindrom( kopie ) )
			return false ;
	}

	return true ;
}

// überprüft, ob eine Zahl n < 10000 eine Lychrel-Zahl ist. Das ist sie ( vermutlich ),
// wenn sie in weniger als 50 Iterationen kein Palindrom geworden ist.
bool istLychrelZahl( long long n )
{
	for ( int iterationen = 1 ;  iterationen < 50 ;  ++iterationen )
	{
		n += umkehren( n ) ;
		cout << n << endl ;
		if ( istPalindrom( n ) )
			return false ;
	}

	return true ;
}

int main ()
{
	int lychrelZahlen = 0 ;

	for ( int i = 1 ;  i < 10000 ;  ++i )
	{
		natuerlicheZahl n( i ) ;
		if ( istLychrelZahl( n ) )
			++lychrelZahlen ;
	}

	cout << lychrelZahlen ;
	return 0 ;
}