/*
 Reinier Cesar Mujica
 28/2/08 9:45pm.
 update xx/08/2008
*/

#include <cstdio>

const int 
    MAXN = 100002;
    
struct abi {
	int N;
	int i, res;
	int tree[MAXN];

	int low_bit( int x ) {
	    return x & -x;	
    }
	
	void update( int pos, int value ) {
		for( i = pos; i <= N; i += low_bit( i ) )
			tree[i] += value;
	}
	
	int get_sum( int pos ) {
		for ( res = 0, i = pos; i; i -= low_bit( i ) )
		 res += tree[i];
		return res;
	}
	
} T;

int a, b, i, val, Q;
    
int main() {

    scanf( "%d" , &T.N );
    for ( i = 1; i <= T.N; i++ ) {
		scanf( "%d", &val );
		T.update( i, val ); 
    }
	
    scanf( "%d", &Q );
    while ( Q-- ) {
		scanf( "%d %d %d", &val, &a, &b );
		if ( val == -1 ) { // update a whit b
			T.update( a, b );
		}
		else {
			printf( "%d\n", T.get_sum( b ) - T.get_sum( a-1 ) );
		}
	}
	
    fflush(stdout);
    return 0;
}
