/*
 Reinier Mujica Hdez
 25 - 9 - 2008
 IOI 2006 "Writing"
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
    MAXN = 257;
    
int N, M, sol;
int i;
int cant[MAXN], act[MAXN];
char ch;
queue < char > Q;

int main() {

    freopen( "writing.in", "r", stdin );
    freopen( "writing.out", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    for ( i = 1; i <= N; i++ ) {
      scanf( "%c", &ch );
      cant[ch]++;
    }
    scanf( "\n" );
    
    for ( i = 1; i <= M; i++ ) {
        scanf( "%c", &ch );
        if ( !cant[ch] ) {
            while ( !Q.empty() ) {
                act[Q.front()]--;
                Q.pop();
            }
        }
        else {
            act[ch]++;
            while ( act[ch] > cant[ch] && !Q.empty() ) {
                act[Q.front()]--;
                Q.pop();
            }
            Q.push( ch );
            if ( Q.size() == N ) sol++;
        }
    }

    printf( "%d\n", sol );

    fflush( stdout );
    return 0;}

