/*
 Reinier César Mujica
 11/4/08 PSN - 2008
*/

#include <cstdio>
#include <string>
#include <algorithm>

#define INP "INPUT.TXT"
#define OUT "OUTPUT.TXT"
#define WRD "WORDS.TXT"

using namespace std;

const int
    MAXN = 8,
    MAXP = 40001,
    cost[27] = {0,2,5,4,4,1,6,5,5,1,7,6,3,5,
                2,3,5,7,2,1,2,4,6,6,7,5,7};
    
int M, T[MAXN], i, sol, cont;
string C, D[MAXP], L[MAXN][2];
char cad[MAXN];

int getcost( string a ) {
    int s = 0;
    for ( int c = 0; c < a.size(); c++ )
     s+=cost[a[c] - 96];
    return s;    
}

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

void update( string a, string b ) {
     int k = getcost ( a ) + getcost ( b );
     if ( k > sol ) {
      sol=k; cont=1;
      L[1][0]=a; L[1][1]=b;       
     }
     else
     if ( k == sol ) {
      if ( b != ""  && !exist_p( a, b ) ){  
       cont++;
       L[cont][0]=a; L[cont][1]=b;
      }
      else
      if ( !exist( a ) ) {
       cont++;
       L[cont][0]=a;       
      }
    }
}

void comb( string res, int pos ) {
     res+=C[pos];
     string kres = res;
     if ( res.size() >= 3 )
     while ( next_permutation( res.begin(), res.end() ) ) {
        int q = lower_bound( D, D + M, res ) - D;
        if ( D[q] == res ) update( res, "" );  // one word
        string a = "";
        if ( res.size() >= 3 )
        for ( int c = 0; c < res.size() - 1; c++ ) { // two words
            a+=res[c]; 
            if ( a.size() < 3 ) continue;
            int q = lower_bound( D, D + M, a ) - D;
            if ( D[q] != a ) continue;
            update( a, "" );
            string b = ""; 
            for ( int r = c+1; r < res.size(); r++ ) {
             b+=res[r];     
             if ( b.size() < 3 ) continue;
             int z = lower_bound( D, D + M, b ) - D;
             if ( D[z] != b ) continue;
             update( b, "" );
             update( a, b );
            }
        }
     }
     for ( int x = pos + 1; x < C.size(); x++ )
      comb( kres, x ); 
}

int main() {
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
    sort(C.begin(), C.end() );
    comb( "", 0 ); //combine all sizes 
    printf( "%d\n", sol );
    for ( i = 1; i <= cont; i++ ) {
        if ( L[i][1] != ""  )
         printf( "%s %s\n", L[i][0].c_str(), 
                            L[i][1].c_str() );                         
        else
         printf( "%s\n", L[i][0].c_str() );
    }
    fflush( stdout );
    return 0;
}
