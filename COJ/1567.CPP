#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10005

int N, M, sol;
int i, j, k;
char A[MAXN], B[MAXN];
int dp[2][MAXN];
bool ok = true;

int main()
{
    gets( A + 1 );
    gets( B + 1 );
    N = strlen( A + 1 );
    M = strlen( B + 1 );
    
    for ( i = 1; i <= N; i++ )
    {
        for ( j = 1; j <= M; j++ )
        {
            if ( A[i] == B[j] )            
                dp[ok][j] = dp[!ok][j - 1] + 1;                        
            else
                dp[ok][j] = dp[ok][j - 1];
            
            sol = max( dp[ok][j], sol );
        }
        ok = !ok;
    }
    
    printf( "%d\n", sol );
    
    return 0;
}
