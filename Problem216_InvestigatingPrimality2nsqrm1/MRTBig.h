#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

typedef ttmath::Int< 10 > BigInteger ;
typedef ttmath::Big< 10, 1 > BigFloat ;
typedef unsigned long long uint64 ;

/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zurück, falls n als zusammengesetzt erkannt wird
// gibt false zurück, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( BigInteger a, BigInteger n ) ;

// gibt sicher zurück, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
bool istPrim_MRD( BigInteger n ) ;