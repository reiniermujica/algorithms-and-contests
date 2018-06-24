/*
 Reinier César Mujica
 4/11/2008
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 310;
	
typedef pair < int, int > par;

int N, sol;
int i, j, k;
int val[MAXN][MAXN];
bool mark[MAXN];
priority_queue < par, vector < par >, greater < par > >  Q;

int main() {

	freopen( "water.in", "r", stdin );
	freopen( "water.out", "w", stdout );

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
	 scanf( "%d", &k );
	 Q.push( par( k, i ) );
	}
	for ( i = 1; i <= N; i++ ) 
	 for ( j = 1; j <= N; j++ )
	  scanf( "%d", &val[i][j] );

	while ( !Q.empty() ) {
		int node = Q.top().second;
		int cost = Q.top().first;
        Q.pop();
		
		if ( !mark[node] ) {
			mark[node] = true;
			sol += cost;
			for ( i = 1; i <= N; i++ ) {
               if ( !mark[i] )
   			    Q.push( par( val[node][i], i ) );
			}
		}
	}
	
	printf( "%d\n", sol );
	return 0;
}