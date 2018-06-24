#include <cstdio>
#include <string>

#define REP( i, j, k ) for ( i = j; i <= k; i++ )

using namespace std;

const int
    MAXN = 105,
    MAXL = 35,
    MAXW = 1010;
    
int N, M, i, j, points[MAXW];
int len[MAXW], L[MAXN];
char cad[MAXW][MAXW], S[MAXN][MAXL];

int findp( int x, int word ) {
    int lo, hi = 1;
    REP( lo, 1, len[word] ) {
     if ( cad[word][lo] ==  S[x][hi] ) {
        hi++;
        if ( hi > L[x] ) return 1;
     }
    }
    return 0;
}

int main() {

    freopen( "wordpow.in", "r", stdin );
    freopen( "wordpow.out", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    
    REP( i, 1, N ) {
        gets( cad[i] + 1 );
        len[i] = strlen( cad[i] + 1 );
        REP( j, 1, len[i] )
         cad[i][j] = tolower( cad[i][j] );
    }
    
    REP( i, 1, M ) {
        gets( S[i] + 1 );
        L[i] = strlen( S[i] + 1 );
        REP( j, 1, L[i] )
         S[i][j] = tolower( S[i][j] );
    }
    
    REP( i, 1, N ) {
     REP( j, 1, M )
      if ( findp( j, i ) )
       points[i]++;
    
     printf( "%d\n", points[i] );
    }
     
    fflush( stdout );
    return 0;
}
