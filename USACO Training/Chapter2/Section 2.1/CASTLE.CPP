/*
 ID: reywork2
 PROG: castle
 LANG: C++
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 55,
	mov[4][3] = { {-1,0,1}, {1,0,0}, {0,1,3}, {0,-1,2} };

struct wall {
	bool w[4];
} T[MAXN][MAXN];
	
int N, M, sol, mm;
int mcut, s1, s2;
int scc[MAXN][MAXN];
int cant[MAXN * MAXN];
int i, j, k;
char ans;

bool check( int x, int y ) {
	 return ( x > 0 && x <= N && y > 0 && y <= M );
}

int dfs( int x, int y ) {
	int cant = 0;
	scc[x][y] = sol;
	for ( int i = 0; i < 4; i++ ) {
	  int cx = x + mov[i][0];
	  int cy = y + mov[i][1];
	  if ( check( cx, cy ) && scc[cx][cy] == 0 &&
	       !T[x][y].w[i] && !T[cx][cy].w[mov[i][2]] )
	   cant += dfs( cx, cy );
	}
	return cant + 1;
}

int main() {
	
	freopen( "castle.in", "r", stdin );
	freopen( "castle.out", "w", stdout );
	
	scanf( "%d %d", &M, &N );
	for ( i = 1; i <= N; i++ )
	 for ( j = 1; j <= M; j++ ) {
	  scanf( "%d", &k );
      if ( k >= 8 ) { T[i][j].w[1] = true; k -= 8; }
	  if ( k >= 4 ) { T[i][j].w[2] = true; k -= 4; }
	  if ( k >= 2 ) { T[i][j].w[0] = true; k -= 2; }
	  if ( k >= 1 ) { T[i][j].w[3] = true; k -= 1; }
	 }

	for ( i = 1; i <= N; i++ )
	 for ( j = 1; j <= M; j++ ) 
	  if ( scc[i][j] == 0 ) {
		sol++;
		cant[sol] = dfs( i, j );
		mm >?= cant[sol];
	  }
	
    for ( j = 1; j <= M; j++ )
     for ( i = N; i > 0; i-- ) {
        int cx, cy, value;
        cx = i - 1; cy = j;
		if ( check( cx, cy ) && scc[cx][cy] != scc[i][j] ) {
    		value = cant[scc[i][j]] + cant[scc[cx][cy]];
  		    if ( value > mcut ) {
			  mcut = value;
			  s1 = i; s2 = j; ans = 'N';
		    }
        }
        cx = i; cy = j + 1;
		if ( check( cx, cy ) && scc[cx][cy] != scc[i][j] ) {
		    value = cant[scc[i][j]] + cant[scc[cx][cy]];
   		    if ( value > mcut ) {
			  mcut = value;
			  s1 = i; s2 = j; ans = 'E';
            }
        }
    }
    
	printf( "%d\n", sol );
	printf( "%d\n", mm );
	printf( "%d\n", mcut );
	printf( "%d %d %c\n", s1, s2, ans );

	return 0;
}
