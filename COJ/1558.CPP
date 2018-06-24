/*
    Reinier César Mujica Hdez
    2 - 10 - 2011
*/

#include <cstdio>

#define MOD 1000000007
#define MAX 1000001

using namespace std;

int T, N;
int dp[MAX];
int i;

int main()
{    
    dp[0] = 1; dp[1] = 2;
    for ( i = 2; i < MAX; i++ )
    {
        dp[i] = ( dp[i - 1] + dp[i - 2] ) % MOD;       
    }
    
    scanf( "%d", &T );
    while ( T-- )
    {
        scanf( "%d", &N );
        printf( "%d\n", dp[N] );       
    }

    return 0;
}
