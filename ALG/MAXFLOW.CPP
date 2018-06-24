/*
 Reinier César Mujica
 30/07/2008
 update xx/08/2008
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
    MAXN = 302,
    oo = 1 << 29;

int N, E, sol;
int src, snk;
int i, j, k;
int cap[MAXN][MAXN], fl[MAXN][MAXN];
int flow[MAXN], from[MAXN];

bool augment( int source, int sink ) {
     fill( from, from + MAXN, -1 );
     fill( flow, flow + MAXN, 0 );
     flow[1] = oo;

     queue < int > Q;
     for ( Q.push( source ); !Q.empty(); Q.pop() ) {
        j = Q.front();
        
		for ( i = 1; i <= N; i++ ) {
            if ( from[i] < 0 && fl[j][i] < cap[j][i] ) {
                flow[i] = min( flow[j], cap[j][i] - fl[j][i] );
                from[i] = j;
                Q.push( i );
            }
		}
     }
     
     if ( from[sink] < 0 ) return false;
     sol += flow[sink];
	 
	 for ( i = sink; i != source; i = from[i] ) {
		fl[from[i]][i] += flow[sink];
		fl[i][from[i]] -= flow[sink];
     }
     return true;
}

int main() {

    freopen( "flow.in", "r", stdin );
    freopen( "flow.out", "w", stdout );

    scanf( "%d %d", &N, &E );
	scanf( "%d %d", &src, &snk );
    for ( i = 0; i < E; i++ ) {
      scanf( "%d %d %d", &j, &k, &sol );
      cap[j][k] = sol;
    }

    sol = 0;
    while ( augment( src, snk ) );
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
