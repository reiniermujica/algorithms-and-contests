/*
 Reinier César Mujica
 27 - 4 - 2009
 Rucksack
*/

#include <cstdio>

const int
    MAXN = 10000001,
    MAXM = 101;
    
int N, sol, sum;
int i, j, k;
int K[MAXM], C[MAXM];
int cant[MAXN];
bool dp[MAXN];

inline int abs_val( int x ) {
    return x < 0 ? -x : x;    
}

int main() {
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d %d", &K[i], &C[i] );
        sum += K[i] * C[i];
    }
      
    dp[0] = true;
    for ( i = 1; i <= N; i++ ) {
        
        for ( j = 0; j <= C[i]; j++ )
            cant[j] = 0;
            
        for ( j = C[i]; j <= sum; j++ ) {
            cant[j] = 0;
            if ( dp[j - C[i]] && !dp[j] ) {
                if ( cant[j - C[i]] + 1 <= K[i] ) {
                    cant[j] = cant[j - C[i]] + 1;   
                    dp[j] = true;
                }    
            }
        }
    }
    
    i = sum / 2;
    while ( i - sol >= 0 ) {
        k = i - sol;
        if ( dp[k] ) break;
        k = i + sol;
        if ( dp[k] ) break;
        sol++;
    }
    sol = sum - k;
    
    printf( "%d\n", abs_val( sol - k ) );        
    return 0;
}
