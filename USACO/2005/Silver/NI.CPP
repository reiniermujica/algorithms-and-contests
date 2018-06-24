/*
 Reinier César Mujica
 14/7/08 PSN - 2008
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
    MAXN = 1002,
    oo = 1 << 29,
    mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
    
    
int N, M, T[MAXN][MAXN], B[MAXN][MAXN], Ni[MAXN][MAXN];
int S[2], F[2], sol;
queue < pair < int, int > > Q;

int main() {
    int i, j, k, x, y, cx, cy;
    freopen( "ni.in", "r", stdin );
    freopen( "ni.out", "w", stdout );
    scanf( "%d %d", &M, &N );
    for ( i = 1; i <= N; i++ )
     for ( j = 1; j <= M; j++ ) {
       scanf( "%d", &T[i][j] );
       if ( T[i][j] == 2 ) {
          S[0] = i; S[1] = j;  
       }
       if ( T[i][j] == 3 ) {
          F[0] = i; F[1] = j;     
       }
     }
    for ( i = 0; i <= N; i++ ) {
     fill( B[i], B[i] + MAXN, oo );
     fill( Ni[i], Ni[i] + MAXN, oo );
    }
    
    /* Betsy BFS */
    B[S[0]][S[1]]=0;
    Q.push( make_pair( S[0], S[1] ) );
    while ( !Q.empty() ) {
     int x = Q.front().first;
     int y = Q.front().second;
     Q.pop();   
     for ( i = 0; i < 4; i++ ) {
        int cx = x + mov[i][0];
        int cy = y + mov[i][1];       
        if ( cx > 0 && cx <= N && cy > 0 && cy <= M 
             && T[cx][cy] != 1 ) {
         if ( B[cx][cy] > B[x][y] + 1 ) {
            B[cx][cy] = B[x][y] + 1;
            Q.push( make_pair( cx, cy ) );       
         }           
        }  
     }    
    }
    
    /* Ni-knight BFS */
    Ni[F[0]][F[1]]=0;
    Q.push( make_pair( F[0], F[1] ) );
    while ( !Q.empty() ) {
     int x = Q.front().first;
     int y = Q.front().second;
     Q.pop();   
     for ( i = 0; i < 4; i++ ) {
        int cx = x + mov[i][0];
        int cy = y + mov[i][1];       
        if ( cx > 0 && cx <= N && cy > 0 && cy <= M 
             && T[cx][cy] != 1 ) {
         if ( Ni[cx][cy] > Ni[x][y] + 1 ) {
            Ni[cx][cy] = Ni[x][y] + 1;
            Q.push( make_pair( cx, cy ) );       
         }           
        }  
     }    
    }
    
    sol = oo;
    for ( i = 1; i <= N; i++ )
     for ( j = 1; j <= M; j++ )
      if ( T[i][j] == 4 )
       if ( Ni[i][j] != oo && B[i][j] != oo )
        sol <?= Ni[i][j] + B[i][j]; 

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
