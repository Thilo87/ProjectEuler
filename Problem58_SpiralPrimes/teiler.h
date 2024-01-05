#include <cmath>
#include <iostream>
using namespace std ;

// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schlie�lich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n ) ;

// gibt ein bool-Array zur�ck, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( int n ) ;

// gibt die Teilersumme von n zur�ck
unsigned long long teilersumme( unsigned long long n ) ;

// gibt die echte Teilersumme von n zur�ck, d.h. die Teilersumme von n abz�glich n
unsigned long long echteTeilersumme( unsigned long long n ) ;