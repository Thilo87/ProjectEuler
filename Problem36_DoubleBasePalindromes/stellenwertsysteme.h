#include <cmath>
#include <vector>
#include <iostream>
using namespace std ;

// wandelt eine Dezimalzahl in eine Binärzahl um
char* dez_in_bin( unsigned long long n ) ;
vector< int > dez_in_bin_v( unsigned long long n ) ; // gibt vector< int > zurück


// wandelt eine Binärzahl in eine Dezimalzahl um
unsigned long long bin_in_dez( char const* n ) ;
unsigned long long bin_in_dez_v( vector< int > const& n ) ;
