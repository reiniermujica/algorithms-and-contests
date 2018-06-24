/*
 Reinier César Mujica
 17 - 11 - 2008
 String Matching ( Kmp )
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int
	MAXN = 1005;
	
int N, M;
int i, k;
int preKMP[MAXN];
char P[MAXN], T[MAXN];

int main() {

	while ( 1 ) {

        /* fill */
        memset( P, 0, sizeof P );
        memset( T, 0, sizeof T );
        memset( preKMP, 0, sizeof preKMP );
        
        /* read */
        scanf( "%s %s", P + 1, T + 1 );
        N = strlen( P + 1 );
        M = strlen( T + 1 );

		/* pre KMP */
		k = 0;
		for ( i = 2; i <= N; i++ ) {
			preKMP[i] = 0;
			while ( k > 0 && P[i] != P[k + 1] )
				k = preKMP[k];
			if ( P[i] == P[k + 1] ) k++;
			preKMP[i] = k;
		}
		
        /* KMP */
		k = 0;
        for ( i = 1; i <= M; i++ ) {
            while ( k > 0 && T[i] != P[k + 1] )
				k = preKMP[k];
			if ( T[i] == P[k + 1] ) k++;
			if ( k == N ) {
				printf( "MATCH AT POSITION %d\n", i - N + 1 );
				k = preKMP[k];
			}
        }
	}

	fflush( stdout );
	return 0;
}
