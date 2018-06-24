/*
 Reinier César Mujica
 3/08/2008
 "Net"
 Bridges ( V + E ) + something
 Con vectores es mas lento ( mucho mas )
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 100002;

int N, M, Ca, Cb, dc_time;
int i, j, k;
int dfsnum[MAXN], low[MAXN];
bool mA[MAXN], mB[MAXN];
vector < pair < int, int > > S;
vector < int > G[MAXN];

int dfs( int x, int father, int &a, int &b ) {
    dfsnum[x] = low[x] = ++dc_time;
    
    int cA = mA[x], cB = mB[x], j, k;
    for ( int i = 0; i < G[x].size(); i++ ) {
        int next = G[x][i];
        if ( next == father ) continue;
        
        if ( !dfsnum[next] ) {
          dfs( next, x, j, k );
          low[x] <?= low[next];
          cA += j; cB += k;
          
          if ( dfsnum[next] == low[next] )
            if ( !j || j == Ca || !k || k == Cb )
             S.push_back( make_pair( x, next ) );
        }
        else
          low[x] <?= low[next];
    }
    a = cA; b = cB;
}

int main() {

    freopen( "net.in", "r", stdin );
    freopen( "net.out", "w", stdout );

    scanf( "%d %d %d %d", &N, &M, &Ca, &Cb );
    FOR( i, 1, Ca ) {
      scanf( "%d", &j );
      mA[j] = true;
    }
    FOR( i, 1, Cb ) {
      scanf( "%d", &j );
      mB[j] = true;
    }

    FOR( i, 0, M - 1 ) {
      scanf( "%d %d", &j, &k );
      G[j].push_back( k );
      G[k].push_back( j );
    }
    
    dfs( 1, -1, j, k );
    
    printf( "%d\n", j = S.size() );
    FOR( i, 0, j - 1 )
     printf( "%d %d\n", S[i].first, S[i].second );

    fflush( stdout );
    return 0;
}
