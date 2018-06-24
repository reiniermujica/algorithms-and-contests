/*
 Reinier César Mujica
 15/4/08 PSN - 2008
*/

#include <iostream>
#include <string>
#include "robot.h"

using namespace std;

const int
    MAXN = 1001,
    mov[4][2] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
    
const string com[4] = { "up", "right", "left", "down" };

int sol;
bool mk[2*MAXN][2*MAXN];

bool ok( int x ) {
     if ( move( com[x] ) == "ok" ) return 1;
     return 0;
}

void dfs( int x, int y, int m ) {
     sol++;
     mk[x][y] = true;
     for (int i = 0; i < 4; i++ ) {
        int cx = x + mov[i][0];
        int cy = y + mov[i][1];
        if ( !mk[cx][cy] ) {
          if ( ok( i ) ) dfs( cx, cy, i );
        }
     }
     if ( m == 0 ) move( com[3] );
     if ( m == 3 ) move( com[0] );
     if ( m == 1 ) move( com[2] );
     if ( m == 2 ) move( com[1] );
}

int main() {
    init();
   
    dfs( MAXN, MAXN , -1);

    cout << sol << endl;
    
    solution();

    fflush( stdout );
    return 0;
}
