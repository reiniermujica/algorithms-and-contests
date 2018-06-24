#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100010;
    
struct inte {
    int ini, fin;
};

int N, M, T[MAXN], i, best, sol, cont, start;
inte A[MAXN];
bool iszero = false;

int main() {

    freopen( "sequence.in", "r", stdin );
    freopen( "sequence.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    
    for ( i = 1; i <= M; i++ ) {
     scanf( "%d", &T[i] );
     if ( T[i] == 0 ) iszero = true;
    }

    sort( T + 1, T + M + 1 );
    
    if ( iszero ) { // if 0

     best = 1; T[1] = -5; start = 1;
     for ( i = 2; i <= M; i++ ) {
      if ( T[i] != (T[i-1] + 1) ) {
       A[++cont].fin = i - 1;
       A[cont].ini = start;
       start = i;
       sol >?= best;
       best = 1;
      } else best++;
     }
     A[++cont].ini = start;
     A[cont].fin = M;
     sol >?= best;
     if ( sol != N ) sol++;
     for ( i = 2; i < cont; i++ ) {
      if ( T[A[i].fin] == (T[A[i+1].ini] - 2) )
        sol >?= A[i+1].fin - A[i].ini + 2;
     }

    }
    else
    {
     best = 1;
     for ( i = 2; i <= M; i++ ) {
        if ( T[i] == T[i-1] + 1 )
         best++;
        else
        {
         sol >?= best;
         best = 1;
        }
     }
     sol >?= best;
    }
    
    printf( "%d\n", sol );

    fflush( stdout );
    return 0;
}
