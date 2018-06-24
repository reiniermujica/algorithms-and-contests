#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAXN 205

int N, sol, C;
int i, j, k;
int dp[MAXN][2];
bool uni[MAXN][2];
char lin1[MAXN], lin2[MAXN];
vector < int > G[MAXN];

using namespace std;

void dfs( int node )
{
	int im = 1, nm = 0;
	bool one = true, two = true;

	for ( int i = 0; i < G[node].size(); i++ )
	{
		int next  = G[node][i];
		dfs( next );
		im += dp[next][1];
		one = (one && uni[next][1]);

		if ( dp[next][0] >= dp[next][1] )
		{
			nm += dp[next][0];
			two = (two && uni[next][0]);
		}
		else
		{
			nm += dp[next][1];
			two = (two && uni[next][1]);
		}
	}

	dp[node][0] = im;
	dp[node][1] = nm;

	if ( im == nm )
		one = false;

	uni[node][0] = one;
	uni[node][1] = two;

}

int main()
{
	scanf( "%d", &N );
	while ( N != 0 )
	{
		map <string,int> M;
		C = 0;

		for ( i = 0; i <= N; i++ )
		{
			G[i].clear();
			dp[i][0] = dp[i][1] = 0;
		}


		scanf( "%s", lin1 );
		M[lin1] = ++C;

		for ( i = 1; i < N; i++ )
		{
			scanf( "%s %s", lin1, lin2 );
			if ( !M[lin1] ) M[lin1] = ++C;
			if ( !M[lin2] ) M[lin2] = ++C;
			int x = M[lin1];
			int y = M[lin2];
			G[y].push_back( x );
		}

		dfs( 1 );

		bool ok = false;

		if ( dp[1][0] > dp[1][1] )
		{
			printf( "%d ", dp[1][0]);
			ok = uni[1][0];
		}
		if ( dp[1][0] < dp[1][1] )
		{
			printf( "%d ", dp[1][1]);
			ok = uni[1][1];
		}
		if ( dp[1][0] == dp[1][1] )
		{
			printf( "%d ", dp[1][0]);
			ok = false;
		}

		if ( ok )
			printf( "Yes\n" );
		else
			printf( "No\n" );

		scanf( "%d", &N );
	}

	return 0;
}
