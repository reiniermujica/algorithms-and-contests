/*
 Reinier César Mujica
 7 - 5 - 2009
 Those profs wants to steal me twenty points
*/

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 0

const int
	MAXN = 2005,
	MAXK = 505;
	
struct stone {
	int x, p, num;
};

struct node {
	int next, cost, cd;
	node( int a = 0, int b = 0, int c = 0 ) {
		next = a; cost = b; cd = c;
	}
};

int N, K, sol, nodes;
int i, j, k, d, oo, c;
int x, y;
int dp[MAXN][MAXK];

struct state {
	int x, d, cost;
	bool operator < ( const state &other ) const {
		if ( cost != other.cost ) return cost < other.cost;
		return d < other.d;
	}
	state( int a = 0, int b = 0, int c = 0 ) {
		x = a; d = b; cost = c;
	}
};

multiset < state > Q;
multiset < state > :: iterator it;
vector < stone > S[MAXN];
vector < node > G[MAXN];

int main() {

	scanf( "%d %d", &N, &K );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &k );
		for ( j = 1; j <= k; j++ ) {
			scanf( "%d %d", &x, &y );
			S[i].push_back( (stone) { x, y, ++nodes } );
		}
	}
	
	/* build graph */
	S[0].push_back( (stone){ 0, 0, 0 } );
	S[N + 1].push_back( (stone){ 0, 0, nodes + 1 } );
	
	for ( i = 0; i <= N; i++ ) {
		for ( k = 0; k < S[i].size(); k++ ) {
			int act = S[i][k].num;
			int dis = S[i][k].x;
			int cos = S[i][k].p;
			
			for ( j = 0; j < S[i + 1].size(); j++ ) {
				int next = S[i + 1][j].num;
				int dist = S[i + 1][j].x;
				int cost = S[i + 1][j].p;
				int cc = abs( dist - dis );
				cc *= ( cos + cost );
				if ( !i || i == N ) cc = 0;
				G[act].push_back( node( next, cc, 0 ) );
			}
			
			for ( j = 0; j < S[i + 2].size(); j++ ) {
				int next = S[i + 2][j].num;
				int dist = S[i + 2][j].x;
				int cost = S[i + 2][j].p;
				int cc = abs( dist - dis );
				cc *= ( cos + cost );
				if ( !i || i == N - 1 ) cc = 0;
				G[act].push_back( node( next, cc, 1 ) );
			}
		}
	}
    
	memset( dp, 63, sizeof dp );
	dp[0][0] = 0; oo = dp[0][1];
	
	/* Dynamic Shortest Path using Dijkstra */
	Q.insert( state( 0, 0, 0 ) );
	while ( !Q.empty() ) {
		state act = ( *Q.begin() );
		Q.erase( Q.begin() );
		
		k = act.x;
		d = act.d;
		c = act.cost;
		
		for ( i = 0; i < G[k].size(); i++ ) {
			int next = G[k][i].next;
			int cost = G[k][i].cost + c;
			int doub = G[k][i].cd + d;
			if ( doub <= K && dp[next][doub] > cost ) {
                if ( dp[next][doub] != oo ) {
                    it = Q.find( state( next, doub, dp[next][doub] ) );
                    if ( it != Q.end() ) Q.erase( it );
                } //deleting states make a better time
                dp[next][doub] = cost;
				Q.insert( state( next, doub, dp[next][doub] ) );
			}
		}
	}

	sol = 1 << 30;
	for ( j = 0; j <= K; j++ )
      	sol <?= dp[nodes + 1][j];
    
	printf( "%d\n", sol );
	return 0;
}
