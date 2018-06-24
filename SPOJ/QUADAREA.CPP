/*
 Reinier César Mujica
 25 - 06 - 2009
 Heron Formule for Cuadrilateral
*/

#include <cstdio>
#include <cmath>

using namespace std;

int T;
double a, b, c, d;
double sol, p;

int main() {
    
    for ( scanf( "%d", &T ); T; T-- ) {
        scanf( "%lf %lf %lf %lf", &a, &b, &c, &d );
        p = ( a + b + c + d ) / 2;
        sol = sqrt( ( p - a ) * ( p - b ) * ( p - c ) * ( p - d ) );
        printf( "%.2lf\n", sol );
    }
    
    fflush( stdout );
    return 0;
}
