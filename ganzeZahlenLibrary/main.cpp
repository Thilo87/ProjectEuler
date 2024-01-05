#include <iostream>
#include "ganzeZahl.h"
using namespace std ;


int main ()
{
	ganzeZahl a( 999 ) ;
	ganzeZahl b( 999 ) ;
	
	cout << (a+b).getText() ;
	return 0 ;
}