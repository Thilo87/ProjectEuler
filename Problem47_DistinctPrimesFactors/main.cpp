/*

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors. 
What is the first of these numbers?

*/

#include <iostream>
#include "primzahlen.h"
#include <vector>
using namespace std ;

int main ()
{
	int const MAX_N = 10000000 ;
	int const K = 5 ;

	vector< int > primes = primzahlliste( MAX_N + 1 ) ; // creates a list of the primes less than MAX_N + 1
	
	for ( int n = 1 ;  n <= MAX_N ;  ++n )
	{
		bool fail = false ;

		int i = n ;
		for ( ;  i < n + K ;  ++i )
		{
			int n_cpy = i ;
			int k = 0 ;
			int n_primefactors = 0 ; // count of the distinct prime factors of n
			do
			{
				if ( n_cpy % primes.at( k ) == 0 ) // is the k-th prime number a prime factor of n ?
				{
					++n_primefactors ;

					if ( ( i + 1 ) % primes.at( k ) == 0 ) // n + 1 has also this prime factor => fail
						break ;
					else
						while ( n_cpy % primes.at( k ) == 0 )
							n_cpy /= primes.at( k ) ; // divide the whole prime factor out of the number
				}

				++k ;
			}
			while ( n_cpy > 1 ) ;

			// has the number less than K prime factors or cancelled the loop above?
			if ( n_cpy != 1 || n_primefactors < K )
			{
				fail = true ;
				break ;
			}
		}
	
		if ( !fail )
		{
			cout << "Here is it: " << n << endl ;
			break ;
		}
	}


	return 0 ;
}