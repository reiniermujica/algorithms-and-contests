#include <cstdio>
#include <cmath>

#define MAXN 1000003
#define int64 long long

using namespace std;

int64 T;
int64 x, y;
int64 i, j;
int64 dp[MAXN + 1000];
bool prime[MAXN + 1000];

int main()
{
    for ( i = 2; i <= MAXN; i++ )
    {
        dp[i] = dp[i-1];
        if ( !prime[i] )
        {
            dp[i]++;
            if ( i * i <= MAXN )
            {
                 for ( j = i; j * i <= MAXN; j++ )
                     prime[i * j] = true;
            }
        }        
    }

    scanf( "%lld", &T );
    while ( T-- )
    {
        scanf( "%lld %lld", &x, &y );
        
        int rx = (int)sqrt( x );
        int ry = (int)sqrt( y );
        
        if ( rx * rx == x && !prime[rx] ) rx--;
        
        printf( "%lld\n", dp[ry] - dp[rx] );
    }
    
    return 0;
}
