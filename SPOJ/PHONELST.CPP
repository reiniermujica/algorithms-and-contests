/*
 Reinier César Mujica
 23 - 3 - 2009 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
    MAXN = 10050;
    
int T, N;
int i, k;
int len[MAXN], idx[MAXN];
char cad[MAXN][20];
bool sol;

int str_cmp( int a, int b ) {
    int l1 = len[a];
    int l2 = len[b];
    int l3 = l1 <? l2;
    for ( int i = 0; i < l3; i++ ) {
        char ca = cad[a][i];
        char cb = cad[b][i];
        if ( ca < cb ) return 1;
        if ( ca > cb ) return -1;
    }
    return 0;
}

bool cmp( const int &a, const int &b ) {
     int kk = str_cmp( a, b );
     if ( kk == 0 ) return len[a] < len[b];
     else return ( kk > 0 ) ? true : false;
}

int main() {
    
    for ( scanf( "%d", &T ); T; T-- ) {
        scanf( "%d\n", &N );
        for ( i = 1; i <= N; i++ ) {
            gets( cad[i] );
            len[i] = strlen( cad[i] );
            idx[i] = i;
        }

        sort( idx + 1, idx + N + 1, cmp );
        for ( sol = 0, i = 1; i < N; i++ ) {
            if ( str_cmp( idx[i], idx[i + 1] ) == 0 ) {
                sol = true;
                break;
            }
            if ( str_cmp( idx[i + 1], idx[i] ) == 0 ) {
                sol = true;
                break;
            }
        }
        
        if ( sol ) printf( "NO\n" );
        else printf( "YES\n" );
    }
    
    fflush( stdout );
    return 0;
}
