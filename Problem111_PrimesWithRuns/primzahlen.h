#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

// gibt ein bool-Array zur�ck, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( unsigned int n ) ;

// gibt in einem Vektor die Primzahlen, die von 2 bis n vorkommen, zur�ck
// verwendet dabei das Sieb des Eratosthenes
vector< int > primzahlliste( unsigned int n ) ;





/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zur�ck, falls n als zusammengesetzt erkannt wird
// gibt false zur�ck, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( unsigned long long a, unsigned long long n ) ;

// berechnet die Potenz n^e mod m, wobei auch sehr gro�e n und e zugelassen sind
// verwendet dabei den Square & Multiply-Algorithmus mit einer Modifikation f�r den Modulo
unsigned long long binModExponentiation( unsigned long long basis, unsigned long long exponent, unsigned int modul ) ;

// berechnet die Potenz n^e, wobei auch sehr gro�e n und e zugelassen sind
unsigned long long binExponentiation( unsigned long long basis, unsigned long long exponent ) ;

// gibt sicher zur�ck, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
bool istPrim_MRD( unsigned long long n ) ;





// gibt die Anzahl der Teiler von n zur�ck
// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schlie�lich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n ) ;

// gibt alle Teiler eine nat�rlichen Zahl n zur�ck
vector< int > teiler( unsigned long long n ) ;

// gibt die Anzahl der zu n teilerfremden Zahlen <= n zur�ck
// es ist phi( m * n ) = phi( m ) * phi( n )
unsigned long long eulerschePhiFunktion( unsigned long long n ) ;

unsigned long long eulerschePhiFunktion( unsigned long long n, bool const* istPrim ) ;

// erstellt alle Werte von phi( n ) bis zur Grenze MAX ( SEHR SCHNELL! )
vector< int > eulerschePhiFunktion( int const MAX ) ;


// gibt die Teilersumme von n zur�ck
unsigned long long teilersumme( unsigned long long n ) ;

// gibt die echte Teilersumme von n zur�ck, d.h. die Teilersumme von n abz�glich n
unsigned long long echteTeilersumme( unsigned long long n ) ;

