/*
 Reinier César Mujica
 21 - 12 - 2008
 Need more Study, no more PES...
*/

#include <cstdio>

using namespace std;

const int
	MAXL = 50010;
	
struct node {
	int cant, next, flag;
} trie[MAXL * 4][2];

int N, M;
int i, j, k;
int ini, fin;
int sol, last, delta = 1;
int bit[MAXL];

int main() {

	freopen( "sec.in", "r", stdin );
	freopen( "sec.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &k );
		for ( j = 1; j <= k; j++ )
			scanf( "%d", &bit[j] );
		
		ini = 1; fin = 1; j = 1;
		while ( fin <= k && trie[ini][bit[fin]].next ) {
			trie[ini][bit[fin]].cant++;
        	if ( k == fin )
				  trie[ini][bit[fin]].flag++;
			ini = trie[ini][bit[fin]].next;
        	fin++;
		}
		if ( fin == k + 1 ) continue;
		
		while ( fin <= k ) {
			trie[ini][bit[fin]].next = ( k != fin ) ? ++delta : 0;
			trie[ini][bit[fin]].cant++;
			if ( k == fin )
				  trie[ini][bit[fin]].flag++;
			ini = delta;
			fin++;
		}
	}
	
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d", &k );
		for ( j = 1; j <= k; j++ ) 
			scanf( "%d", &bit[j] );
		
		ini = 1; fin = 1; sol = 0;
		int last = 0;
		while ( fin <= k && ini ) {
			sol += trie[ini][bit[fin]].flag;
            last = trie[ini][bit[fin]].cant - trie[ini][bit[fin]].flag;
			ini = trie[ini][bit[fin]].next;
			fin++;
		}

        if ( k != fin + 1 ) sol += last;
		printf( "%d\n", sol );
	}
	
	fflush( stdout );
	return 0;
}
