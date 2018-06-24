/*
 Reinier César Mujica
 13 - 11 - 2008
 fuck time optimized
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 100001;

struct point {
	int x, y;
	bool operator < ( const point &o ) const {
		if ( x != o.x ) return x < o.x;
		return abs( y ) < abs( o.y );
	}
};	

int N, i, sol;
int lo, hi, mid;
point cant[MAXN];
point T[MAXN];
point event[2 * MAXN];

bool ok( int n ) {
     int i, j, k, s = 0;
     for ( i = 1; i <= n; i++ ) {
         cant[i].x = cant[i].y = 0;
         event[++s].x = T[i].x;
         event[s].y = i;
         event[++s].x = T[i].y;
         event[s].y = -i;
     }
     
     sort( event + 1, event + s + 1 );
     j = k = 0;
     for ( i = 1; i <= s; i++ ) {
         int id = event[i].y;
         if ( id > 0 ) {
            cant[id].x = j;
            cant[id].y = k;
            j++;
         }
         else {
            j--;
            if ( k - cant[abs( id )].y < cant[abs( id )].x )
             return false;
            k++;
         }
     }
     return true;
}

int main() {

	freopen( "paranoid.in", "r", stdin );
	freopen( "paranoid.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) 
		scanf( "%d %d", &T[i].x, &T[i].y );
		
	lo = 1; hi = N;
	while ( lo <= hi ) {
        mid = ( lo + hi ) >> 1;
		if ( ok( mid ) ) { lo = mid + 1; sol >?= mid; }
		else hi = mid - 1;
	}

    printf( "%d\n", sol );
	return 0;
}
