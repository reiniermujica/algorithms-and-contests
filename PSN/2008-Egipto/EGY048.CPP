/*
 Reinier César Mujica
 10/4/08 PSN - 2008
*/

#include <cstdio>

const int
    MAXR = 10001,
    MAXC = 76;
    
int N, M, sol, Kr[MAXR], Kc[MAXC];
char C[MAXR][MAXC];

bool equal_r( int x, int y ) {
     int i;
     for ( i = 1; i <= M; i++ )
      if ( C[x][i] != C[y][i] )
       return false;
     return true;
}

bool equal_c( int x, int y ) {
     int i;
     for ( i = 1; i <= N; i++ )
      if ( C[i][x] != C[i][y] )
       return false;
     return true;
}


int main() {
    int i, k;
    freopen( "mgrid.in", "r", stdin );
    freopen( "mgrid.out", "w", stdout );
    scanf( "%d %d\n", &N, &M );
    for ( i = 1; i <= N; i++ )
     gets( C[i] + 1 );

    /* PreKmp for rows */
    k = 0;
    for ( i = 2; i <= N; i++ ) {
        while ( k > 0 && !equal_r( i, k + 1 ) )
         k = Kr[k];
        if ( equal_r( i, k + 1 ) ) k++;
        Kr[i]=k;
    }

    /* PreKmp for columns */
    k = 0;
    for ( i = 2; i <= M; i++ ) {
        while ( k > 0 && !equal_c( i, k + 1 ) )
         k = Kc[k];
        if ( equal_c( i, k + 1 ) ) k++;
        Kc[i]=k;
    }
    
    sol = (N - Kr[N]) * (M - Kc[M]);
    printf("%d\n", sol );

    fflush( stdout );
    return 0;
}
