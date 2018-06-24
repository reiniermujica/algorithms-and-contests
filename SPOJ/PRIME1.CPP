/*
 Reinier César Mujica
 06 - 11 - 2008
*/

#include <cstdio>
#include <cmath>

using namespace std;

const int
	MAXN = 100000;
	
int T, N, M, cant;
int i, j, k;
bool mark[MAXN];
int prime[MAXN];

int main() {

	/* find primes in range 2..MAXN */
	k = (int)sqrt( MAXN );
	for ( i = 2; i <= k; i++ ) {
		if ( !mark[i] ) {
			j = 2;
			while ( j * i < MAXN ) {
				mark[j * i] = true;
				j++;
			}
		}
	}
	
	for ( i = 2; i <= MAXN; i++ )
     if ( !mark[i] ) prime[++cant] = i;
	
	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &N, &M );
		
		if ( N == 1 ) N++;
		if ( N == 2 ) { printf( "2\n" ); N++; };
		if ( N % 2 == 0 ) N++;
		
		for ( i = N; i <= M; i += 2 ) {
			j = 1; k = (int)sqrt( i );
            bool isprime = true;
			while ( prime[j] <= k ) {
				if ( i % prime[j] == 0 ) {
					isprime = false;
					break;
				}
                j++;
                if ( j > cant ) break;
            }
			if ( isprime ) printf( "%d\n", i );
		}
		printf( "\n" );	
	}

	return 0;
}
