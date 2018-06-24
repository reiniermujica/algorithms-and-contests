/*
 Reinier César Mujica
 15/4/08 PSN - 2008
*/

#include <iostream>

using namespace std;

const int
    MAXN = 105;
    
int C[5], D[MAXN], sol, i, j, x, y;

int main() {
    cin >> C[1] >> C[2] >> C[3];
    for ( i = 1; i <= 3; i++ ) {
     cin >> x >> y;
     for ( j = x; j < y; j++ ) D[j]++;          
    }
    for ( i = 1; i < MAXN; i++ ) {
     sol+= (C[D[i]] * D[i]);  
    }
    cout << sol << endl;
    
    fflush( stdout );    
    return 0;   
}
