/*
 Reinier César Mujica
 10 - 3 - 2009
 "Convex Hull"
 O(N * lg(N))
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

#define SQR( x ) ( x ) * ( x )

using namespace std;

const int
	MAXN = 100100,
	oo = 1 << 30;
	
typedef double real;

struct point {
	int x, y, id;
	point ( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; id = c;
	}
	bool operator < ( const point &b ) const {
		if ( x != b.x ) return x < b.x;
		if ( y != b.y ) return y < b.y;
		return id > b.id;
	}
} T[MAXN];

int N, Q, m, top;
int i, j, k;
real sol;
int S[MAXN];

real dist( point a, point b ) {
	 return sqrt( SQR( a.x - b.x ) + SQR( a.y - b.y ) );
}

int cross( const point &a, const point &b, const point &c ) {
	return ( a.x - c.x ) * ( b.y - c.y ) -
		   ( b.x - c.x ) * ( a.y - c.y );
}

bool cmp_cross( const point &a, const point &b ) {
  	 int cc = cross( a, b, T[0] );
  	 if ( cc != 0 ) return cc > 0;
  	 return a < b;
}
  
int main() {

    for ( scanf( "%d", &Q ); Q; Q-- ) {
    
		scanf( "%d", &N );

		T[0] = point( oo, oo, -oo ); m = 0;
		for ( i = 1; i <= N; i++ ) {
			scanf( "%d %d", &j, &k );
			T[i] = point( j, k, i );
			if ( T[i].y < T[m].y || ( T[i].y == T[m].y && T[i].x < T[m].x ) )
				m = i;
		}

		T[0] = T[m];
		swap( T[N], T[m] ); N--;
    
		/* ...Convex Hull... */
   		sort( T + 1, T + N + 1, cmp_cross );
    	for ( top = 0; top < 2 && top <= N; top++ )
			S[top] = top;
        top--;
		for ( i = 2; i <= N; i++ ) {
			while ( top > 0 && cross( T[i], T[S[top]], T[S[top - 1]] ) >= 0 ) top--;
			S[++top] = i;
		}
		
		/* calc dist */
		for ( i = 0, sol = 0; i < top; i++ )
			sol += dist( T[S[i]], T[S[i + 1]] );
		sol += dist( T[S[top]], T[S[0]] );

        printf( "%.2lf\n", sol );
        for ( i = 0; i <= top; i++ )
         printf( "%d ", T[S[i]].id );
        printf( "\n"); printf( "\n");
    }
    
    fflush(stdout);
	return 0;
}
