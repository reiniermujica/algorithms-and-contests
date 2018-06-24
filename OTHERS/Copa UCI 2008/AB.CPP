/*
 Reinier Cesar Mujica
 2/06/08
 "Sequencia AB"
 Copa UCI 2008 1ra Edicion
*/

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int
	MAXN = 30002;

int N, M, i, j;
int cont[2];
char C[MAXN];
vector < int > V;

int do_work( int start, int end ) {
    if ( start > end) {
        V.push_back( 4 );
        return 0;
    }
    
    if ( C[start] != C[end] ) {
        if ( C[start] == 'a' )
         V.push_back( 1 );
        else
         V.push_back( 2 );
        do_work( start + 1, end - 1 );
    }
    else {
      cont[0] = 0; cont[1] = 0; int k = start + 1;
      cont[C[start] - 'a']++;
      V.push_back( 3 );
      
      while ( cont[0] != cont[1] ) {
        cont[C[k] - 'a']++;
        k++;
      }
      do_work( start, k - 1 );
      do_work( k, end );
    }
}

int main() {

    scanf( "%d\n", &M );

    while ( M-- ) {

      gets( C + 1 );
      N = strlen( C + 1 );
      for ( i = 1; i <= N; i++ )
       cont[C[i] - 'a']++;

      if ( cont[0] != cont[1] )
        printf( "%d\n", 0 );

      else {
       do_work( 1, N );
       printf( "1 %d\n", V.size() );
       for ( i = 0; i < V.size(); i++ )
        printf( "%d\n", V[i] );
      }
    }

    fflush( stdout );
    return 0;
}
