#include <iostream>
#include <cmath>
using namespace std ;

class natuerlicheZahl
{
public:
	// Konstruktoren
	natuerlicheZahl() ;	// die Zahl wird mit 0 initialisiert
	natuerlicheZahl( unsigned long long zahl ) ;
	natuerlicheZahl( char const* zahl ) ;
	natuerlicheZahl( natuerlicheZahl const& zahl ) ; // Kopierkonstruktor

	// Destruktor
	~natuerlicheZahl() ;

	// gibt diese natuerliche Zahl auf cout aus
	void ausgeben() ;

	// mathematische Operationen
	void addiere( natuerlicheZahl const& zahl ) ;
	void multipliziere( natuerlicheZahl const& zahl ) ;

	// Vergleichsoperationen
	bool istKleiner( natuerlicheZahl const& zahl ) ;		// ist diese Zahl < zahl ?
	bool istKleinerGleich( natuerlicheZahl const& zahl ) ;	// ist diese Zahl <= zahl ?
	bool istGleich( natuerlicheZahl const& zahl ) ;			// ist diese Zahl == zahl ?

	// Operatoren
	natuerlicheZahl& operator=( natuerlicheZahl const& rhs ) ; // Zuweisungsoperator
	natuerlicheZahl& operator=( unsigned long long rhs ) ;

	// Getter
	int getZiffernanzahl() { return ziffernanzahl ; } ;
	int getZiffer( int stelle ) { return ziffern[ stelle ] ; } ;

private:
	int* ziffern ;			// Ziffern der Zahl
	int ziffernanzahl ;		// Anzahl der Ziffern der Zahl

} ;

// Operatoren für die Multiplikation 
natuerlicheZahl operator*( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ;
natuerlicheZahl operator*( natuerlicheZahl const& lhs, unsigned long long rhs ) ;
natuerlicheZahl operator*( unsigned long long lhs, natuerlicheZahl const& rhs ) ;

// Operatoren für die Addition
natuerlicheZahl operator+( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ;
natuerlicheZahl operator+( natuerlicheZahl const& lhs, unsigned long long rhs ) ;
natuerlicheZahl operator+( unsigned long long lhs, natuerlicheZahl const& rhs ) ;

// Operatoren für die Potenz
natuerlicheZahl operator^( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ; // TODO
natuerlicheZahl operator^( unsigned long long lhs, natuerlicheZahl const& rhs ) ; // TODO
natuerlicheZahl operator^( natuerlicheZahl const& lhs, unsigned long long rhs ) ;


// Vergleichsoperatoren
bool operator<( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ;
bool operator<( unsigned long long lhs, natuerlicheZahl const& rhs ) ;
bool operator<( natuerlicheZahl const& lhs, unsigned long long rhs ) ;

bool operator>( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ; 
bool operator>( unsigned long long lhs, natuerlicheZahl const& rhs ) ; 
bool operator>( natuerlicheZahl const& lhs, unsigned long long rhs ) ; 

bool operator==( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ; 
bool operator==( unsigned long long lhs, natuerlicheZahl const& rhs ) ; 
bool operator==( natuerlicheZahl const& lhs, unsigned long long rhs ) ; 

bool operator!=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ;
bool operator!=( unsigned long long lhs, natuerlicheZahl const& rhs ) ; 
bool operator!=( natuerlicheZahl const& lhs, unsigned long long rhs ) ; 

bool operator>=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ; 
bool operator>=( unsigned long long lhs, natuerlicheZahl const& rhs ) ; 
bool operator>=( natuerlicheZahl const& lhs, unsigned long long rhs ) ; 

bool operator<=( natuerlicheZahl const& lhs, natuerlicheZahl const& rhs ) ; 
bool operator<=( unsigned long long lhs, natuerlicheZahl const& rhs ) ;
bool operator<=( natuerlicheZahl const& lhs, unsigned long long rhs ) ; 