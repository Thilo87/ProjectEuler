#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std ;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main()
{
	int ziffernVorher = 0 ;
	int ziffernNachher = 0 ;

	ifstream fin( "roman.txt" ) ;

	string s ;
	while ( fin >> s )
	{
		ziffernVorher += s.size() ;
		replaceAll( s, "DCCCC", "kk" ) ;
		replaceAll( s, "LXXXX", "kk" ) ;
		replaceAll( s, "VIIII", "kk" ) ;
		replaceAll( s, "CCCC", "kk" ) ;
		replaceAll( s, "XXXX", "kk" ) ;
		replaceAll( s, "IIII", "kk" ) ;
		ziffernNachher += s.size() ;
	}

	fin.close() ;

	cout << ziffernVorher - ziffernNachher << endl ;
	return 0 ;
}