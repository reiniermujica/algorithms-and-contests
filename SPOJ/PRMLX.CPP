/*
 Reinier César Mujica
 8 - 11 - 2008
 Is beautiful or not ? Of course..
*/

#include <cstdio>
#include <algorithm>

#define debug 0

using namespace std;

const int
	MAXN = 40,
	MAXC = 300;
	
int N, M, sol;
int i, j, k;
int cant[MAXC], fact[MAXN];
char cad[MAXN];

void split_factor( int number, int action ) {
	 int k = 2;
	 while ( number > 1 ) {
		while ( number % k != 0 ) k++;
		fact[k] += action;
		number /= k;
	 }
}

int factorize( int lenght ) {
	int i, j, k, s;
	
	fill( fact, fact + MAXN, 0 );
	for ( i = 2; i <= lenght; i++ )
		split_factor( i, 1 );
     
	for ( i = 'a'; i <= 'z'; i++ )
		if ( cant[i] > 1 ) {
			for ( j = 2; j <= cant[i]; j++ )
			 split_factor( j, -1 );
		}
	
	s = 1;
	for ( i = 2; i <= 30; i++ )
		if ( fact[i] > 0 ) {
			k = i;
			for ( j = 2; j <= fact[i]; j++ )
			 k *= i;
			s *= k;
		}

	return s;
}

int main() {
	
	while ( gets( cad ) && cad[0] != '#' ) {
		
		/* fill */
		fill( cant, cant + MAXC, 0 );
		sol = 0;
		
		/* init */
		N = strlen( cad );
		for ( i = 0; i < N; i++ )
			cant[cad[i]]++;
			
		/* process */
		for ( i = 0; i < N - 1; i++ ) {
            for ( j = 'a'; j < cad[i]; j++ )
				if ( cant[j] ) {
					cant[j]--;
					sol += factorize( N - i - 1 );
					cant[j]++;
				}
			cant[cad[i]]--;
		}

		printf( "%10d\n", sol + 1 );
	}
	
	fflush( stdout );
	return 0;
}
