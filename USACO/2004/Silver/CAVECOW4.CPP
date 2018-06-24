/*
 Reinier César Mujica
 17 - 10 - 2008
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 50010,
	oo = 1 << 30,
    dx[24] = { 2, 1, 0,-1,-2, 2, 1, 0,-1,-2,2,1,-1,-2,2,1,0,-1,-2,2,1,0,-1,-2},
    dy[24] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0, 0, 0,1,1,1, 1, 1,2,2,2, 2, 2};

struct point {
	int x, y, id;
	point( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; id = c;
	}
	bool operator < ( const point &other ) const {
		 if ( x != other.x ) return x < other.x;
		 return y < other.y;
	}
	bool operator == ( const point &other ) const {
		 return ( x == other.x && y == other.y );
    }
} L[MAXN];

int N, T, sol;
int i, j, k;
int min_val[MAXN];
queue < point > Q;

int isok( point a ) {
	 int lo, hi, mid;
	 lo = 1; hi = N;
	 while ( lo <= hi ) {
		mid = ( lo + hi ) >> 1; // is very fasetest than /
		if ( L[mid] == a ) return mid;
		if ( L[mid] < a ) lo = mid + 1;
		else hi = mid - 1;
	 }
	 return -1;
}

int main() {
	
	freopen( "cavecow4.in", "r", stdin );
	freopen( "cavecow4.out", "w", stdout );
	
	scanf( "%d %d", &N, &T );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d", &j, &k );
		L[i] = point( j, k, i );
	}
	
	/* fill */
	sort( L + 1, L + N + 1 );
	fill( min_val, min_val + MAXN, oo );
	min_val[0] = 0;
	for ( i = 1; i <= N; i++ ) L[i].id = i;

	/* BFS */
	for ( Q.push( point( 0, 0, 0 ) ); !Q.empty(); Q.pop() ) {
		point top = Q.front();
		
		for ( j = 0; j < 24; j++ ) {
            int cx = top.x + dx[j];
            int cy = top.y + dy[j];
            k = isok( point( cx, cy ) );
            if (  k != -1  ) {
			  if ( min_val[k] > min_val[top.id] + 1 ) {
				min_val[k] = min_val[top.id] + 1;
				Q.push( point( cx, cy, k ) );
			  }
            }
        }
    }
    
	/* print */
	sol = oo;
	for ( i = 1; i <= N; i++ )
     if ( L[i].y == T ) sol <?= min_val[i];
	
	printf( "%d\n", ( sol != oo ) ? sol : -1 );
	return 0;
}
