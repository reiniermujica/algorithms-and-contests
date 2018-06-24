/*
 Reinier César Mujica
 5/3/08
 "Convex Hull"
 O(N * lg(N))
 update 24/11/2008
 fixed input bugs and convex hull bugs
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

#define SQR( x ) \
	(x) * (x)
	
using namespace std;

const int
	MAXN = 50002,
	oo = 1 << 29;
	
typedef double real;

struct point {
	int x, y;
	point ( int a = 0, int b = 0 ) {
		x = a; y = b;
	}
	
	bool operator < ( const point &b ) const {
		if ( x != b.x ) return x < b.x;
		return y < b.y;
	}
} T[MAXN], mleft = point( oo, oo );

int N, top;
int i, j, k;
real sol;
int S[MAXN];

real dist( point a, point b ) {
	 return sqrt( SQR( a.x - b.x ) + SQR( a.y - b.y ) );
}

int cross( const point &a, const point &b, const point &c ) {
	return  (a.x - c.x) * (b.y - c.y) -
			(b.x - c.x) * (a.y - c.y);
}

bool cmp_cross( const point &a, const point &b ) {
	 return cross( a, b, T[0] ) > 0;
}
 
int main() {

	freopen( "convex.in", "r", stdin );
	freopen( "convex.out", "w", stdout );

	scanf( "%d", &N );	
	for ( i = 0; i < N; i++ ) {
     scanf( "%d %d", &j, &k );
	 T[i] = point( j, k );
	 if ( T[i] < T[0] ) swap( T[i], T[0] );
	}
	
	sort( T + 1, T + N, cmp_cross );
	
	/* ... Convex Hull...*/
	for ( top = 0; top < 2; top++ )
	 S[top] = top;
	 
	for ( i = 2; i < N; i++ ) {
		while ( cross( T[i], T[S[top]], T[S[top - 1]] ) > 0 ) top--;
		S[++top] = i;
	}
	
	for ( i = 1; i <= top; i++ )
		sol += dist( T[S[i]], T[S[i - 1]] );
	sol += dist( T[S[top]], T[0] );
	
    printf( "%d %.2lf\n", top + 1, sol );
	for ( i = 0; i <= top; i++ )
	 printf( "%d %d\n", T[S[i]].x, T[S[i]].y );
	
    fflush(stdout);
	return 0;
}
