#include <cstdio>
#include <queue>
#include <algorithm>

#define REP( i, k, N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    MAXN = 152,
    oo = 1 << 29,
    mov[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

typedef pair < int, int > par;

struct point {
    int x, y;
};

int N, M, i, j, x, y, cx, cy;
int B[MAXN][MAXN];
char C[MAXN][MAXN];
point P[2];
queue < par > Q;

int main() {

    freopen( "munch.in", "r", stdin );
    freopen( "munch.out", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    
    REP( i, 1, N ) {
      gets( C[i] + 1 );
      fill( B[i], B[i] + MAXN, oo );
      REP( j, 1, M ) {
        if ( C[i][j] == 'B' ) {
            P[1].x = i;
            P[1].y = j;
        }
        if ( C[i][j] == 'C' ) {
            P[0].x = i;
            P[0].y = j;
            B[i][j] = 0;
        }
      }
    }

    /* BFS */
    Q.push( make_pair( P[0].x, P[0].y ) );
    while ( !Q.empty() ) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        
        REP( i, 0, 3 ) {
          cx = x + mov[i][0];
          cy = y + mov[i][1];
          if ( cx > 0 && cx <= N && cy > 0 && cy <= M ) {
            if ( C[cx][cy] != '*'  && B[cx][cy] > B[x][y] + 1 ) {
                B[cx][cy] = B[x][y] + 1;
                Q.push( make_pair( cx, cy ) );
            }
          }
        }
    }

    printf( "%d\n", B[P[1].x][P[1].y] );
    
    fflush( stdout );
    return 0;
}
