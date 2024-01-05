#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

// ist lhs > rhs ?
bool operator>( string& lhs, string& rhs ) ;

// ist lhs < rhs ?
bool operator<( string& lhs, string& rhs ) ;

// ist lhs = rhs ?
bool operator==( string& lhs, string& rhs ) ;

// ist lhs >= rhs ?
bool operator>=( string& lhs, string& rhs ) ;

// ist lhs <= rhs ?
bool operator<=( string& lhs, string& rhs ) ;

// Berechnet minuend - subtrahend, wobei minuend >= subtrahend sein muss
string sub( string minuend, string subtrahend ) ;

// Berechnet ersterSummand + zweiterSummand
string add( string ersterSummand, string zweiterSummand ) ;

// Führt eine Division mit Rest dividend / divisior aus, wobei pair< Ganzzahliger Anteil, Rest > ausgegeben wird
pair< string, string > div( string dividend, string divisor ) ;