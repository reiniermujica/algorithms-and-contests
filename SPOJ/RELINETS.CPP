/*
 Reinier César Mujica
 6/5/08
 SPOJ #1707 Reliable Nets
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 16,
    MAXM = 21,
    oo = 1 << 29;
    
struct edge {
    int a, b, c;
};

int N, M, i, j, k, cost, ncos, sol, cases;
edge T[MAXM], L[MAXM];
bool mk[MAXN], ok;

int dfs( int v ) {
    mk[v] = true;
    for ( int i = 0; i < M; i++ )
     if ( L[i].a == v && !mk[L[i].b] )
      dfs( L[i].b );
     else
     if ( L[i].b == v && !mk[L[i].a] )
      dfs( L[i].a );
}

int main() {

    scanf( "%d %d", &N, &M );
    
    while ( N && M ) {
     sol = oo; cost = 0;
     cases++;

     for ( i = 0; i < M; i++ ) {
        scanf( "%d %d %d", &T[i].a, &T[i].b, &T[i].c );
        cost += T[i].c;
     }

     for ( i = 0; i < ( 1 << M ) - 1; i++ ) {
       ncos = cost;
       
       for ( j = 0; j < M; j++ ) {
        L[j].a = T[j].a;
        L[j].b = T[j].b;
        if ( (i & ( 1 << j )) ) {
            ncos -= T[j].c;
            L[j].a = 0; L[j].b = 0;
        }
       }

       ok = true;

       if ( ncos >= sol ) continue;
       for ( j = 0; j < M; j++ ) {
        if ( !L[j].a ) continue;
        fill( mk, mk + MAXN, false );
        
        L[j].a = 0; L[j].b = 0;

        dfs( 1 );
        
        for ( k = 1; k <= N; k++ )
         if ( !mk[k] ) {
           ok = false;
           break;
        }

        if ( !ok ) break;

        L[j].a = T[j].a;
        L[j].b = T[j].b;
       }
       
       if ( ok ) sol <?= ncos;
     }
     
     if ( sol == oo )
      printf("There is no reliable net possible for test case %d.\n", cases );
     else
      printf( "The minimal cost for test case %d is %d.\n", cases, sol );
     
     N = 0; M = 0;
     scanf( "%d %d", &N, &M );
    }

    fflush( stdout );
    return 0;
}
