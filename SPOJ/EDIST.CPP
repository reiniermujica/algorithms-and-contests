#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 2005

int T, N, M;
int i, j;
int dp[MAXN][MAXN];
char cad1[MAXN], cad2[MAXN];

int min( int x, int y, int z )
{
	if ( x <= y && x <= z ) return x;
	if ( y <= x && y <= z ) return y;
	if ( z <= x && z <= y ) return z;
	return x;
}

int main()
{
	scanf( "%d", &T );
	while ( T-- )
	{
		scanf( "%s", cad1 + 1 );
		scanf( "%s", cad2 + 1 );

		N = strlen( cad1 + 1 );
		M = strlen( cad2 + 1 );

		memset( dp, 30, sizeof dp );
		for ( i = 0; i <= M; i++ )
        {
			dp[0][i] = i;
        }

		for ( i = 0; i <= N; i++ )
        {
			dp[i][0] = i;
        }

		for ( i = 1; i <= N; i++ )
		{
			for ( j = 1; j <= M; j++ )
			{
					if ( cad1[i] == cad2[j] )
						dp[i][j] = min( dp[i - 1][j - 1], dp[i][j - 1] + 1 );
					else
						dp[i][j] = min( dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] ) + 1;
			}
        }

		printf( "%d\n", dp[N][M] );
	}
	
	return 0;
}
