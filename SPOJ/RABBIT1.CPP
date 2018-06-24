/*
 Reinier César Mujica
 09/07/2008
 "Counting Rabbits"
 Made by my friend Abel Nieto
 Fibonacci en log(N)
*/

#include <iostream>

using namespace std;

typedef long long int64;

int64 N, M, T;
int64 a, b, c, d, k;

int main() {

    cin >> T;
    
    while ( T-- ) {
     cin >> N >> M;
     a = c = 1; b = d = 0;
     M = 1 << M;
     while ( N ) {
       if ( N % 2 ) {
        k = c * a;
        c = (k + c*b + d*a) % M;
        d = (k + d*b) % M;
       }
       k = a * a;
       a = (k + 2*a*b) % M;
       b = (k + b*b) % M;
       N /= 2;
     }
     
     cout << c << endl;
    }

    fflush( stdout );
    return 0;
}
