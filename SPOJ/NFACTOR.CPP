#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000010
#define LL long long

LL N, A, B, sol;
LL T;
LL i, j, k;
LL M = 0;
LL primes[MAXN];
LL cant[MAXN][11];
LL nfact[MAXN];
bool mark[MAXN];

void dfs( LL x, LL res, LL c )
{
     if ( c == 10 ) return ;

     LL same = res * primes[x];
     if ( same < MAXN )
     {
         nfact[same] = c;
    	 dfs( x, same, c );
     }

     for ( LL i = x + 1; i <= M; i++ )
     {
         LL next = res * primes[i];
         if ( next >= MAXN ) break;
         if ( next < MAXN )
         {
            nfact[next] = c + 1;
            dfs( i, next, c + 1 );
         }
     }
}

int main()
{

	/* find primes */
	fill( mark, mark + MAXN, true );
	for ( i = 2; i < MAXN; i++ )
	{
		if ( mark[i] )
		{
			primes[++M] = i;
			k = i;
			while ( k * i < MAXN )
			{
				mark[k * i] = false;
				k++;
			}
		}
	}

    fill( nfact, nfact + MAXN, -1 );
    nfact[1] = 0;
	for ( i = 1; i <= M; i++ )
	{
        nfact[primes[i]] = 1;
        dfs( i, primes[i], 1 );
	}

 	for ( i = 1; i < MAXN; i++ )
	{
		for ( j = 0; j <= 10; j++ )
		{
			cant[i][j] = cant[i - 1][j] + ( nfact[i] == j );
		}
	}

	scanf( "%lld", &T );
	while ( T-- )
	{
		scanf( "%lld %lld %lld", &A, &B, &N );
		printf( "%lld\n", cant[B][N] - cant[A - 1][N] );
	}

	return 0;
}
