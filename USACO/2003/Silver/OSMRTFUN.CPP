/*
 Reinier César Mujica
 22 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 150,
	MAXM = 40000,
	SIZE = 40050,
	oo = 1 << 29;
	
int N, sol;
int i, j, k;
int S[MAXN], F[MAXN];
int dp1[SIZE * 2], dp2[SIZE * 2];
int *next = dp2 + SIZE, *last = dp1 + SIZE;

int main() {

	freopen( "osmrtfun.in", "r", stdin );
	freopen( "osmrtfun.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d %d", &S[i], &F[i] );
	
	fill( dp1, dp1 + ( 2 * SIZE ), -oo );
	fill( dp2, dp2 + ( 2 * SIZE ), -oo );
	dp1[SIZE] = 0; dp2[SIZE] = 0;
	
	for ( i = 1; i <= N; i++ ) {
        
        for ( j = -MAXM; j < MAXM; j++ )
            if ( last[j] != -oo )
                next[j + S[i]] >?= last[j] + F[i];

    	for ( j = 0; j < MAXM; j++ )
            if ( next[j] >= 0 ) sol >?= ( next[j] + j );

        for ( j = -MAXM; j < MAXM; j++ )
            last[j] = next[j];
    }
        
	printf( "%d\n", sol );
	return 0;
}
