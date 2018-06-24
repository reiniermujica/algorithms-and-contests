/*
 Reinier César Mujica
 14/4/08 PSN - 2008
 Using RMQ algorithm
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    MAXN = 50001;
    
int N, Q, maxi[MAXN][16], mini[MAXN][16], i, j, k;

int main() {
    int x, y;
    freopen( "lineup.in", "r", stdin );
    freopen( "lineup.out", "w", stdout );
    scanf( "%d %d", &N, &Q );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &x );
        maxi[i][0] = x;
        mini[i][0] = x;
    }

    /* compute values using RMQ O (N*lg(N)) */
    k = (int)log2( N );
    for ( i = 1; i <= k; i++ ) {
     int pow = 1 << i;
     for ( j = 1; j <= N - pow + 1; j++ ) {
        maxi[j][i] = max( maxi[j][i-1], 
                          maxi[j + pow / 2][i-1] );
        mini[j][i] = min( mini[j][i-1],
                          mini[j + pow / 2][i-1] );
     }        
    }
    
    for ( i = 0; i < Q; i++ ) {
     scanf( "%d %d", &x, &y );
     k = (int)log2( y-x );
     printf( "%d\n", max( maxi[x][k], maxi[y - (1<<k) + 1][k] ) -
                     min( mini[x][k], mini[y - (1<<k) + 1][k] ) );
    }

    fflush( stdout );
    return 0;
}
