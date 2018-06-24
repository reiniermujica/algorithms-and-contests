/*
 Reinier César Mujica
 22/4/08 PSN - 2008
 Using RMQ algorithm O(N * log(N))
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    MAXN = 25002,
    MAXL = 15;

int N, M, RMQ[MAXN][MAXL], i, j, k, a, b;
    
int main(){

    freopen( "cavecow2.in", "r", stdin );
    freopen( "cavecow2.out", "w", stdout );

    scanf( "%d %d", &N, &M);

    for ( i = 1; i <= N; i++ ) {
     scanf( "%d", &a );
     RMQ[i][0] = a;
    }

    /* Min - Max Range Quering  O(N * log(N))*/
    
    k = (int)log2( N );
    for ( i = 1; i <= k; i++ ) {
     int pow = 1 << i; // 2^i
     for ( j = 1; j <= N - pow + 1; j++ )
      RMQ[j][i] = min( RMQ[j][i-1], RMQ[j + pow / 2][i-1] );
    }
    
    for ( i = 0; i < M; i++ ) {
     scanf( "%d %d", &a, &b );
     k = (int)log2( b - a );
     printf( "%d\n", min( RMQ[a][k], RMQ[b - (1 << k) + 1][k] ) );
    }
    
    fflush( stdout );
    return 0;   
}
