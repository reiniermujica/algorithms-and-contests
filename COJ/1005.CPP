#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAXN 10005

struct offer
{
    int x, y, price;
    offer( int a = 0, int b = 0, int c = 0)
    {
        x = a; y = b; price = c;
    }    
};

int T, N;
int i;
int dp[MAXN];
int link[MAXN];
vector < offer > L;
vector < offer > :: iterator it;

bool cmp_Y(const offer &a, const offer &b)
{
    return a.y < b.y;    
}

int main()
{
    scanf( "%d", &T );
    while ( T-- )
    {
        L.clear();
        memset( dp, 0, sizeof dp );
        memset( link, 0, sizeof link );
        
        scanf( "%d", &N );
        for ( i = 0; i < N; i++ )
        {
            int x, y, p;
            scanf( "%d %d %d", &x, &y, &p );
            L.push_back( offer(x, x + y, p) );
        }
        
        sort( L.begin(), L.end(), cmp_Y );
        
        for ( i = 1; i < N; i++ )
        {
            it = upper_bound(L.begin(), L.end(), offer(0, L[i].x, 0), cmp_Y);
            if ( it != L.end() )
            {
                link[i] = it - L.begin() - 1;
                if ( link[i] < 0 ) link[i] = -1;
                else link[i]++;
            }
            else link[i] = -1;
        }
        
        for ( i = 1; i <= N; i++ )
        {
            dp[i] = max( dp[i - 1], dp[max(link[i-1],0)] + L[i-1].price );
        }
        
        printf( "%d\n", dp[N] );
    }
    
    return 0;
}
