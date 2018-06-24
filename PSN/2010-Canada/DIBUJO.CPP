/*
 Reinier César Mujica
 12 - 9 - 2010
 Segment Tree
*/

#include <cstdio>

using namespace std;

const int
	MAXC = 500000,
	MAXR = MAXC * 5;
	
int N, sol;
int x, y;
int i, k, max_y;
int T[MAXR], ID[MAXR];

void build( int node, int lo, int hi ) {
     if ( lo == hi ) {
        ID[lo] = node;
        return ;
     }
     int mid = ( lo + hi ) / 2;
     build( node * 2, lo, mid );
     build( node * 2 + 1, mid + 1, hi );
     return ;
}

void update( int node, int lo, int hi, int x, int y ) {
     if ( lo > y || hi < x ) return ;    
     if ( lo >= x && hi <= y ) { // range cover all
         T[node]++;
         return ;
     }
    int mid = ( lo + hi ) / 2;
    update( node * 2, lo, mid, x, y );
    update( node * 2 + 1, mid + 1, hi, x, y );
    return ;
}

bool ok( int node ) {
     int res = 0;
     while ( node > 0 ) {
        res += T[node];
        node /= 2;
     }
     return res % 2;
}

int main() {
    
    freopen( "DIBUJO.in", "r", stdin );
    freopen( "DIBUJO.out", "w", stdout );

    build( 1, 1, 4 * MAXC );
    
    /* read  & update*/
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        update( 1, 1, 4 * MAXC, x, y );
        max_y >?= y;
    }
	
	/* querying */
    for ( i = 1; i <= max_y; i++ ) {
        if ( ok( ID[i] ) ) k++;
        else k = 0;
        sol >?= k;
    }
    
    printf( "%d\n", sol );
	return 0;
}
