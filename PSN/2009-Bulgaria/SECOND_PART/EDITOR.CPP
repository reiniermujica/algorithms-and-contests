/*
 Reinier César Mujica
 02 - 06 - 2009
 The basic idea is using linked list data structure,
 but is so bored
*/

#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

const int
    MAXN = 100050;
    
int N, M;
int i;
char line[MAXN], act;
list < char > L;
list < char > :: iterator cur;

int main() {
    
    gets( line + 1 );
    N = strlen( line + 1 );
    for ( i = 1; i <= N; i++ )
        L.push_back( line[i] );

    cur = L.end();
    scanf( "%d\n", &M );
    for ( i = 0; i < M; i++ ) {
        scanf( "%c", &act );
        if ( act == 'L' ) {
            if ( cur != L.begin() ) cur--;
        }
        if ( act == 'D' ) {
            if ( cur != L.end() ) cur++;
        }
        if ( act == 'B' ) {
            if ( cur != L.begin() && !L.empty() )
              cur = L.erase( --cur );
        }
        if ( act == 'P' ) {
            scanf( " %c", &act );
            if ( L.empty() ) L.push_back( act );
            else {
                cur = L.insert( cur, act );
                cur++;
            }
        }
        scanf( "\n" );
    }

    /* print */
    for ( cur = L.begin(); cur != L.end(); cur++ )
        printf( "%c", *cur );
    printf( "\n" );

    fflush( stdout );
    return 0;
}
