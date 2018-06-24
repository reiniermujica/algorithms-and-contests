/*
 Reinier Cesar Mujica
 4/06/08
 "Batalla Marítima"
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int
    MAXN = 1052,
    mov[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    
int N, M, i, j, k, sol;
char C[MAXN][MAXN];
bool ok;
queue < pair < int, int > > Q;
  
void bfs( int x, int y ) {
     int i, j, k, cx, cy;
     Q.push( make_pair( x, y ) );
     while ( !Q.empty() ) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        
        for ( k = 0; k < 4; k++ ) {
          cx = x + mov[k][0];
          cy = y + mov[k][1];
          if ( cx > 0 && cx <= N && cy > 0 && cy <= M
            && C[cx][cy] == '#' ) {
             C[cx][cy] = '1';
             Q.push( make_pair( cx, cy ) );
          }
        }
    }
}

int main() {

    scanf( "%d %d\n", &N, &M );
    
    while ( N && M ) {
      sol = 0;
      for ( i = 0; i < N; i++ ) {
       gets( C[i + 1] + 1 );
      }

      ok = true;
      for ( i = 1; i <= N; i++ ) {
       for ( j = 1; j <= M; j++ ) {
        if ( C[i][j] == '#' ) continue;
          if ( C[i - 1][j] == '#' && C[i][j + 1] == '#' ) {
            ok = false;
            break;
          }
          if ( C[i][j + 1] == '#' && C[i + 1][j] == '#' ) {
            ok = false;
            break;
          }
          if ( C[i + 1][j] == '#' && C[i][j - 1] == '#' ) {
            ok = false;
            break;
          }
          if ( C[i][j - 1] == '#' && C[i - 1][j] == '#' ) {
            ok = false;
            break;
          }
       }
       if ( !ok ) break;
      }
      if ( !ok )
       printf( "Mal distribucion.\n" );
      else {
       for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
         if ( C[i][j] == '#' ) {
            sol++;
            bfs( i, j );
         }
       printf( "Existen %d barcos.\n", sol );
      }
      scanf( "%d %d\n", &N, &M );
    }

    fflush( stdout );
    return 0;
}
