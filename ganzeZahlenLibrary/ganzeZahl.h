#include <cmath>
#include <iostream>
using namespace std ;

class ganzeZahl
{
public:
	// Getter
	int const& getZiffernanzahl() { return ziffernAnzahl ; }
	int const& getZiffer( int stelle ) { return ziffern[ stelle ] ; }
	int getVorzeichen() { if ( istNegativ ) return 1 ; else -1 ; }
	char const* getText() { return alsText ; }

	// mathematische Operationen
	void addiere( long long zahl ) ;
	void addiere( ganzeZahl& zahl ) ;
	void addiere( int ziffernAnzahl, int* ziffern ) ;
	void multipliziere( ganzeZahl& zahl ) ;

	// Operatoren
	// unärer Minus-Operator
	const ganzeZahl operator-() ;
	const ganzeZahl operator+( ganzeZahl& lhs ) ;
	
	// Setter
	void setZiffer( int stelle, int wert ) { ziffern[ stelle ] = wert ; }

	// Konstruktoren
	ganzeZahl() ;
	ganzeZahl( int ziffernAnzahl, bool istNegativ, int* ziffern ) ;
	ganzeZahl( long long zahl ) ;
	ganzeZahl( ganzeZahl const& rhs ) ; // Kopie-Konstruktor

	// Destruktor
	~ganzeZahl() ;

private:
	void aktualisiereText() ;
	char* alsText ;
	bool istNegativ ;
	int ziffernAnzahl ;
	int* ziffern ;
} ;

// addiert zahl1 + zahl2 zu einer neuen Zahl
ganzeZahl* addiere ( ganzeZahl& zahl1, ganzeZahl& zahl2 ) ;