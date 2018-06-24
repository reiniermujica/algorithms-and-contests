/*
 Reinier César Mujica
 4 - 1 - 2009
 Two test fail by stack memory...
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
	MAXN = 21,
	MAXM = 1001;

int N, M, best = 1 << 30;
int i, k;
int C[MAXN];
int T[MAXN][MAXM];
int mark[MAXM];
char ch;
vector < int > sol, temp;

void dfs( int pos, int cant, int died ) {
     int i, j, k;
     if ( cant >= best ) return ; // not way
     if ( died == M ) {
        sol = temp;
        best = cant;
        return ;
     }
     if ( pos > N ) return ;
     
     dfs( pos + 1, cant, died ); // not taken this sat
     if ( cant >= best ) return ;

     k = 0;
     for ( i = 1; i <= C[pos]; i++ ) {
        int next = T[pos][i];
        if ( mark[next] == 0 ) k++;
     }
     if ( !k ) return ;

     for ( i = 1; i <= C[pos]; i++ ) {
        int next = T[pos][i];
        mark[next]++;
     }

     temp.push_back( pos );
     dfs( pos + 1, cant + 1, died + k ); //taken this sat
     temp.pop_back();
     
     for ( i = 1; i <= C[pos]; i++ ) {
         int next = T[pos][i];
         mark[next]--;
     }
     return ;
}

int main() {

	freopen( "SAT.in", "r", stdin );
	freopen( "SAT.out", "w", stdout );
	
	scanf( "%d %d\n", &N, &M );
	for ( i = 1; i <= N; i++ ) {
        while ( true ) {
            scanf( "%d", &k );
            T[i][++C[i]] = k;
            scanf( "%c", &ch );
            if ( ch == '\n' ) break;
        }
	}
	
	fill( mark, mark + MAXM, 0 );
	dfs( 1, 0, 0 );
    
	printf( "%d\n", sol.size() );
	for ( i = 0; i < sol.size(); i++ )
        printf( "%d\n", sol[i] );

	fflush( stdout );
	return 0;
}
