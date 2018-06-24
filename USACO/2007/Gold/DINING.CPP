/*
 Reinier César Mujica
 26 - 12 - 2008
 do in test time...
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050;
	
int N, F, D, sol;
int i, j, k, cow;
int t1, t2, c1, c2;
int source = 0, sink;
int cant[MAXN], last[MAXN];
int cap[MAXN][MAXN], flow[MAXN][MAXN];

bool augment( int source, int sink ) {
	 int i, j, k;
	 
	 fill( cant, cant + MAXN, 1 << 30 );
	 fill( last, last + MAXN, -1 );
	 queue < int > Q;
	 
	 for ( Q.push( source ); !Q.empty(); Q.pop() ) {
		int act = Q.front();
		for ( i = 1; i <= cow; i++ ) {
			if ( flow[act][i] < cap[act][i] && last[i] == -1 ) {
				cant[i] = min( cant[act], cap[act][i] - flow[act][i] );
				last[i] = act;
				Q.push( i );
			}
		}
	 }

	 if ( last[sink] == -1 ) return false;
	 k = sink; j = cant[sink];

	 while ( last[k] != -1 ) {
    	flow[last[k]][k] += j;
		flow[k][last[k]] -= j;
		k = last[k];
	 }
	 return true;
}

int main() {
	
	freopen( "dining.in", "r", stdin );
	freopen( "dining.out", "w", stdout );
	
	scanf( "%d %d %d", &N, &F, &D );

	cow = F + D; k = cow + N; sink = k + N + 1;
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d", &c1, &c2 );
		for ( j = 1; j <= c1; j++ ) {
			scanf( "%d", &t1 );
			cap[t1][cow + i] = 1;
		}
		for ( j = 1; j <= c2; j++ ) {
			scanf( "%d", &t1 );
			cap[k + i][t1 + F] = 1;
		}
	}
	
	for ( i = 1; i <= F; i++ )
        cap[0][i] = 1;
	for ( i = 1; i <= D; i++ )
		cap[F + i][sink] = 1;
	for ( i = 1; i <= N; i++ )
        cap[cow + i][k + i] = 1;
	cow = sink;
	
	while ( augment( source, sink ) )
		sol++;
	
	printf( "%d\n", sol );
	return 0;
}
