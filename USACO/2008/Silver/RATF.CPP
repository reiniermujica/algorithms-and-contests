#include <cstdio>
#include <queue>

using namespace std;

int N, K, sol, act, n1, n2;
queue < int > Q;

int main() {

    freopen( "ratf.in", "r", stdin );
    freopen( "ratf.out", "w", stdout );
    
    scanf( "%d %d", &N, &K );
    
    Q.push( N );
    
    while ( !Q.empty() ) {
        act = Q.front();
        Q.pop();
        int n1 = (act / 2 ) - ( K / 2 );
        int n2 = (act / 2 ) + ( K - ( K / 2 ) );
        if ( n1 + n2 == act && n2 - n1 == K && n1 > 0 && n2 > 0 ) {
            Q.push( n1 );
            Q.push( n2 );
        }
        else
         sol++;
    }
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
