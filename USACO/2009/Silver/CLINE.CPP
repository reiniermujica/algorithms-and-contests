/*

*/

#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int N, S;
int i, j, k;
deque < int > L;
char ch;

int main() {

    freopen( "cline.in", "r", stdin );
    freopen( "cline.out", "w", stdout );
    
    scanf( "%d\n", &S );
    for ( i = 0; i < S; i++ ) {
        scanf( "%c ", &ch );
        if ( ch == 'A' ) {
            N++;
            scanf( "%c\n", &ch );
            if ( ch == 'L' )
                L.push_front( N );
            else
                L.push_back( N );
        }
        else {
            scanf( "%c %d\n", &ch, &k );
            if ( ch == 'L' )
                for ( j = 0; j < k; j++ )
                    L.pop_front();
            else
                for ( j = 0; j < k; j++ )
                    L.pop_back();    
        }
    }
    
    for ( i = 0; i < L.size(); i++ )
        printf( "%d\n", L[i] );
        
    fflush( stdout );
    return 0;
}
