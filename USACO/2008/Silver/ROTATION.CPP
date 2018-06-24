/*
 PROG: rotation
 LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int
	MAXN = 1050;
	
struct edge {
	int x, y, z;
	edge( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; z = c;
	}
} L[MAXN];

queue < int > Q;

int N, M, sol;
int i, j, k, c;
int dir_mov[MAXN];

int main() {

	freopen( "rotation.in", "r", stdin );
	freopen( "rotation.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i < N; i++ ) {
		scanf( "%d %d %d", &j, &k, &c );
		L[i] = edge( j, k, c );
	}
	
	for ( i = 1; i <= N; i++ ) dir_mov[i] = -1;
	dir_mov[1] = 0;
	for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		
		int act = Q.front();
		int cm = dir_mov[act];
		
		for ( i = 1; i < N; i++ ) {
			if ( L[i].x == act ) {
				int next = L[i].y;
				int mov = L[i].z;
				if ( cm == 0 && mov == 1 ) {
					dir_mov[next] = 1;
					Q.push( next );	
				}
				else
				if ( cm == 1 && mov == 0 ) {
					dir_mov[next] = 1;
					Q.push( next );
				}				
				else {
					dir_mov[next] = 0;
					Q.push( next );
				}
			}
		}
	}
	
	printf( "%d\n", dir_mov[N] );
	return 0;
}
