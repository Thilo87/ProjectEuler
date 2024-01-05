#include <iostream>
#include <cmath>

using namespace std ;

// Ende-Zeichen f�r Ziffernfolge im natuerlich-Format
int const ENDE     = -1 ;

// 0 und 1 im natuerlich-Format
int const dieNull[] = { 0, ENDE } ;
int const dieEins[] = { 1, ENDE } ;

// gib die Anzahl signifikanter Ziffern von zahl zur�ck
int laenge ( int const zahl[] ) ;

// wandle Text in eine neue Zahl um
int* zuZahl ( char const text[] ) ;

// wandle Zahl in statischen Text um
// Achtung: der Wert ist nur stabil bis zum n�chsten Aufruf
char const* zuText ( int const zahl[] ) ;

// addiere zahl1 + zahl2 zu einer neuen Zahl
int* addiere ( int const zahl1[], int const zahl2[] ) ;

// subtrahiere zahl1 - zahl2 zu einer neuen Zahl,
// gebe NULL zur�ck, wenn zahl1 < zahl2 ist
int* subtrahiere ( int const zahl1[], int const zahl2[] ) ;

// gebe neue Zahl mit demselben Wert wie zahl zur�ck
static
int* kopiere ( int const zahl[] ) ;

// vergleiche zahl1 und zahl2 nach Gr��e
// Antwort: -1, falls zahl1 <  zahl2
//           0, falls zahl1 == zahl2
//           1, falls zahl1 >  zahl2
int vergleiche ( int const zahl1[], int const zahl2[] ) ;

// gib ggT( zahl1, zahl2 ) als neue Zahl zur�ck
int* ggT ( int const zahl1[], int const zahl2[] ) ;

// multipliziere zahl1 * zahl2 zu einer neuen Zahl
int* multipliziere ( int const zahl1[], int const zahl2[] ) ;

// berechne Potenz zahl hoch n in eine neue Zahl,
// gib NULL zur�ck, wenn Exponent negativ ist
int* potenz ( int const zahl[], int n ) ;
