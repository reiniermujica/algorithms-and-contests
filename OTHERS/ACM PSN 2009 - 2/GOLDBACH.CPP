/*
 Reinier César Mujica
 25 - 06 - 2009
 Sieve of Erastotenes
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 1000005;
    
int N;
int i, j, k;
bool mark[MAXN + 20], found;
vector < int > primes;

int main() {

    /* sieve */
    mark[1] = true;
    for ( i = 3; i < MAXN; i += 2 ) {
        if ( !mark[i] ) {
            primes.push_back( i );
            for ( j = 2; j * i < MAXN; j++ )
                mark[i * j] = true;
        }
    }
    
    scanf( "%d", &N );
    while ( N != 0 ) {
        for ( i = found = 0; i < primes.size() && N >= primes[i]; i++ ) {
            j = primes[i];
            k = N - primes[i];
            if ( !mark[j] && !mark[k] && k % 2 && j != k ) {
                printf( "%d = %d + %d\n", N, j, k );
                found = true;
                break;
            }
        }
        
        if ( !found ) 
            printf( "Goldbach's conjecture is wrong.\n" );
    
        scanf( "%d", &N );
    }

    fflush( stdout );
    return 0;
}
