/*
 Reinier César Mujica
 21 - 5 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100005;
    
int N, L, K;
int i, sol;
int R[MAXN];

int main() {

    freopen( "fad.in", "r", stdin );
    freopen( "fad.out", "w", stdout );
    
    scanf( "%d %d %d", &N, &L, &K );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &R[i] );
    
    sort( R + 1, R + N + 1 );
    for ( i = 1; i <= N; i++ )
        if ( R[i] <= L ) {
            L += K;
            sol++;
        }
    
    printf( "%d\n", sol );
    return 0;
}
