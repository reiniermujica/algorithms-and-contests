#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1005

typedef pair < int, int > par;

struct edge
{
    int v, dist, cost;
    edge( int a = 0, int b = 0, int c = 0)
    {
        v = a; dist = b; cost = c;
    }
};

int N, E, S, T;
int i, j, k;
int sol[MAXN], dist[MAXN];
vector < edge > G[MAXN];
priority_queue< par, vector <par>, greater <par> > Q;
par solution = par( 1 << 30, 1 << 30 );

int main()
{
    scanf( "%d %d %d %d", &N, &E, &S, &T );
    for ( i = 0; i < E; i++ )
    {
        int a, b, c, d;
        scanf( "%d %d %d %d", &a, &b, &c, &d );
        G[a].push_back( edge( b, c, c - d ) );
        G[b].push_back( edge( a, c, c - d ) );
    }

    /* filling */
    fill( sol, sol + MAXN, 1 << 30 );
    fill( dist, dist + MAXN, 1 << 30 );
    sol[S] = dist[S] = 0;
    
    Q.push( par( 0, S ) );
    while ( !Q.empty() )
    {
        int node = Q.top().second;
        int cost = Q.top().first;
        Q.pop();
        
        if ( node == T )
        {
            if ( par( sol[node], dist[node] ) < solution )
                solution = par( sol[node], dist[node] );
            continue;
        }
        
        for ( i = 0; i < G[node].size(); i++ )
        {
            int next = G[node][i].v;
            int ncos = G[node][i].cost + sol[node];
            int ndis = G[node][i].dist + dist[node];
            
            if ( sol[next] > ncos )
            {
                sol[next] = ncos;
                dist[next] = ndis;
                Q.push( par( ncos, next ) );
            }
            else
            if ( sol[next] == ncos )
            {
                if ( dist[next] > ndis )
                {
                    dist[next] = ndis;
                    Q.push( par( ncos, next ) );
                }            
            }            
        }    
    }
    
    printf( "%d %d\n", solution.second, solution.first );
    
    return 0;    
}
