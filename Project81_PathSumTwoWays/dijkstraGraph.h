#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <queue>
using namespace std ;

class dijkstraKnoten ;
class dijkstraKante ;
class dijkstraGraph ;



/******************************* KNOTEN ********************************/

class dijkstraKnoten
{
public:
	dijkstraKnoten( double distanz, int nummer ) ;

	double distanz ; // Distanz zum Startknoten
	vector< dijkstraKante > kanten ; // Kanten, die von diesem Knoten ausgehen
	dijkstraKnoten* vorgaenger ; // Vorgänger-Knoten
	bool besucht ; // ist dieser Knoten schon besucht worden ?

	void info() ;

	// Get-Funktionen
	int getNummer() { return nummer ; }

private:
	int nummer ;
} ;





/******************************* KANTE ********************************/

class dijkstraKante
{
public:
	dijkstraKante( double kosten, int nummer ) ;

	dijkstraKnoten* zielknoten ; // Knoten, zu dem diese Kante führt

	// Get-Funktionen
	double getKosten() { return kosten ; }
	int getNummer() { return nummer ; }

private:
	double kosten ;
	int nummer ;

} ;





/******************************* GRAPH ********************************/

class dijkstraGraph
{
public:
	// initialisiert einen neuen Graphen mit nKnoten Knoten und dem Startknoten startKnotenNr
	dijkstraGraph( int nKnoten, int startKnotenNr ) ;

	// fuegt eine Kante von knotenA zu knotenB hinzu, die die Pfadkosten kosten hat
	void neueKante( int knotenA, int knotenB, double kosten ) ;

	// führt den Algorithmus von Dijkstra durch
	void startDijkstra() ;

	// Get-Funktionen
	int getStartknoten() { return startKnotenNr ; }
	int getKnotenanzahl() { return knoten.size() ; }
	int getKantenanzahl() { return kanten.size() ; }
	dijkstraKnoten* getKnoten( int nummer ) { return &knoten.at( nummer ) ; }

	void info() ;

private:
	vector< dijkstraKnoten > knoten ; // Knoten, die der Graph enthält. Aufruf: knoten.at( KNOTENNUMMER )
	vector< dijkstraKante > kanten ; // Kanten, die der Graph enthält. Alle Objekte der Klasse dijkstraKnoten
									  // enthalten nur Verweise auf die Elemente dieses Vectors

	int startKnotenNr ; // die Nummer des Knotens, an dem die Pfadsuche gestartet wird

} ;



