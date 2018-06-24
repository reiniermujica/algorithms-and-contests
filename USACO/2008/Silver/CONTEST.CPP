/*
 Reinier César Mujica
 23 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 150;
    
int N, M, sol;
int i, j, k;
bool can[MAXN][MAXN], ok;

int main() {
    
    freopen( "contest.in", "r", stdin );
    freopen( "contest.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= M; i++ ) {
        scanf( "%d %d", &j, &k );
        can[j][k] = true;
    }
    
    for ( k = 1; k <= N; k++ )
        for ( i = 1; i <= N; i++ )
            for ( j = 1; j <= N; j++ )
                can[i][j] = can[i][j] || ( can[i][k] && can[k][j] );
    
    for ( i = 1; i <= N; i++ ) {
        ok = true;
        for ( j = 1; j <= N; j++ ) {
            if ( i == j ) continue;
            if ( !can[i][j] && !can[j][i] ) {
                ok = false;
                break;
            }
        }
        if ( ok ) sol++;
    }
    
    printf( "%d\n", sol );
    return 0;
}
