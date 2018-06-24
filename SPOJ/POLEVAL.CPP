#include <cstdio>

using namespace std;

#define MAXN 1020
#define LL long long

LL N, T = 0;
LL i, j, k;
LL C[MAXN];
LL p[MAXN];

LL evalue( int ki )
{
	p[1] = ki;
	for ( int i = 2; i <= N; i++ )
	{
		p[i] = p[i - 1] * ki;
	}

	LL sol = 0;
	for ( int i = N; i > 0; i-- )
	{
		sol = sol + (C[i] * p[i]);
	}
	return sol + C[0];
}

int main()
{
	scanf( "%lld", &N );
	while ( N != -1 )
	{
		T++;
		for ( i = N; i >= 0; i-- )
		{
			scanf( "%lld", &C[i] );
		}
		printf( "Case %lld:\n", T );

		scanf( "%d", &k );
		for ( i = 1; i <= k; i++ )
		{
			LL ki;
			scanf( "%lld", &ki );
			printf( "%lld\n", evalue( ki ) );
		}
		scanf( "%lld", &N );
	}

	return 0;
}
