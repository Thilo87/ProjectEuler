#include <iostream>
#include <set>
using namespace std ;

template< typename T >
class Menge
{
public:
	Menge()
	{

	}
	Menge( set< T > A )
	{
		elemente = A ;
	}

	Menge< T > vereinigen( Menge< T > B )
	{
		set< T > vereinigung ;
		for ( set< T >::iterator i = elemente.begin() ;  i != elemente.end() ;  ++i )
			vereinigung.insert( (*i) ) ;
		for ( set< T >::iterator i = B.elemente.begin() ;  i != B.elemente.end() ;  ++i )
			vereinigung.insert( (*i) ) ;
		return Menge( vereinigung ) ;
	}
	Menge< T > schneiden( Menge< T > B )
	{
		set< T > schnitt ;
		for ( set< T >::iterator i = elemente.begin() ;  i != elemente.end() ;  ++i )
			if ( B.elemente.count( (*i) ) > 0 )
				schnitt.insert( (*i) ) ;
		return Menge( schnitt ) ;
	}

	bool operator==( Menge< T > const& B )
	{
		if ( elemente.size() == B.elemente.size() )
		{
			for ( set< T >::iterator i = elemente.begin() ;  i != elemente.end() ;  ++i )
				if ( B.count( (*i) ) == 0 )
					return false ;
			return true ;
		}

		return false ;
	}
	bool operator!=( Menge< T > const& B )
	{
		if ( elemente.size() == B.elemente.size() )
		{
			for ( set< T >::iterator i = elemente.begin() ;  i != elemente.end() ;  ++i )
				if ( B.count( (*i) ) == 0 )
					return true ;

			return false ;
		}

		return true ;
	}

	void ausgeben()
	{
		cout << "{ " ;
		for ( set< T >::iterator i = elemente.begin() ;  i != elemente.end() ;  ++i )
			cout << (*i) << " " ;
		cout << "}" ;
	}

	set< T > elemente ;
} ;