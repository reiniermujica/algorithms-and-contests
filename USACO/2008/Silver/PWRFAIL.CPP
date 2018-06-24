/*
 PROG: pwrfail
 LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int
	MAXN = 1050,
	oo = 1 << 30;
	
typedef double real;

struct point {
	int x, y;
	point( int a = 0, int b = 0 ) {
		x = a; y = b;
	}
};

int N, M;
real R, sol;
int i, j, k;
int x, y;
real min_val[MAXN];
point L[MAXN];
bool mk[MAXN][MAXN];

queue < int > Q;

real dist( int a, int b ) {
	 if ( mk[a][b] ) return 0;
	 real h1 = abs( L[a].x - L[b].x );
	 real h2 = abs( L[a].y - L[b].y );
	 return sqrt( ( h1 * h1 ) + ( h2 * h2 ) );
}

void bfs() {
     for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		int act = Q.front();
		for ( i = 1; i <= N; i++ ) 
			if ( i != act ) {
			 real dista = dist( act, i );
			 if ( dista > R ) continue;
			 if ( min_val[i] > min_val[act] + dista ) {
				min_val[i] = min_val[act] + dista;
				Q.push( i );
			 }
		}
	 }
}

int main() {
	
	freopen( "pwrfail.in", "r", stdin );
	freopen( "pwrfail.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	scanf( "%lf", &R );
	  
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d", &x, &y );
		L[i] = point( x, y );
	}
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d", &x, &y );
		mk[x][y] = true;
		mk[y][x] = true;
	}
	
	for ( i = 2; i <= N; i++ )
	 min_val[i] = oo;
	 
	bfs();
	if ( min_val[N] == oo ) printf( "-1\n" );
	else {
      	int sol = min_val[N] * 1000 ;
        printf( "%d\n", sol );
    }
	return 0;
}
