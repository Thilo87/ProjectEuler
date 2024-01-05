#include <cmath>
#include <iostream>
using namespace std ;

// bestimmt mit dem Sieb des Eratosthenes eine Liste von Primzahlen bis sqrt( n ).
// danach werden die Primfaktoren und deren Exponenten von n errechnet und aus diesen schließlich die Teileranzahl,
// indem die Teilerzahl d = (e1 + 1)(e2 + 1)(e3 + 1) ... ist
int teileranzahl( unsigned long long n ) ;

// gibt ein bool-Array zurück, in dem array[ i ] true ist, wenn i eine Primzahl ist
bool* siebEratosthenes( int n ) ;

// gibt die Teilersumme von n zurück
unsigned long long teilersumme( unsigned long long n ) ;

// gibt die echte Teilersumme von n zurück, d.h. die Teilersumme von n abzüglich n
unsigned long long echteTeilersumme( unsigned long long n ) ;