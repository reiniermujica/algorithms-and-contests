#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 510

int N, source, sink;
int i, j, k;
int cap[MAXN * 2][MAXN * 2];
int val[MAXN][3];
int flow = 0;
int last[MAXN * 2];

bool canfix(int x, int y)
{
	return ( val[x][0] < val[y][0] && val[x][1] < val[y][1] && val[x][2] < val[y][2] );
}

bool augment( int source, int sink )
{
	memset( last, -1, sizeof last );
	queue < int > Q;

	for ( Q.push( source ); !Q.empty() && last[sink] < 0; Q.pop() )
	{
		int next = Q.front();
		for ( int i = source; i <= sink; i++ )
		{
			if ( cap[next][i] > 0 && last[i] < 0 )
			{
				last[i] = next;
				Q.push(i);
			}
		}
	}

	if ( last[sink] < 0 ) return false;

	for ( int i = sink; i != source; i = last[i] )
	{
		cap[last[i]][i]--;
		cap[i][last[i]]++;
	}
	return true;
}

int main()
{
	scanf( "%d", &N );
	while ( N != 0 )
	{
		memset( cap, 0, sizeof cap );

		for ( i = 0; i < N; i++ )
		{
			scanf( "%d %d %d", &val[i][0], &val[i][1], &val[i][2] );
		}


		/* build the graph */
		source = 0; sink = 2 * N + 1;
		for ( i = 1; i <= N; i++ )
		{
			cap[source][i] = 1;
			cap[N + i][sink] = 1;
		}

		for ( i = 0; i < N; i++ )
		{
			for ( j = 0; j < N; j++ )
			{
				if ( i != j && canfix( i, j ) )
				{
					cap[i + 1][ ( j + 1 ) + N ] = 1;
				}
			}
		}

		flow = 0;
		while ( augment(source, sink) ) flow++;

		printf( "%d\n", N - flow );

		scanf( "%d", &N );
	}

	return 0;
}
