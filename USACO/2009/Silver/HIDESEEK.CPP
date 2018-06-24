/*

*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
    MAXN = 20005,
    oo = 1 << 30;
    
int N, M;
int id, sol, cant;
int i, j, k;
int dist[MAXN];
vector < int > G[MAXN];
priority_queue < par, vector < par >, greater < par > > Q;

int main() {

    freopen( "hideseek.in", "r", stdin );
    freopen( "hideseek.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 0; i < M; i++ ) {
        scanf( "%d %d", &j, &k );
        G[j].push_back( k );
        G[k].push_back( j );
    }
    
    fill( dist, dist + MAXN, oo );
    dist[1] = 0;
    
    for ( Q.push( par( 0, 1 ) ); !Q.empty(); Q.pop() ) {
        int node = Q.top().second;
        int cost = Q.top().first + 1;
        for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( dist[next] > cost ) {
                dist[next] = cost;
                Q.push( par( cost, next ) );
            }
        }
    }
    
    for ( i = 2; i <= N; i++ ) {
        if ( dist[i] > sol && dist[i] != oo ) {
            sol = dist[i];
            id = i;
            cant = 1;
        }
        else
        if ( dist[i] == sol ) cant++;
    }
    
    printf( "%d %d %d\n", id, sol, cant );
    return 0;
}
