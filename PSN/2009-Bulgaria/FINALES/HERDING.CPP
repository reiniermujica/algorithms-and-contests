/*
 Reinier César Mujica
 27 - 4 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
    MAXN = 1050,
    mov[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    
int N, M, sol;
int i, j, k;
int T[MAXN][MAXN];
int comp[MAXN][MAXN];
char cad[MAXN];
int num[300];

void bfs( int x, int y ) {
     int i, k;
     
     queue < par > Q;
     for ( Q.push( par( x, y ) ); !Q.empty(); Q.pop() ) {
        par top = Q.front();
        for ( i = 0; i < 4; i++ ) {
            int cx = top.first + mov[i][0];
            int cy = top.second + mov[i][1];
            if ( cx > 0 && cx <= N && cy > 0 && cy <= M && !comp[cx][cy] ) {
                k = ( i + 2 ) % 4;
                if ( T[cx][cy] == k ) {
                    comp[cx][cy] = sol;
                    Q.push( par( cx, cy ) );
                }
                else
                if ( T[top.first][top.second] == i ) {
                    comp[cx][cy] = sol;
                    Q.push( par( cx, cy ) );
                }
            }
        }
     }
}

int main() {
    
    num['N'] = 0; num['E'] = 1; num['S'] = 2; num['W'] = 3;
   
    scanf( "%d %d\n", &N, &M );
    for ( i = 1; i <= N; i++ ) {
        gets( cad + 1 );
        for ( j = 1; j <= M; j++ )
            T[i][j] = num[cad[j]];
    }
    
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
            if ( comp[i][j] == 0 ) {
                sol++;
                comp[i][j] = sol;
                bfs( i, j );
            }
     
    printf( "%d\n", sol );
    return 0;
}
