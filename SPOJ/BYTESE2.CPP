/*
 Reinier César Mujica
 25 - 4 - 2009
 Sweep Line Easy
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;
   
int Q, N, sol;
int i, j, k;

int main() {
    
    for ( scanf( "%d", &Q ); Q; Q-- ) { 
        vector < par > ls;
       
        scanf( "%d", &N );
        for ( i = 1; i <= N; i++ ) {
            scanf( "%d %d", &j, &k );
            ls.push_back( par( j, 1 ) );
            ls.push_back( par( k, -1 ) );
        }
        
        k = sol = 0;
        sort( ls.begin(), ls.end() );
        for ( i = 0; i < ls.size(); i++ ) {
            k += ls[i].second;
            sol >?= k;
        }
        
        printf( "%d\n", sol );
    }
    
    fflush( stdout );
    return 0;
}
