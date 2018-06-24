/*
 Reinier César Mujica
 22/4/08 PSN - 2008
 Using Segment Tree algorithm O(N * log(N))
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    MAXN = 25002,
    MAXL = MAXN * 3,
    oo = 1 << 29; // 2^29

int N, M, R[MAXL], T[MAXN], i, j, k, a, b;
    
int build( int node, int lo, int hi ) {
    if ( lo == hi ) {
     R[node] = T[lo];
     return R[node];
    }
    int mid = ( lo + hi ) / 2;
    R[node] = min( build( node * 2, lo, mid ),
                   build( node * 2 + 1, mid + 1, hi ) );
    return R[node];
}

int query( int node, int lo, int hi, int a, int b ) {
    if ( hi < a || lo > b )
     return oo;
    if ( lo >= a && hi <= b )
     return R[node];
    int mid = ( lo + hi ) / 2;
    return query( node * 2, lo, mid, a, b ) <?
           query( node * 2 + 1, mid + 1, hi, a, b );
}

int main(){

    freopen( "cavecow2.in", "r", stdin );
    freopen( "cavecow2.out", "w", stdout );

    scanf( "%d %d", &N, &M);

    for ( i = 1; i <= N; i++ )
     scanf( "%d", &T[i] );

    /* Build Segment Tree O(N * log(N)) */

    build( 1, 1, N );
    
    for ( i = 0; i < M; i++ ) {
     scanf( "%d %d", &a, &b );
     printf( "%d\n", query( 1, 1, N, a, b ) );
    }
    
    fflush( stdout );
    return 0;   
}
