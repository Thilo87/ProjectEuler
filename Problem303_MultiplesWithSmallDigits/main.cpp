#include <iostream>
using namespace std ;

bool nur2en( size_t n )
{
	while ( n != 0 )
	{
		if ( n % 10 > 2 )
			return false ;
		n /= 10 ;
	}

	return true ;
}

unsigned long long f( size_t n )
{
		long long k = n ;
		long long l = 1 ;
		while ( !nur2en( k ) )
		{
			k += n ;
			++l ;
		}

		return k ;
}

int main ()
{
	for ( size_t i = 1 ;  i <= 50 ;  ++i )
		if ( f(i*i) != f(i)*f(i) )
			cout << i << endl ;
	// f(10*n
	while ( true )
	{
		size_t n ;
		cin >> n ;
		cout << "f(" << n << ") = " << f(n) << endl ;
	}
	//long long summe = 0 ;
	//for ( size_t n = 1 ;  n <= 10000 ;  ++n )
	//{
	//	long long k = n ;
	//	long long l = 1 ;
	//	while ( !nur2en( k ) )
	//	{
	//		k += n ;
	//		++l ;
	//	}

	//	cout << l << endl ;
	//	summe += l ;
	//	//cout << "f(" << n << ") = " << k << endl ;
	//}

	//cout << summe << endl ;
	return 0 ;
}