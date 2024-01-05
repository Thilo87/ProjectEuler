#include "dijkstraGraph.h"

void dijkstraGraph::startDijkstra()
{
	dijkstraKnoten* aktuellerKnoten = NULL ;

	for ( int k = 0 ;  k < knoten.size() ;  ++k )
	{
		// suche unter den unbesuchten Knoten denjenigen mit der geringsten Distanz ( zum Startknoten )
		double geringsteDistanz = DBL_MAX ;
		for ( int i = 0 ;  i < knoten.size() ;  ++i )
			if ( knoten.at( i ).besucht == false )
				if ( knoten.at( i ).distanz <= geringsteDistanz )
				{
					aktuellerKnoten = &knoten.at( i ) ;
					geringsteDistanz = knoten.at( i ).distanz ;
				}

		// setze den aktuellen Knoten, also den mit der geringsten Distanz, auf besucht
		aktuellerKnoten ->besucht = true ;

		// gehe alle Nachbarknoten des aktuellen Knotens durch und aktualisiere deren Distanz
		for ( int i = 0 ;  i < aktuellerKnoten ->kanten.size() ;  ++i )
			if ( aktuellerKnoten ->kanten.at( i ).zielknoten ->besucht == false )
			{
				// Distanz des aktuellen Knotens + Kantengewicht ( Kosten ) der Kante zum Nachbarknoten
				double neueDistanz = aktuellerKnoten ->distanz + aktuellerKnoten ->kanten.at( i ).getKosten() ;

				// wenn die neue Distanz kleiner als die Distanz beim Nachbarknoten ist, speichere sie in diesem
				// und setze den aktuellen Knoten als Vorgänger
				if ( neueDistanz < aktuellerKnoten ->kanten.at( i ).zielknoten ->distanz )
				{
					aktuellerKnoten ->kanten.at( i ).zielknoten ->distanz = neueDistanz ;
					aktuellerKnoten ->kanten.at( i ).zielknoten ->vorgaenger = aktuellerKnoten ;
				}
			}
	}
}


dijkstraKnoten::dijkstraKnoten( double distanz, int nummer )
{
	this ->distanz = distanz ;
	this ->nummer = nummer ;
	this ->vorgaenger = NULL ;
	this ->besucht = false ;
}

void dijkstraKnoten::info()
{
	cout << "Knotennummer: " << this ->nummer << endl ;
	cout << endl ;
	cout << "KANTEN: " << endl ;
	for ( int i = 0 ;  i < this ->kanten.size() ;  ++i )
		cout << this ->kanten.at( i ).getKosten() << endl ;
}

dijkstraKante::dijkstraKante( double kosten, int nummer )
{
	this ->kosten = kosten ;
	this ->nummer = nummer ;
	this ->zielknoten = NULL ;
}




dijkstraGraph::dijkstraGraph( int nKnoten, int startKnotenNr )
{
	if ( nKnoten <= startKnotenNr )
	{
		cerr << "Fehler: Anzahl der Knoten in dem Graphen muss echt kleiner als die Nummer des Startknotens sein, "
			 << "da die Nummerierung bei 0 beginnt." << endl ;
		return ;
	}
				

	this ->startKnotenNr = startKnotenNr ;

	// füge dem Vector mit den Knoten des Graphen knoten Knoten hinzu, wobei deren Distanz zum Startknoten
	// auf unendlich ( DBL_MAX ) gesetzt wird.
	for ( int i = 0 ;  i < nKnoten ;  ++i )
		this ->knoten.push_back( dijkstraKnoten( DBL_MAX, i ) ) ;

	// setze die Distanz des Startknotens auf 0
	this ->knoten.at( startKnotenNr ).distanz = 0 ;
}

void dijkstraGraph::neueKante( int knotenA, int knotenB, double kosten )
{
	if ( knotenA >= this ->knoten.size() || knotenB >= this ->knoten.size() )
	{
		cerr << "Fehler: Einen oder beide dieser Knoten gibt es nicht!" << endl ;
		return ;
	}

	// neue Kante erstellen mit dem Zielknoten knotenB
	this ->kanten.push_back( dijkstraKante( kosten, this ->kanten.size() ) ) ;
	this ->kanten.at( kanten.size() - 1 ).zielknoten = &knoten.at( knotenB ) ;
	this ->knoten.at( knotenB ).vorgaenger = &knoten.at( knotenA ) ;

	// zu dem Kanten-Vector des Knotens knotenA die soeben erstellte Kante hinzufügen
	this ->knoten.at( knotenA ).kanten.push_back( this ->kanten.at( this ->kanten.size() - 1 ) ) ;
}

void dijkstraGraph::info()
{
	cout << "Knotenanzahl: " << knoten.size() << endl ;
	cout << "Kantenanzahl: " << kanten.size() << endl ;
	cout << "Startknoten-Nr.: " << startKnotenNr << endl ;
	cout << endl ;

	cout << "KNOTEN: " << endl ;
	cout << left ;
	cout << setw( 8 ) << "Nr." << setw( 20 ) << "Distanz" << setw( 20 ) << "Ausgehende Kanten (Nummern)" << endl ;
	for ( int i = 0 ;  i < knoten.size() ;  ++i )
	{
		cout << setw( 8 ) << i << setw( 20 ) << knoten.at( i ).distanz ;
		for ( int j = 0 ;  j < knoten.at( i ).kanten.size() ;  ++j )
			cout << knoten.at( i ).kanten.at( j ).getNummer() << " " ;

		cout << endl ;
	}


	cout << endl ;
	cout << "KANTEN: " << endl ;
	cout << setw( 8 ) << "Nr." << setw( 20 ) << "Kosten" << setw( 20 ) << "Zielknoten-Nr." << endl ;
	for ( int i = 0 ;  i < kanten.size() ;  ++i )
		cout << setw( 8 ) << i << setw( 20 ) << kanten.at( i ).getKosten() << setw( 20 ) << kanten.at( i ).zielknoten ->getNummer() << endl ;

	cout << endl ;
	cout << "KNOTEN-VERBINDUNGEN-UEBERSICHT ( KNOTEN_A  -->  KOSTEN  -->  KNOTEN_B ): " << endl ;
	for ( int i = 0 ;  i < knoten.size() ;  ++i )
		for ( int j = 0 ;  j < knoten.at( i ).kanten.size() ; ++j )
			cout << setw( 4 ) << i << "  --> K: " << setw( 6 ) << knoten.at( i ).kanten.at( j ).getKosten() << " -->  " << setw( 4 ) << knoten.at( i ).kanten.at( j ).zielknoten ->getNummer() << endl ;
}