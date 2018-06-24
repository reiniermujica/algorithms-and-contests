/*
 Reinier César Mujica
 xx/08/2008
 "Relaciones"
 Esta solucion no da para el jd #2
 Me parece que no es óptima
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXV = 1002,
	MAXE = 10002;

struct EDGE {
	int v, next;
	EDGE ( int a = 0, int b = 0 ) {
		v = a; next = b;
	}
} ls[2 * MAXE], ls_e[2 * MAXE];

int N, M, sol;
int i, j, k, v;
int C, C_E;
int last[MAXV], last_e[MAXV];
int min_val[MAXV];

int dfs( int x ) {
	if ( min_val[x] != -1 ) return min_val[x];
	
	min_val[x] = 0;
	for ( int i = last[x]; i; i = ls[i].next )
		min_val[x] >?= dfs( ls[i].v ) + 1;
	
	for ( int i = last_e[x]; i; i = ls_e[i].next )
		min_val[x] >?= dfs( ls_e[i].v );
	
	return min_val[x];
}

int main() {

    freopen( "relats.in", "r", stdin );
    freopen( "relats.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	FOR( i, 1, M ) {
		scanf( "%d %d %d", &j, &k, &v );
		if ( v == 0 ) {
			ls_e[++C_E] = EDGE( k, last_e[j] );
			last_e[j] = C_E;
			
			ls_e[++C_E] = EDGE( j, last_e[k] );
			last_e[k] = C_E;
		}
		else {
            if ( v == -1 ) {
		 	 ls[++C] = EDGE( j, last[k] );
			 last[k] = C;
            }
			else {
			 ls[++C] = EDGE( k, last[j] );
			 last[j] = C;
			}
		}
	}
	
	fill( min_val, min_val + MAXV, -1 );
	sol = -1;
	
	FOR( i, 1, N ) 
	 sol >?= dfs( i );
	
	if ( sol != -1 ) {
		FOR( i, 1, N ) {
			for ( j = last[i]; j; j = ls[j].next ) 
				if ( min_val[i] < min_val[ls[j].v] ) {
					sol = -1;
					break;				
				}
			if ( sol == -1 ) break;
			for ( j = last_e[i]; j; j = ls_e[j].next ) 
				if ( min_val[i] != min_val[ls_e[j].v] ) {
					sol = -1;
					break;				
				}
			if ( sol == -1 ) break;
		}
	}
	
	if ( sol != -1 ) {
		printf( "%d\n", sol );
		FOR( i, 1, N )
		 printf( "%d\n", min_val[i] );
	}
	else printf( "NO\n" );
	
    fflush( stdout );
    return 0;
}
