/*
 Reinier César Mujica
 11-10-2008
 The day of the first force stealing
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 150,
	oo = 1 << 30,
	mov[4][3] = { {-1,0,1}, {1,0,0}, {0,1,3}, {0,-1,2} };
	
struct cell {
	int x, y, z;
	cell( int a = 0, int b = 0 ) {
		x = a; y = b;
	}
	bool operator != ( const cell &other ) const {
		return ( x != other.x ) || ( y != other.y );
	}
};

int N, M, sol;
int i, j, k;
char cad[MAXN][MAXN];
int min_val[MAXN][MAXN];
int last[MAXN][MAXN];
cell path[MAXN * MAXN * 2];
cell start, end;

char dir( int m ) {
	 if ( m == 0 ) return 'N';
	 if ( m == 1 ) return 'S';
	 if ( m == 2 ) return 'E';
	 if ( m == 3 ) return 'W';
}

int main() {

	freopen( "navcit.in", "r", stdin );
	freopen( "navcit.out", "w", stdout );
	
	scanf( "%d %d\n", &N, &M );
	N = (N * 2)-1; M = (M * 2)-1;
	for ( i = 1; i <= N; i++ ) {
		gets( cad[i] + 1 );
		for ( j = 1; j <= M; j++ ) {
		 if ( cad[i][j] == 'S' ) {
			start = cell( i, j );
		 }
		 if ( cad[i][j] == 'E' ) {
			end = cell( i, j );
		 }
        }
	}

	/* fill */
	for ( i = 1; i <= N; i++ )
	 fill( min_val[i], min_val[i] + MAXN, oo );
	min_val[start.x][start.y] = 0;
    last[start.x][start.y] = -1;
    
    /* BFS */
	queue < cell > Q;
	for ( Q.push( start ); !Q.empty(); Q.pop() ) {
		cell act = Q.front();
		for ( i = 0; i < 4; i++ ) {
			int x = act.x + mov[i][0];
			int y = act.y + mov[i][1];
			if ( x > 0 && x <= N && y > 0 && y <= M &&
				 cad[x][y] != '.' ) {
			  if ( min_val[x][y] > min_val[act.x][act.y] + 1 ) {
				min_val[x][y] = min_val[act.x][act.y] + 1;
				last[x][y] = mov[i][2];
				Q.push( cell( x, y ) );
			  }	 
			}
		}
	}

    /* path */
	cell act = end;
	while ( act != start ) {
		int x = act.x;
		int y = act.y;
		int z = last[act.x][act.y];
		int cont = 0;		
		while ( last[x][y] == z ) {
			x = x + mov[z][0];
			y = y + mov[z][1];
			cont++;
		}
		path[++sol] = cell( cont, mov[z][2] );
		act = cell( x, y );
    }
	
    /* print */
	for ( i = sol; i > 0; i-- )
     printf( "%c %d\n", dir( path[i].y ), path[i].x / 2 );

	return 0;
}
