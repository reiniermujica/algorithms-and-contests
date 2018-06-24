/*
 Reinier César Mujica
 18 - 3 - 2009
 Knaspack
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 510,
    MAXT = 5010;
    
int T, N, b_time;
int i, j, k;
int S[MAXN], sav[MAXN];
int last[MAXT], sol[MAXN];
bool dp[MAXT];

int main() {
    
    scanf( "%d %d", &T, &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &S[i] );
        
    /* Knaspack */
    dp[0] = true;
    for ( i = 1; i <= N; i++ )
        for ( j = T; j >= S[i]; j-- )
            if ( !dp[j] && dp[j - S[i]] ) {
                dp[j] = true;   
                last[j] = i;
            }
        
    for ( i = T; !dp[i]; i-- );
    
    while ( last[i] ) {
        sav[++k] = last[i];
        i -= S[last[i]];
    }
    
    /* first musicians */
    b_time = 1;
    for ( i = k; i; i-- ) {
        sol[sav[i]] = b_time;
        b_time += S[sav[i]];
    }
    
    /* second musicians */
    b_time = 1;
    for ( i = 1; i <= N; i++ )
        if ( !sol[i] ) {
            sol[i] = b_time;
            b_time += S[i];
        }
    
    for ( i = 1; i <= N; i++ )
        printf( "%d ", sol[i] - 1 );
    
    printf( "\n" );
    
    fflush( stdout );
    return 0;
}
