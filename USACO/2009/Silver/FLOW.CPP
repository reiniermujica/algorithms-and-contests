/*
 Reinier César Mujica
 11 - 2 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 257,
	src = 'A',
	snk = 'Z';
	
int N = MAXN - 1, E, sol;
int i, j, k;
int cap[MAXN][MAXN], fl[MAXN][MAXN];
int flow[MAXN], last[MAXN];
char a, b;

bool augment( int source, int sink ) {
	 
	 memset( flow, 0, sizeof flow );
	 memset( last, -1, sizeof last );
	 flow[source] = 1 << 30;
	 queue < int > Q;
	 for ( Q.push( source ); ( !Q.empty() && last[sink] < 0 ); Q.pop() ) {
		k = Q.front();
		for ( i = 65; i <= 122; i++ ) {
			if ( last[i] < 0 && fl[k][i] < cap[k][i] ) {
				flow[i] = min( flow[k], cap[k][i] - fl[k][i] );
				last[i] = k;
				Q.push( i );
			}
		}
	 }
	 
	 if ( last[sink] < 0 ) return false;
	 sol += flow[sink];
	 k = sink;
	 while ( k != src ) {
		fl[k][last[k]] -= flow[sink];
		fl[last[k]][k] += flow[sink];
		k = last[k];
	 }
	 
	 return true;
}

int main() {
	
	freopen( "flow.in", "r", stdin );
	freopen( "flow.out", "w", stdout );
	
	scanf( "%d\n", &E );
	for ( i = 1; i <= E; i++ ) {
		scanf( "%c %c %d\n", &a, &b, &k );
		cap[a][b] += k;
	}
	
	while ( augment( src, snk ) ) ;
	
	printf( "%d\n", sol );
	return 0;
}
