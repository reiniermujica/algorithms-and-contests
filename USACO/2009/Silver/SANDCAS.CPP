/*
 Reinier César Mujica
 20 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 25005;

int N, X, Y, sol;
int i;
int T[MAXN], S[MAXN];
    
int main() {

    freopen( "sandcas.in", "r", stdin );
    freopen( "sandcas.out", "w", stdout );
    
    scanf( "%d %d %d", &N, &X, &Y );
    for ( i = 1; i <= N; i++ )
        scanf( "%d %d", &T[i], &S[i] );
        
    sort( T + 1, T + N + 1 );
    sort( S + 1, S + N + 1 );
    
    for ( i = 1; i <= N; i++ ) {
        if ( T[i] < S[i] )
            sol += ( S[i] - T[i] ) * X;
        else 
            sol += ( T[i] - S[i] ) * Y;
    }

    printf( "%d\n", sol );
    return 0;
}
