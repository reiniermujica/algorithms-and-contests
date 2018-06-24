#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, sol;
int i, j, x;
int dp[15][15];
char cad[15];

int main()
{
	scanf( "%d\n", &T );
	while (T--)
	{
		memset(dp, 0, sizeof dp);
		
		scanf( "%d\n", &N );
		for ( i = 1; i <= N; i++ )
		{
			gets( cad + 1 );
			for ( j = 1; j <= N; j++ )
			{
				if ( cad[j] == '#' )
					dp[i][j] = 1;
				else 
					dp[i][j] = 0;
				dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		
		sol = 0;
		for ( i = 1; i <= N; i++ )
			for ( j = 1; j <= N; j++ )
			{
				for ( x = 0; x + i <= N && x + j <= N; x++ )
				{
					int val = dp[i+x][j+x] - dp[i-1][j+x] - dp[i+x][j-1] + dp[i-1][j-1];
					if ( val == 0 )
                        sol >?= (x + 1);	
				}
			}
			
        printf( "%d\n", sol );
    }

	return 0;
}
