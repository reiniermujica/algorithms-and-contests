/*
 Reinier Cesar Mujica
 5/10/2008
 "Lowest Common Ancestor"
 Build : O(N)
 Query : O(sqrt(H))
 Update: O(sqrt(H))
*/

#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const int
    MAXN = 40015;

struct edge {
	int v, cost, next;
	edge( int a = 0, int b = 0, int c = 0 ) {
		v = a; cost = b; next = c;
	}
} ls[2 * MAXN];

int N, M, H, RH, cases;
int i, j, k, c;
int L[MAXN], last[MAXN];
int T[MAXN], P[MAXN];
int cost[MAXN], R[MAXN];
char cad[20];
bool mark[MAXN];

queue < int > Q;

int wath( char *st ) {
    if ( strstr( st, "DONE" ) ) return 0;
    if ( strstr( st, "QUERY" ) ) return 1;
    if ( strstr( st, "CHANGE" ) ) return 2;
}

void bfs() {
	 int node, i;
	 L[1] = 1;
	 for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		node = Q.front();
	    H >?= L[node];
		
	    for ( i = last[node]; i; i = ls[i].next ) {
		  int next = ls[i].v;
		  if ( L[next] == 0 ) {
			T[next] = node;
			cost[next] = ls[i].cost;
			L[next] = L[node] + 1;
			Q.push( next );
		  }
	    }
	 }
}

int query( int x, int y ) {
    int i = x, j = y, sol = 0;
    while ( P[i] != P[j] ) {
      if ( L[i] > L[j] ) {
		sol >?= R[i];
		i = P[i];
	  } 
      else {
	   sol >?= R[j];
       j = P[j];
	  }
    }
    
    while ( i != j ) {
      if ( L[i] > L[j] ) {
	   sol >?= cost[i];
       i = T[i];
	  }
      else {
	   sol >?= cost[j];
       j = T[j];
	  }
    }
	
    return sol;
}

void change( int ii, int cos ) {
	 int x = ls[ii].v, y = ls[ii + N].v;
	 if ( L[x] < L[y] ) swap( x, y );
	 int level = L[x];
	 cost[x] = cos;
	 if ( ( level - 1 ) % RH == 0 )
		R[x] = cos;
	 else
		R[x] = R[T[x]] >? cost[x];

	 for ( Q.push( x ); !Q.empty(); Q.pop() ) {
		int node = Q.front();
		
		for ( int i = last[node]; i; i = ls[i].next ) {
			int next = ls[i].v;
			if ( L[next] <= L[node] ) continue;
			if ( ( L[next] - 1 ) % RH == 0 ) continue;

			R[next] = R[node] >? cost[next];
			Q.push( next );
		}
	 }
}

int main() {

  	scanf( "%d", &cases );
    while ( cases-- ) {
	
		scanf( "%d", &N );
		
		/* fill */
		for ( i = 0; i < N + 5; i++ )
		 L[i] = last[i] = mark[i] = 0;

    	for ( i = 1; i < N; i++ ) {
			scanf( "%d %d %d\n", &j, &k, &c );
			ls[i] = edge( k, c, last[j] );
			last[j] = i;
			ls[i + N] = edge( j, c, last[k] );
			last[k] = i + N;
		}
    
		bfs();		
		RH = (int)sqrt( H );
		if ( RH > H || RH <= 0 ) RH = H;
		
		for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
			int node = Q.front();
			mark[node] = true;
		
			if ( L[node] <= RH ) {
				P[node] = 1;
				R[node] = R[T[node]] >? cost[node];
			}
			else
			if ( ( L[node] - 1 ) % RH == 0 ) {
				P[node] = T[node];
				R[node] = cost[node];
			}
			else {
				P[node] = P[T[node]];
				R[node] = R[T[node]] >? cost[node];
			}
		
			for( i = last[node]; i; i = ls[i].next ) {
				int next = ls[i].v;
				if ( !mark[next] ) Q.push( next );
			}
		}

		for( ;; ) {
			scanf( "%s", &cad );
			k = wath( cad );
			if ( !k ) break;
			
			scanf( "%d %d\n", &j, &c );
			if ( k == 1 )
			 printf( "%d\n", query( j, c ) );
			else
			 change( j, c );
		}
		scanf( "\n" );
    
	}
	
    fflush( stdout );
    return 0;
}
