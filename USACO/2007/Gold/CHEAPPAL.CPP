/*
 Reinier César Mujica
 24 - 3 - 2009
 Is cold see the dp states
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 2005,
    MAXC = 260;
    
int N, M;
int i, j, k;
int dp[MAXN][MAXN];
int ins_del[MAXC];
char cad[MAXN], c;

int main() {
    
    freopen( "cheappal.in", "r", stdin );
    freopen( "cheappal.out", "w", stdout );
    
    scanf( "%d %d\n", &M, &N );
    gets( cad + 1 );
    for ( i = 0; i < M; i++ ) {
        scanf( "%c %d %d\n", &c, &j, &k );
        ins_del[c] = j <? k;
    }
    
    for ( k = 1; k < N; k++ ) {
        for ( i = 1; i + k <= N; i++ ) {
            j = i + k;
            
            if ( cad[i] == cad[j] )
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = ( dp[i + 1][j] + ins_del[cad[i]] ) <?
                           ( dp[i][j - 1] + ins_del[cad[j]] );
        }
    }
    
    printf( "%d\n", dp[1][N] );
    return 0;
}
