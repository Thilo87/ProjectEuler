#include <ttmath\ttmath.h>
#include <iostream>
#include <vector>
using namespace std ;

// gibt den Z�hler der n-ten Konvergente der regul�ren Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zur�ck
ttmath::Int< 100 > konvergente_p( vector< int > const& b, unsigned int n ) ;

// gibt den Nenner der n-ten Konvergente der regul�ren Kettenbruchentwicklung [ b0; b1, b2, b3, ... ] zur�ck
ttmath::Int< 100 > konvergente_q( vector< int > const& b, unsigned int n ) ;

// gibt die Teilnenner der Kettenbruchentwicklung von sqrt( n ) zur�ck. Dabei wird bei nicht-quadratischen Zahlen
// die Periode nur einmal angegeben, womit die Periodenl�nge gleich die L�nge des Vectors - 1 ist.
vector< int > kettenbruch_sqrt( unsigned int n ) ;