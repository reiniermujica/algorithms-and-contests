/*
 Reinier César Mujica
 15/4/08 PSN - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 102,
    MAXL = 1002;
    
struct sem {
    int d, r, g;
};

int N, L, act, tim, D[MAXL], i;
bool mk[MAXN], blocked[MAXL];
sem A[MAXN];

void update () {
     for ( i = 1; i <= N; i++ ) {
        if ( mk[i] ) {
           blocked[A[i].d]=true;
           D[i]++;
           if ( D[i] > A[i].r ) {
            D[i]=1;
            mk[i]=false;
            blocked[A[i].d]=false;    
           }        
        }
        else
        {
         D[i]++;
         blocked[A[i].d]=false;
         if ( D[i] > A[i].g ) {
          D[i]=1;
          mk[i]=true;      
          blocked[A[i].d]=true;
         }       
        }          
    }
}

int main() {   
    scanf( "%d %d", &N, &L );
    for ( i = 1; i <= N; i++ ) {
     scanf( "%d %d %d", &A[i].d, &A[i].r, &A[i].g );
     D[i]=1;
    }
    
    fill( mk, mk + MAXN, true );
    fill( blocked, blocked + MAXL, false );
    
    while ( act != L ) {
      tim++;
      update();
      if ( blocked[act + 1] ) continue;
      act++;
    } 
     
    printf( "%d\n", tim );
    
    fflush( stdout );
    return 0;    
}
