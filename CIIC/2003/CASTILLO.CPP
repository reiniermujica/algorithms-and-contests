/*
 Reinier Cesar Mujica
 17/06/2008
 "Castillo"
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

const int
    MAXN = 102,
    oo = 1 << 29,
    mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

typedef pair < int, int > par;

struct wall {
    bool N, S, E, O;
};

int N, M, sol = oo;
int i, j, k, px, py, x, y;
int dp[MAXN][MAXN];
wall T[MAXN][MAXN];

queue < par > Q;

void is_wall( int k ) {
     if ( k - 8 >= 0 ) {
        k -= 8; T[i][j].S = true;
     }
     if ( k - 4 >= 0 ) {
        k -= 4; T[i][j].E = true;
     }
     if ( k - 2 >= 0 ) {
        k -= 2; T[i][j].N = true;
     }
     if ( k - 1 >= 0 ) {
        k -= 1; T[i][j].O = true;
     }
}

int tell_me( int x, int y, int m ) {
    if ( !m ) return T[x][y].E;
    if ( m == 1 ) return T[x][y].S;
    if ( m == 2 ) return T[x][y].N;
    if ( m == 3 ) return T[x][y].O;
}

int main() {

    freopen( "CASTILLO.DAT", "r", stdin );
    freopen( "CASTILLO.SOL", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    
    REP( i, 1, N )
     REP( j, 1, M ) {
      scanf( "%d", &k );
      is_wall( k );
     }
    scanf( "%d %d", &px, &py );

    REP( i, 0, N + 1 )
     fill( dp[i], dp[i] + MAXN, oo );

    dp[px][py] = 0;
    Q.push( make_pair( px, py ) );
    while ( !Q.empty() ) {
      x = Q.front().first;
      y = Q.front().second;
      Q.pop();
      REP( i, 0, 3 ) {
        int cx = x + mov[i][0];
        int cy = y + mov[i][1];
        if ( cx > 0 && cx <= N && cy >= 0 && cy <= M ) {
          k = tell_me( x, y, i );
          if ( dp[cx][cy] > dp[x][y] + k ) {
            dp[cx][cy] = dp[x][y] + k;
            Q.push( make_pair( cx, cy ) );
          }
        }
        else
         sol <?= dp[x][y] + tell_me( x, y, i );
      }
    }

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
