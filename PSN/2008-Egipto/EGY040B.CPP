/*
 Esta  da menos con un jd
*/

#include <cstdio>
#include <string>
#include <algorithm>

#define INP "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#define WRD "WORDS.TXT"

using namespace std;

const int
    MAXN = 9,
    MAXP = 40001,
    cost[27] = {0,2,5,4,4,1,6,5,5,1,7,6,3,5,
                2,3,5,7,2,1,2,4,6,6,7,5,7};
    
int getcost( string a ) {
    int s = 0;
    for ( int c = 0; c < a.size(); c++ )
     s+=cost[a[c] - 96];
    return s;    
}

int N, M, T[MAXN], i, j, k, sol, cont, list[MAXP][2];
string C, D[MAXP], L[MAXN][2];
char cad[MAXN];

bool exist(string a) {
     for ( int c = 1; c <= cont; c++ )
      if ( L[c][0] == a || L[c][1] == a ) return 1;       
     return 0;       
}

bool exist_p(string a, string b) {
     for ( int c = 1; c <= cont; c++ )
      if ( (L[c][0] == a && L[c][1] == b) ||
           (L[c][0] == b && L[c][1] == a) ) return 1;       
     return 0;       
}

int main() {
    for ( i = 0; i < MAXP; i++ ) {
     list[i][0] = -1; list[i][1] = -1;
    }
    freopen( INP, "r", stdin );
    scanf( "%s", &cad );
    C=cad;
    fflush( stdin );
    freopen( WRD, "r", stdin );
    scanf( "%s", &cad );
    while ( cad[0] != '.' ) {
       D[M++]=cad;
       scanf( "%s", &cad );
    }
    freopen( OUT, "w", stdout );
    sort( C.begin(), C.end() );
    while ( next_permutation( C.begin(), C.end() ) ) {
        i = lower_bound( D, D + M, C ) - D;        
        if ( D[i] == C ) {
           k = getcost( D[i] );
           if ( k > sol ) {
             sol=k; cont=1;
             L[1][0]=C;
           }
           else
           if ( k == sol && !exist( C ) )
             L[++cont][0]=C;   
        }
        else
        {
         string a = "";
         for ( j = 0; j < C.size() - 1; j++ ) {
            a+=C[j]; string b = "";
            for ( k = j + 1; k < C.size(); k++ ) b+=C[k];
            int d1 = lower_bound( D, D + M, a ) - D;
            int d2 = lower_bound( D, D + M, b ) - D;
            if ( D[d1] == a && D[d2] == b ) {
                int c = getcost(a) + getcost(b);
                if ( c > sol ) {
                 sol=c; cont=1;
                 L[1][0]=a;
                 L[1][1]=b;   
                }
                else
                if ( c == sol ) {
                 if (!exist_p( a, b )){
                  L[++cont][0]=a;
                  L[cont][1]=b;       
                 }
                }
            }
            else
            if ( D[d1] == a ) {
              int c = getcost( a );
              if ( c > sol ) {
               sol=c; cont=1;
               L[cont][0]=a;      
              }
              else
              if ( c == sol && !exist( a )) 
               L[++cont][0]=a;      
            }
            else
            if ( D[d2] == b ) {
              int c = getcost( b );
              if ( c > sol ) {
               sol=c; cont=1;
               L[1][0]=b;      
              }
              else
              if ( c == sol && !exist( b ) )
               L[++cont][0]=b;      
            }   
         }  
        }
    }
    printf( "%d\n", sol );
    for ( i = 1; i <= cont; i++ ) {
        if ( L[i][1] != ""  ) {
         printf( "%s %s\n", L[i][0].c_str(), 
                            L[i][1].c_str() );                         
        }
        else
         printf( "%s\n", L[i][0].c_str() );
    }
    fflush( stdout );
    return 0;
}
