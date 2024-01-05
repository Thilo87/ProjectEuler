#include <iostream>
#include <ttmath\ttmath.h>
#include <stdlib.h>
#include <cmath>
#include <tuple>

typedef ttmath::Int< 100 > bint ;

// steinscher Algorithmus um den ggT( a, b ) zu berechnen
bint ggT_Stein( bint a, bint b ) ;

// gibt ein Tripel ( ggT( a, b ), s, t ) zur�ck, wobei ggT( a, b ) = s * a + t * b
std::tuple< bint, bint, bint > erwEuklidAlgo( bint a, bint b ) ;

// gibt die L�sungsmenge der linearen Kongruenz ax kongruent c ( mod m ) als
// 2-Tupel ( x0, v ) zur�ck, wobei die L�sungsmenge L = { x0 + v * n | n ganze Zahl } ist.
std::tuple< bint, bint > lineareKongruenz( bint a, bint c, bint m ) ;

// gibt die L�sungsmenge der linearen diophantischen Gleichung ax + by = c als Tupel
// ( x_speziell, v_x, y_speziell, v_y ) zur�ck. Dann ist die L�sungsmenge
// L = { ( x_speziell + v_x * n, y_speziell + v_y * n ) | n ganze Zahl }
std::tuple< bint, bint, bint, bint > diophGleichung( bint a, bint b, bint c ) ;