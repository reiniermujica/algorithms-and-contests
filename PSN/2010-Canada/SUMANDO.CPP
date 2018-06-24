#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10005
#define LL long long

int N, A, B;
LL M;
int i, j;
LL dp[MAXN];

int main()
{
    freopen( "sumando.in", "r", stdin );
    freopen( "sumando.out", "w", stdout );
        
    scanf( "%d %d %d %I64d", &N, &A, &B, &M );
    
    dp[0] = 1;
    for ( i = A; i <= B; i++ )
    {
        for ( j = i; j <= N; j++ )
        {
            dp[j] += dp[j - i];    
            dp[j] %= M;
        }
    }
    
    printf( "%I64d\n", dp[N] % M );
    
    return 0;
}
