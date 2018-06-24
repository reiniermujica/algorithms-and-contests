/*
 Reinier César Mujica
 11/09/2008
 "Lowest Common Ancestor"
 Build : O(N)
 Query : O(sqrt(H))
 Nunca pense que me diera
 cuando empece ha programarlo
*/

#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const int
    MAXN = 40005;

struct edge {
	int v, cost, next;
	edge( int a = 0, int b = 0, int c = 0 ) {
		v = a; cost = b; next = c;
	}
} ls[2 * MAXN];

int N, M, H, RH;
int i, j, k, c;
int L[MAXN], last[MAXN];
int T[MAXN], P[MAXN];
int cost[MAXN], R[MAXN];
char ch;
bool mark[MAXN];

queue < int > Q;

void dfs( int node, int level ) {
     L[node] = level; H >?= level;     
     
	 for ( int i = last[node]; i; i = ls[i].next ) {
		int next = ls[i].v;
		if ( L[next] == 0 ) {
			T[next] = node;
			cost[next] = ls[i].cost;
			dfs( next, level + 1 );
		}
	 }
}

int query( int x, int y ) {
    int i = x, j = y, sol = 0;
    while ( P[i] != P[j] ) {
      if ( L[i] > L[j] ) {
		sol += R[i];
		i = P[i];
	  } 
      else {
	   sol += R[j];
       j = P[j];
	  }
    }
    
    while ( i != j ) {
      if ( L[i] > L[j] ) {
	   sol += cost[i];
       i = T[i];
	  }
      else {
	   sol += cost[j];
       j = T[j];
	  }
    }
	
    return sol;
}

int main() {

    freopen( "dquery.in", "r", stdin );
    freopen( "dquery.out", "w", stdout );

    scanf( "%d %d\n", &N, &M );
    for ( i = 1; i < N; i++ ) {
     scanf( "%d %d %d %c\n", &j, &k, &c, &ch );
     ls[i] = edge( k, c, last[j] );
	 last[j] = i;
	 ls[i + N] = edge( j, c, last[k] );
	 last[k] = i + N;
    }
    
    dfs( 1, 1 );

	RH = (int)sqrt( H );
	for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		int node = Q.front();
		mark[node] = true;
		
		if ( L[node] <= RH ) {
			P[node] = 1;
			R[node] = R[T[node]] + cost[node];
		}
		else
		if ( ( L[node] - 1 ) % RH == 0 ) {
			P[node] = T[node];
			R[node] = cost[node];
		}
		else {
			P[node] = P[T[node]];
			R[node] = R[T[node]] + cost[node];
		}
		
		for( i = last[node]; i; i = ls[i].next ) {
			int next = ls[i].v;
			if ( !mark[next] ) Q.push( next );
		}
	}

    scanf( "%d", &M );
    for ( i = 0; i < M; i++ ) {
      scanf( "%d %d", &j, &k );
      printf( "%d\n", query( j, k ) );
    }
    
    fflush( stdout );
    return 0;
}
