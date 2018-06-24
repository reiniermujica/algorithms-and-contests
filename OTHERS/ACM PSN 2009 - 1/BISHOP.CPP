/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define IO freopen

typedef pair < int, int > par;

int T, N, M;
int i, j, k;
int x1, y1, x2, y2;
int dir1, dir2;
int sol;

int get_dir( int x, int y ) {
    int dir;
    if ( x % 2 && y % 2 )
         dir = 1; //black
    else
    if ( ( x % 2 && !( y % 2 ) ) ||
       ( !( x % 2 ) && y % 2 ) ) //white
        dir = 2;
    else dir = 1; //black
    return dir;   
}

int main() {
    
    IO( "bishop.in", "r", stdin );
    IO( "bishop.out", "w", stdout );
    
    for ( scanf( "%d", &T ); T; T-- ) {
        scanf( "%d", &M );
        scanf( "%d", &N );
        for ( i = 0; i < M; i++ ) {
            scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
            dir1 = get_dir( x1, y1 );
            dir2 = get_dir( x2, y2 );
            if ( par( x1, y1 ) == par( x2, y2 ) ) puts( "0" );
            else
            if ( dir1 != dir2 ) puts( "no move" );
            else {
                if ( abs( x1 - x2 ) == abs( y1 - y2 ) )
                    puts( "1" );
                else puts( "2" );           
            }
        }
    }
    
    fflush( stdout );
    return 0;
}
