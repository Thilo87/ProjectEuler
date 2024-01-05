#include <cmath>
#include <iostream>
#include <vector>
using namespace std ;

// gibt ein bool-Array zur�ck, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( unsigned int n ) ;

// gibt in einem Vektor die Primzahlen, die von 2 bis n vorkommen, zur�ck
// verwendet dabei das Sieb des Eratosthenes
vector< int > primzahlliste( unsigned int n ) ;


// gibt die Anzahl der Teiler von n zur�ck
// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schlie�lich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n ) ;

// gibt die Teilersumme von n zur�ck
unsigned long long teilersumme( unsigned long long n ) ;

// gibt die echte Teilersumme von n zur�ck, d.h. die Teilersumme von n abz�glich n
unsigned long long echteTeilersumme( unsigned long long n ) ;

