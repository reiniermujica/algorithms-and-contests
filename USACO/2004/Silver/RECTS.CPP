/*
 Reinier César Mujica
 14 - 11 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
      MAXN = 200;
      
typedef pair < int, int > par;

int N, sol;
int i, j, k;
par T[MAXN];
int dp[MAXN];

int main() {

    freopen( "rects.in", "r", stdin );
    freopen( "rects.out", "w", stdout);
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
     scanf( "%d %d", &j, &k );
     if ( j > k ) swap( j, k );
     T[i] = par( j, k );
    }

    /* catching */
    sort( T + 1, T + N + 1 );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j < i; j++ ) {
            if ( T[i].first > T[j].first && T[i].second >= T[j].second )
             dp[i] >?= dp[j];
            if ( T[i].first >= T[j].first && T[i].second > T[j].second )
             dp[i] >?= dp[j];
        }
        dp[i]++;
        sol >?= dp[i];
    }
    
    printf( "%d\n", sol );
    return 0;
}
