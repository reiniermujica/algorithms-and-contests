/*
 Reinier César Mujica
 1 - 1 - 2009
 Trie whit dynamic memory
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int
    MAXN = 20010,
	MAXL = 110;

struct node {
	int id;
	node *next[256];
} trie;

int N, M;
int sol, s1, s2;
int i, j, k;
char line[MAXN][MAXL];
char c;

int main() {

    freopen( "prefix.in", "r", stdin );
    freopen( "prefix.out", "w", stdout );
	
	scanf( "%d\n", &N );
	for ( i = 1; i <= N; i++ ) {
		gets( line[i] );
        M = strlen( line[i] ); k = 0;

   		node *act = &trie;
		for ( j = 0; j < M; j++ ) {
			c = line[i][j];
			if ( act->next[c] == NULL ) {
				act->next[c] = new node();
				act = act->next[c];
    			act->id = i;
			}
			else {
				k++;
				act = act->next[c];
				if ( k > sol ) {
					sol = k;
					s1 = act->id; s2 = i;
				}
            }
		}
	}
	
	printf( "%s\n%s\n", line[s1], line[s2] );
    return 0;
}
