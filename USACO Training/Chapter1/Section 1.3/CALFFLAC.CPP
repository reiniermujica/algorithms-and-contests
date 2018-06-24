/*
ID: reywork2
PROG: calfflac
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int
    MAXN = 20002;
    
struct pal {
    char val;
    int pos;
};

int N, M, sol, ini, fin, i, j, s1, s2, start, end;
pal L[MAXN];
char T[MAXN], x;

bool isletter( char a ) {
     if ( a >= 'a' && a <= 'z' ) return 1;
     if ( a >= 'A' && a <= 'Z' ) return 1;
     return 0;
}

char upper( char a ) {
     if ( a > 'Z' )
      return a - 32;    
     return a;
}

int main() {
    freopen( "calfflac.in", "r", stdin );
    freopen( "calfflac.out", "w", stdout );

    /* read */
    while ( scanf( "%c", &x ) != EOF ) {
     T[++N]=x;
     if ( isletter ( x ) ) {
      L[++M].val = upper( x );       
      L[M].pos=N;      
     }
    }
    
    /* solve ~O(N*L) */
    for ( i = 1; i <= M; i++ ) {
        int cont = 0;
        ini = i; fin = i;
        while ( L[ini].val == L[fin].val ) {
         cont++;
         ini--; fin++;
         if ( ini == 0 || fin > M ) break;   
        }
        if ( cont > sol ) {
         sol = cont; 
         s1 = i; s2 = i;             
         start = ini + 1;
         end = fin - 1;
        }
        cont = 0;
        ini = i; fin = i + 1;
        while ( L[ini].val == L[fin].val ) {
         cont++;
         ini--; fin++;
         if ( ini == 0 || fin > M ) break;   
        }
        if ( cont > sol ) {
         sol = cont; 
         s1 = i; s2 = i + 1;              
         start = ini + 1;
         end = fin - 1;
        }
    }
    
    /* print solution */
    if ( s1 == s2 ) cout << sol*2 - 1 << endl;
    else cout << sol*2 << endl;
    for ( i = L[start].pos; i <= L[end].pos; i++ )
     cout << T[i];
    cout << endl;
    
    fflush( stdout );
    return 0;    
}
