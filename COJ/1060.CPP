#include <iostream>

using namespace std;

const int
    MAXD = 10;
    
int sol, N;
bool D[MAXD];

bool isok( int k, int d ) {
     if ( k == 0 ) return 0;
     while ( k > 0 ){
       if ( !D[k % 10] ) return 0;
       k /= 10;
       d--;
     }
     if ( d == 0 ) return 1;
     return 0;
}

bool mult( int x, int y ) {
     int d1 = x * (y / 10);
     if ( !isok( d1,3 ) ) return 0;
     int d2 = x * (y % 10);
     if ( !isok( d2,3 ) ) return 0; 
     if ( !isok( d1*10+d2, 4 ) ) return 0;
     return true;
}

int main() {
    int i, j;
    
    while ( cin >> N )
    {
        sol = 0;
        memset(D, false, sizeof D );
        
        for ( i=0; i<N; i++ ) 
        {
            cin >> j;
            D[j]=true;
        }
        for ( i=100; i<1000; i++ )
            for ( j=10; j<100; j++ )
                if ( isok(i,3) && isok(j,2) && mult(i,j) )
            sol++;
        
        cout << sol << endl;
    }
    
    return 0;
}
