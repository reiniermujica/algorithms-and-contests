#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 15
#define MAXM 10010
#define oo 1 << 30

int N, M;
int i, j, k;
int dp[MAXM][MAXN];
int val[MAXN];

int change(int x, int y)
{
	return abs(x - y) * abs(x - y);
}

int main()
{
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N; i++ )
		scanf( "%d", &val[i] );

	for ( i = 0; i <= M; i++ )
	{
		fill( dp[i], dp[i] + MAXN, oo );
	}

	dp[0][0] = 0;

	for ( i = 1; i <= N; i++ )
	{
		for ( j = 1; j <= M; j++ )
		{
			for ( k = 1; k * k <= j; k++ )
			{
				int sq = k * k;
				if ( j - sq >= 0 && dp[j - sq][i - 1] != oo )
					dp[j][i] = min( dp[j][i], dp[j - sq][i - 1] + change(val[i], k ) );
			}
		}
	}

	if ( dp[M][N] == oo )
		printf( "-1\n" );
	else
		printf( "%d\n", dp[M][N] );

	return 0;
}
