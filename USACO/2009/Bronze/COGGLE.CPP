/*
 Reinier César Mujica
 4 - 3 - 2009
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int
	MAXN = 30500,
	MAXZ = 30;
	
struct node {
    bool finish;
    node *next[300];
} trie;

	
int N, M, sol;
int i, j, k;
char cad[MAXZ];
char mat[MAXZ][MAXZ];
bool mark[MAXZ][MAXZ];
FILE *fs = fopen( "coggle.out", "w" );

bool ok( string a ) {
     node *start = &trie;
     for ( int i = 0; i < a.size(); i++ ) {
        char c = a[i];
        if ( start->next[c] == NULL ) return false;
        start = start->next[c];
     }
     if ( start->finish ) {
           sol++;
           start->finish = false;
     }
     return true;
}

void dfs( int x, int y, string act ) {

	 act += mat[x][y];
     if ( act.size() > 20 ) return ;
     if ( !ok( act ) ) return ;

     mark[x][y] = true;

     if ( !mark[x - 1][y] )
    	 dfs( x - 1, y, act );
     if ( !mark[x - 1][y + 1] )
    	 dfs( x - 1, y + 1, act );
     if ( !mark[x][y + 1] )
	     dfs( x, y + 1, act );
     if ( !mark[x + 1][y + 1] )
    	 dfs( x + 1, y + 1, act );
     if ( !mark[x + 1][y] )
	     dfs( x + 1, y, act );
     if ( !mark[x + 1][y - 1] )
    	 dfs( x + 1, y - 1, act );
     if ( !mark[x][y - 1] )
	     dfs( x, y - 1, act );
     if ( !mark[x - 1][y - 1] )
    	 dfs(   x - 1, y - 1, act );

	 mark[x][y] = false;
}

int main() {
	
	FILE *fe = fopen( "dict.txt", "r" );
	while ( fscanf( fe, "%s\n", &cad ) != EOF ) {
        k = strlen( cad );
        node *start = &trie;
		for ( i = 0; i < k; i++ ) {
            char act = cad[i];
            if ( start->next[act] == NULL ) {
                start->next[act] = new node();
            }
            start = start->next[act];
        }
        start->finish = true;
    }
	fclose( fe );
    
	fe = fopen( "coggle.in", "r" );
	
	N = 5;
	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= N; j++ )
			fscanf( fe, "%c ", &mat[i][j] );
	}
	
	for ( i = 0; i <= 6; i++ ) { // closing path
        mark[i][0] = true;
        mark[0][i] = true;
        mark[N + 1][i] = true;
        mark[i][N + 1] = true;
    }

	for ( i  = 1; i <= N; i++ ) {
		for ( j = 1; j <= N; j++ ) {
			dfs( i, j, "" );
		}
	}

	fprintf( fs, "%d\n", sol );
	return 0;
}
