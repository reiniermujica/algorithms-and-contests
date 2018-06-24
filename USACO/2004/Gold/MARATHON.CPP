/*
 Reinier César Mujica
 2 - 12 - 2008
*/

#include <cstdio>
#include <vector>

using namespace std;

typedef pair < int, int > par;

const int
    MAXN = 40050;
    
int N, E, sol;
int i, j, k, c;
char ch;
int D[MAXN];
bool mk[MAXN];
vector < par > G[MAXN];

void dfs( int x, int cost ) {
     D[x] = cost; mk[x] = true;
     for ( int i = 0; i < G[x].size(); i++ ) {
        int next = G[x][i].first;
        int coss = G[x][i].second;
        if ( mk[next] ) continue;
        dfs( next, D[x] + coss );
     }
}

int main() {

    freopen( "MARATHON.IN", "r", stdin );
    freopen( "MARATHON.OUT", "w", stdout );
    
    scanf( "%d %d", &N, &E );
    for ( i = 1; i <= E; i++ ) {
        scanf( "%d %d %d %c", &j, &k, &c, &ch );
        G[j].push_back( par( k, c ) );
        G[k].push_back( par( j, c ) );
    }
    
    dfs( 1, 0 );
    for ( i = 1; i <= N; i++ ) {
     if ( D[i] > sol ) {
        sol = D[i];
        k = i;
     }
     D[i] = mk[i] = 0;
    }
     
    dfs( k, 0 ); sol = 0;
    for ( i = 1; i <= N; i++ )
     sol >?= D[i];

    printf( "%d\n", sol );
    return 0;
}
