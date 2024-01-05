#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

// gibt ein bool-Array zurück, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( unsigned int n ) ;

// gibt in einem Vektor die Primzahlen, die von 2 bis n vorkommen, zurück
// verwendet dabei das Sieb des Eratosthenes
vector< int > primzahlliste( unsigned int n ) ;





/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zurück, falls n als zusammengesetzt erkannt wird
// gibt false zurück, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( unsigned long long a, unsigned long long n ) ;

// berechnet die Potenz n^e mod m, wobei auch sehr große n und e zugelassen sind
// verwendet dabei den Square & Multiply-Algorithmus mit einer Modifikation für den Modulo
unsigned long long binModExponentiation( unsigned long long basis, unsigned long long exponent, unsigned int modul ) ;

// berechnet die Potenz n^e, wobei auch sehr große n und e zugelassen sind
unsigned long long binExponentiation( unsigned long long basis, unsigned long long exponent ) ;

// gibt sicher zurück, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
bool istPrim_MRD( unsigned long long n ) ;





// gibt die Anzahl der Teiler von n zurück
// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schließlich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n ) ;

// gibt alle Teiler eine natürlichen Zahl n zurück
vector< int > teiler( unsigned long long n ) ;

// gibt die Anzahl der zu n teilerfremden Zahlen <= n zurück
// es ist phi( m * n ) = phi( m ) * phi( n )
unsigned long long eulerschePhiFunktion( unsigned long long n ) ;

unsigned long long eulerschePhiFunktion( unsigned long long n, bool const* istPrim ) ;

// erstellt alle Werte von phi( n ) bis zur Grenze MAX ( SEHR SCHNELL! )
vector< int > eulerschePhiFunktion( int const MAX ) ;


// gibt die Teilersumme von n zurück
unsigned long long teilersumme( unsigned long long n ) ;

// gibt die echte Teilersumme von n zurück, d.h. die Teilersumme von n abzüglich n
unsigned long long echteTeilersumme( unsigned long long n ) ;

