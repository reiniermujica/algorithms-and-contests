/*
 ID: reywork2
 PROG: clocks
 LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 10,
    MAXM = 10000;
    
int sol[MAXM], best[MAXM];
int T[MAXN], tmp[MAXN];
int cant[MAXN];
int i, j, k;

struct state {
    int cant;
    int cl[MAXN];

    state( int cc = 0, int a = 0, int b = 0, int c = 0, int d = 0,
           int e = 0 ) {
        cant = cc;
        cl[1] = a; cl[2] = b; cl[3] = c; cl[4] = d;
        cl[5] = e;
    }
    
} mov[MAXN];

void apply( int k ) {
     for ( int i = 1; i <= mov[k].cant; i++ ) {
        int j = mov[k].cl[i];
        tmp[j] = ( tmp[j] + 3 );
        if ( tmp[j] > 12 ) tmp[j] %= 12;
     }
}

void update() {
     for ( int i = 1; i <= 9; i++ )
      if ( tmp[i] != 12 ) return ;

     if ( k > best[0] ) return ;
     if ( k < best[0] ) {
         best[0] = k;
         for ( int i = 1; i <= k; i++ )
          best[i] = sol[i];
     }
     else {
        bool ok = false;
        for ( int i = 1; i <= k; i++ )
            if ( sol[i] < best[i] ) {
                ok = true;
                break;
            }
        if ( ok ) {
         for ( int i = 1; i <= k; i++ )
          best[i] = sol[i];
        }
     }
}

void dfs( int x ) {
     int c[MAXN];
     memcpy( c, tmp, sizeof tmp );
     if ( cant[x] >= 3 ) return ;
     cant[x]++;
     apply( x );
     sol[++k] = x;
     update();
     for ( int i = x; i <= 9; i++ )
      dfs( i );
     cant[x]--;
     k--;
     memcpy( tmp, c, sizeof c );
}

int main() {

    freopen( "clocks.in", "r", stdin );
    freopen( "clocks.out", "w", stdout );

    /* init moves */
    mov[1] = state( 4, 1, 2, 4, 5 );
    mov[2] = state( 3, 1, 2, 3 );
    mov[3] = state( 4, 2, 3, 5, 6 );
    mov[4] = state( 3, 1, 4, 7 );
    mov[5] = state( 5, 2, 4, 5, 6, 8 );
    mov[6] = state( 3, 3, 6, 9 );
    mov[7] = state( 4, 4, 5, 7, 8 );
    mov[8] = state( 3, 7, 8, 9 );
    mov[9] = state( 4, 5, 6, 8, 9 );
    
    for ( i = 1; i <= 9; i++ )
     scanf( "%d", &T[i] );

    fill( best, best + MAXM, 1000 );
    
    for ( i = 1; i <= 9; i++ ) {
        memset( cant, sizeof cant, 0 );
        memcpy( tmp, T, sizeof T );
        dfs( i );
    }

    for ( i = 1; i < best[0]; i++ )
     printf( "%d ", best[i] );
     
    printf( "%d\n", best[best[0]] );

    fflush( stdout );
    return 0;
}
