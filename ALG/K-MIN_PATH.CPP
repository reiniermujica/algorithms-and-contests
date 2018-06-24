/*
 Reinier César Mujica
 27/3/08 PSN - 2008
 update xx/08/2008
 K-th minimun path
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int
    MAXN = 1002;
    
typedef pair< int, int > par;

int N, E, K, sol;
int i, j, k;
int cant[MAXN];

vector< par > G[MAXN];
priority_queue< par, vector< par >, greater< par > > Q;

int main() {
   
    freopen( "kpath.in", "r", stdin );
    freopen( "kpath.out", "w", stdout );
	
    scanf( "%d %d %d", &N, &E, &K );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &j, &k, &sol );
        G[j].push_back( make_pair( k, sol ) );
    }
	
    Q.push( make_pair( 0, 1 ) );
    while ( !Q.empty() ) {
      int cost = Q.top().first;
      int node = Q.top().second;
      Q.pop();
      
	  cant[node]++;
      if ( node == N ){
         printf( "%d\n", cost );
         K--;
         if ( !K ) break;      
      }
      
	  for ( i = 0; i < G[node].size(); i++ ) {
        int next = G[node][i].first;
        int ncos = G[node][i].second + cost;
        
		if ( cant[next] >= K ) continue;
        Q.push( make_pair( ncos, next ) );      
      }
    }
	
    for ( i = K; i; i-- ) printf( "-1\n" ); // no exist path
    
	fflush(stdout);
    return 0;    
}
