#include <ttmath\ttmath.h>
#include <iostream>
#include <vector>
using namespace std ;

// gibt den Zähler der n-ten Konvergente der regulären Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zurück
ttmath::Int< 100 > konvergente_p( vector< int > const& b, unsigned int n ) ;

// gibt den Nenner der n-ten Konvergente der regulären Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zurück
ttmath::Int< 100 > konvergente_q( vector< int > const& b, unsigned int n ) ;

// gibt die Teilnenner der Kettenbruchentwicklung von sqrt( n ) zurück. Dabei wird bei nicht-quadratischen Zahlen
// die Periode nur einmal angegeben, womit die Periodenlänge gleich die Länge des Vectors - 1 ist.
vector< int > kettenbruch_sqrt( unsigned int n ) ;