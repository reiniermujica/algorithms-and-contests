/*
    Reinier César Mujica Hdez
    3 - 10 - 2011    
*/

#include <cstdio>

#define MAXN 501

using namespace std;

int N;
int i;
int dp[MAXN];

int main()
{
    for ( i = 1; i < MAXN; i++ )
    {
        dp[i] = dp[i - 1] + (i * i);        
    }

    scanf( "%d", &N );
    while ( N != 0 )
    {
        printf( "%d\n", dp[N] );
        scanf( "%d", &N );    
    }
    
    return 0;
}
