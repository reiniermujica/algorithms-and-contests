/*
 Reinier César Mujica
 24 - 10 - 2008
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
	MAXN = 1000050;

int N, T, C, sol;
int i, j, k, m;
int P[MAXN];
char st[MAXN];

int main() {

	scanf( "%d\n", &T );
	while ( C++ < T ) {
		
		scanf( "%d\n", &N );
		gets( st + 1 );

    	fill( P, P + MAXN, 0 );
        printf( "Test case #%d\n", C );
	
		/* pre KMP */
		k = 0;
		for ( i = 2; i <= N; i++ ) {
			while ( k > 0 && st[i] != st[k + 1] ) 
				k = P[k];
			if ( st[i] == st[k + 1] ) k++;
			P[i] = k;
			
			if ( P[i] ) {
                j = i - P[i];
                if ( i % j == 0 )
			      printf( "%d %d\n", i, i / j );
			}
		}
        printf( "\n" );
	}

    fflush( stdout );
	return 0;
}
