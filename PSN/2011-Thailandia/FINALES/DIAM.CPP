/*
    Not Tested yet
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 1002
typedef pair< int, int > par;

int N, sol;
int i, j, k;
int dist[MAXN][MAXN];
bool mark[MAXN];
vector< par > G[MAXN];
queue < par > Q;

int main()
{
	freopen( "DIAM.IN", "r", stdin );
	freopen( "DIAM.OUT", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i < N; i++ )
	{
		scanf( "%d %d %d", &j, &k, &sol );
		G[j].push_back( par( k, sol ) );
		G[k].push_back( par( j, sol ) );
	}

	for ( i = 1, sol = 0; i <= N; i++ )
	{
        fill( mark, mark + N + 2, false );
        mark[i] = true;
        
		Q.push( par( i, 0 ) );
		while ( !Q.empty() )
		{
            int node = Q.front().first;
            int cost = Q.front().second;
            Q.pop();
            sol >?= cost;

            for ( j = 0; j < G[node].size(); j++ )
            {
                int next = G[node][j].first;
                if ( !mark[next] )
                {
                    mark[next] = true;
                    dist[i][next] = G[node][j].second + cost;
                    Q.push( par( next, dist[i][next] ) );
                }
            }
        }
	}

    printf( "%d\n", sol );
    
	return 0;
}
