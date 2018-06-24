#include <cstdio>

using namespace std;

int N;
int T;
int sol;

void dfs(int num )
{
	if ( num <= N ) sol++;
	if ( num > N) return;
	dfs( num * 10 );
	dfs( num * 10 + 1);
}

int main()
{
	scanf( "%d", &T );

	while ( T-- )
	{
		scanf( "%d", &N );

		sol = 0;
		dfs( 1 );

		printf( "%d\n", sol );
	}

	return 0;
}
