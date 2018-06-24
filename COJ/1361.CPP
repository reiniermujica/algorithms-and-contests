#include <iostream>
#include <vector>
#include <cmath>

#define MAXN 1005

using namespace std;

int N, M;
int i, j, k;
int dp[MAXN];
vector < int > V;

int sqr3( int x )
{
    int r = 1;
    while ( r * r * r <= x ) r++;
    return r - 1;
}

int main()
{
    /* calculate all cool numbers */    
    for ( i = 1; i < MAXN; i++ )
    {
        dp[i] = dp[i - 1];
        V.push_back( i * i * i );
        int sq = (int)sqrt( V[i - 1] );
        if ( sq * sq == V[i - 1] )
            dp[i]++;    
    }
    
    while ( cin >> N >> M )
    {
        int x = sqr3( N );
        int y = sqr3( M );
        if ( x * x * x == N ) x--;
        
        cout << dp[y] - dp[x] << endl;    
    }

    return 0;
}
