/*
 Reinier César Mujica
 1/10/2008
 "Cazador"
 A little shit
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 5010,
    oo = 1 << 29;

struct DUCKS {
	int x, y, val;
	
	bool operator < ( const DUCKS &other ) const {
		if ( x != other.x ) return x < other.x;
		return y < other.y;
	}
};

int N, sol;
int i, j, k;
int cx, cy, val;
int s1, s2;
int x = oo, rx, y = oo, ry;
int dx[MAXN], dy[MAXN];

vector < DUCKS > L;

int main() {

    freopen( "CAZADOR.ENT", "r", stdin );
    freopen( "CAZADOR.SAL", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d %d", &cx, &cy, &val );
        L.push_back( (DUCKS) { cx, cy, val } );
		dx[cx] += val;
		dy[cy] += val;
		x <?= cx; rx >?= cx;
		y <?= cy; ry >?= cy;
	}
	
	sort( L.begin(), L.end() );
	for ( i = x; i <= rx; i++ )
	 for ( j = y; j <= ry; j++ ) {

      if ( k < N && L[k].x == i && L[k].y == j ) {
        val = L[k].val; k++;
        while ( L[k].x == i && L[k].y == j && k < N ) {
            val += L[k].val;
            k++;
        }
      }
      else
       val = 0;
	  val = dx[i] + dy[j] - val;
	  if ( val > sol ) {
		sol = val;
		s1 = i; s2 = j;
	  }
	 }
	
	printf( "%d %d\n", s1, s2 );
	printf( "%d\n", sol );
	
    fflush( stdout );
    return 0;
}
