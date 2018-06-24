#include <cstdio>
#include <queue>

using namespace std;

#define MAXN 202
#define MAXM 502
#define oo 1 << 25

int N, M, K;
int i, j, k;
bool ok = true;
int Q[2][MAXN][MAXM];
int cant[2][MAXN];
priority_queue < int, vector < int >, greater < int > > S;
int T[MAXN][MAXN];

int main()
{
	scanf( "%d %d %d", &N, &M, &K );
	for ( i = 1; i <= N; i++ )
	{
		for ( j = 1; j <= M; j++ )
		{
			scanf( "%d", &T[i][j] );
		}
	}

	for ( i = 1; i <= M; i++ )
	{
		Q[ok][i][1] = T[1][i];
		cant[ok][i] = 1;
	}

	ok = !ok;
	for ( i = 2; i <= N; i++ )
	{
		for ( j = 1; j <= M; j++ )
		{
			int size = 0;
			int one = 1, two = 1, tre = 1;


			while ( size < K )
			{
				int p = oo, sel = 0;
				
				if ( one <= cant[!ok][j - 1] && Q[!ok][j - 1][one] < p )
				{
					 p = Q[!ok][j - 1][one];
					 sel = 1;
				}
				if ( two <= cant[!ok][j] && Q[!ok][j][two] < p )
				{
					 p = Q[!ok][j][two];
					 sel = 2;
				}
				if ( tre <= cant[!ok][j + 1] && Q[!ok][j + 1][tre] < p )
				{
					 p = Q[!ok][j + 1][tre];
					 sel = 3;
				}

				if ( sel == 0 ) break;

				Q[ok][j][++size] = p + T[i][j];
				if ( sel == 1 ) one++;
				if ( sel == 2 ) two++;
				if ( sel == 3 ) tre++;
			}
			cant[ok][j] = size;
		}
		ok = !ok;
	}

    ok = !ok;
    for ( i = 1; i <= M; i++ )
    {
        while ( cant[ok][i] )
        {
              S.push( Q[ok][i][cant[ok][i]--] );
        }
    }

    k = 0;
    while ( k < K - 1 )
    {
          k++;
          printf( "%d ", S.top() );
          S.pop();
    }
    
    printf( "%d\n", S.top() );
    
	return 0;
}

