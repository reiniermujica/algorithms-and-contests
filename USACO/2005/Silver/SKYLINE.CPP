/*
 Reinier César Mujica
 2/10/2008
 "Perfil de Ciudad"
*/

#include <cstdio>
#include <stack>

using namespace std;

int N, W, sol;
int i, x, y;

stack < int > S;

int main() {

	freopen( "skyline.in", "r", stdin );
	freopen( "skyline.out", "w", stdout );
	
	scanf( "%d %d", &N, &W );
    S.push( 0 );
	for ( i = 0; i <= N; i++ ) {
  	   scanf( "%d %d", &x, &y );
       y = ( i == N ) ? 0 : y;
       while ( y < S.top() ) {
            sol++;
            S.pop();
       }
       if ( y > S.top() )
         S.push( y );
    }
    
	printf( "%d\n", sol );
	return 0;
}
