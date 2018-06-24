#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 5005;

struct point {
    int x, y;
};

int N, i, j, sol;
point T[MAXN];
bool M[MAXN][MAXN];

bool isok( int x, int y ) {
     if ( x >= 0 && x < MAXN && y >= 0 && y < MAXN )
      return M[x][y];
     return 0;      
}

int main() {
    freopen( "ruin.in", "r", stdin );
    freopen( "ruin.out", "w", stdout );
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
     scanf( "%d %d", &T[i].x, &T[i].y );
     M[T[i].x][T[i].y] = true;
    }
        
    for ( i = 1; i <= N; i++ )
     for ( j = i+1; j <= N; j++ ){
      int dx = abs(T[i].x - T[j].x);
      int dy = abs(T[i].y - T[j].y);
      int lx = T[i].x + dy;
      int rx = T[i].y + dx;
      if ( !isok(lx,rx) ) continue;
      lx = T[j].x + dy;
      rx = T[j].y + dx;
      if ( isok(lx,rx) )
        sol >?= (dx*dx) + (dy*dy);
     }
     
    printf( "%d\n", sol );
    
    return 0;
}
