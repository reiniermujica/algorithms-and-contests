#include <cstdio>
using namespace std;

#define MAXN 1005

int N, A, B, sol;
int dp[MAXN];
int i, j, k;

int main()
{
	for ( int i = 1; i < MAXN-1; i++ )
	{
		dp[i] = dp[i - 1] + ( ( i * ( i + 1) * ( i + 2 ) ) % 100 );
	}

	scanf( "%d", &N );
	while ( N-- )
	{
		scanf( "%d %d", &A, &B );
		printf( "%d\n", ( dp[B] - dp[A - 1]) % 100 );
	}
	return 0;
}
