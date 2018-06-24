/*
 Reinier César Mujica
 21/05/08 PSN - 2008
*/

#include <iostream>

using namespace std;

const int
    MAXN = 1002,
    MAXL = 35;
    
int N, K, i, j;
int dp[MAXN][MAXL];
int res[MAXL];

void suma( int a, int b, int c ) {
     int carry = 0, i, j, k;
     int s1, s2, s3 = 0;

     if ( dp[a][0] < dp[b][0] ) {
       s1 = a; s2 = b;
     }
     else {
       s1 = b; s2 = a;
     }
     for ( i = 1; i <= dp[s1][0]; i++ ) {
       k = dp[s1][i] + dp[s2][i] + carry;
       carry = k / 10;
       dp[c][++s3] = k % 10;
     }
     for ( i = i ; i <= dp[s2][0]; i++ ) {
       k = dp[s2][i] + carry;
       carry = k / 10;
       dp[c][++s3] = k % 10;
     }
     if ( carry > 0 ) dp[c][++s3] = carry;
     dp[c][0] = s3;
}

int main() {

    freopen( "ddayz.in", "r", stdin );
    freopen( "ddayz.out", "w", stdout );
    
    cin >> N >> K;
    
    dp[0][0] = 1; dp[0][1] = 1;
    
    for ( i = 1; i <= K; i++ )
     for ( j = i; j <= N; j++ )
      suma( j - i, j, j );

    for ( i = dp[N][0]; i > 0 ; i-- )
     cout << dp[N][i];
    cout << endl;
    
    fflush( stdout );
    return 0;
}
