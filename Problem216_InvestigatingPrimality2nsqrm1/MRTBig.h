#include <iostream>
#include <ttmath\ttmath.h>
using namespace std ;

typedef ttmath::Int< 10 > BigInteger ;
typedef ttmath::Big< 10, 1 > BigFloat ;
typedef unsigned long long uint64 ;

/* MILLER-RABIN-PRIMZAHLTEST */

// gibt true zur�ck, falls n als zusammengesetzt erkannt wird
// gibt false zur�ck, falls n prim oder pseudoprim zur Basis a ist
static
	bool zeuge( BigInteger a, BigInteger n ) ;

// gibt sicher zur�ck, ob n nach dem deterministischen Miller-Rabin-Primzahltest eine Primzahl ist
bool istPrim_MRD( BigInteger n ) ;