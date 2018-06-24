/*
 Reinier César Mujica
 18 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 105;

struct puzzle {
	int n;
	char c[5];
} ls[MAXN * MAXN], C[MAXN][MAXN], ac;
	
int N, M;
int i, j, k;
int T[MAXN][MAXN];
bool used[MAXN * MAXN];

void rotate( puzzle &x ) {
	 char d = x.c[1];
	 for ( int i = 1; i <= 3; i++ )
		x.c[i] = x.c[i + 1];
	 x.c[4] = d;
}

bool ok( int x, int y, int f ) {
     ac = ls[f];
    
    for ( int i = 0; i < 5; i++ ) {
        rotate( ac );
        if ( x == 1 && y == 1 ) {
            if ( ac.c[1] != '0' || ac.c[4] != '0' )
              continue;
            else return true;
        }
        if ( x == 1 && y == M ) {
            if ( ac.c[1] != '0' || ac.c[2] != '0' )
                continue;
            if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
            return true;
        }
        if ( x == N && y == 1 ) {
           if ( ac.c[3] != '0' || ac.c[4] != '0' )
                continue;
            if ( ac.c[1] != C[x - 1][y].c[3] ) continue;
            return true;
        }
        if ( x == N && y == M ) {
            if ( ac.c[2] != '0' || ac.c[3] != '0' )
                continue;
            if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
            return true;
        }
        if ( x == 1 ) {
            if ( ac.c[1] != '0' ) continue;
            if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
            return true;
        }
        if ( y == 1 ) {
            if ( ac.c[4] != '0' ) continue;
            if ( ac.c[1] != C[x - 1][y].c[3] ) continue;
            return true;
        }
        if ( x == N ) {
            if ( ac.c[3] != '0' ) continue;
            if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
            if ( ac.c[1] != C[x - 1][y].c[3] ) continue;
            return true;
        }
        if ( y == M ) {
            if ( ac.c[2] != '0' ) continue;
            if ( ac.c[1] != C[x - 1][y].c[3] ) continue;
            if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
            return true;
        }
        
        if ( ac.c[1] != C[x - 1][y].c[3] ) continue;
        if ( ac.c[4] != C[x][y - 1].c[2] ) continue;
        return true;
    }
    
    return false;
}

void dfs( int x, int y ) {
	 for ( int i = 1; i <= N * M; i++ ) {
        if ( !used[i] && ok( x, y, i ) ) {
            used[i] = true;
            C[x][y] = ac;
            if ( x == N && y == M ) {
            	for ( i = 1; i <= N; i++ )
            	 for ( j = 1; j <= M; j++ )
               	  printf( "%d %c %c %c %c\n", C[i][j].n, C[i][j].c[1], C[i][j].c[2],
                                              C[i][j].c[3], C[i][j].c[4] );
                 exit( 0 );
            }
            if ( y == M ) dfs( x + 1, 1 );
            else dfs( x, y + 1 );
            used[i] = false;
        }
     }
}

int main() {
	
	freopen( "jigsaw.in", "r", stdin );
	freopen( "jigsaw.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N * M; i++ )
		scanf( "%d %c %c %c %c\n", &ls[i].n, &ls[i].c[1], &ls[i].c[2],
                                   &ls[i].c[3], &ls[i].c[4] );

	dfs( 1, 1 );

	fflush( stdout );
	return 0;
}
