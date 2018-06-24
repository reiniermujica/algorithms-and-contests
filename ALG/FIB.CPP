/*
 Reinier César Mujica
 09/07/2008
 "Fibonacci en log(N)"
*/

#include <iostream>

using namespace std;

int N, M, k;
int a, b, c, d;

int main() {

    while ( cin >> N  ) {
     a = c = 1; b = d = 0;
     
     while ( N ) {
       if ( N % 2 ) {
        k = c * a;
        c = k + c*b + d*a;
        d = k + d*b;
       }
       k = a * a;
       a = k + 2*a*b;
       b = k + b*b;
       N /= 2;
     }
     
     cout << c << endl;
    }

    fflush( stdout );
    return 0;
}
