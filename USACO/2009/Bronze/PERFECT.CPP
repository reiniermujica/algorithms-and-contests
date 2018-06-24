/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 101;
    
int N, sol;
int i, j;
int T[MAXN][MAXN];
int S[MAXN];

int main() {

    freopen( "perfect.in", "r", stdin );
    freopen( "perfect.out", "w", stdout );
    
    scanf( "%d\n", &N );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= N; j++ )
            scanf( "%d", &T[i][j] );
        sort( T[i] + 1, T[i] + N + 1 );
        S[i] = T[i][N / 2 + 1];
    }
    
    sort( S + 1, S + N + 1 );
    sol = S[N / 2 + 1];
    
    printf( "%d\n", sol );
    return 0;
}
