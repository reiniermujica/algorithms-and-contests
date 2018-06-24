#include <cstdio>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int
    MAXN = 1050;
    
struct city {
    int len, tim;
};

int N, M, sol, hh, mm, cont, s, f, i, j, k1, k2;
char cad[MAXN], start[MAXN], dest[MAXN], c;
map < string, int > MAP;
city T[MAXN];

int main() {

    freopen( "taxi.in", "r", stdin );
    freopen( "taxi.out", "w", stdout );
    
    scanf( "%s\n", &cad );
    while ( cad[0] != '$' ) {
        MAP[(string)cad] = ++cont;
        scanf( "%d %d", &T[cont].len, &T[cont].tim );
        scanf( "%s\n",  &cad );
    }
    
    scanf( "%s %s", &start, &dest );
    scanf( "%d %c %d", &hh, &c, &mm );
    
    s = MAP[(string)start]; f = MAP[(string)dest];
    int act = 0, d1, d2;
    for ( i = s; i <= f; i++ ) {
     
     for ( j = 1; j <= T[i].len; j++ ) {
        int d = T[i].tim;
        k1 += d; k2++;
        int lash = hh, lasm = mm;
        while ( d + mm >= 60 ) {
         hh++;
         if ( hh > 23  ) hh = 0;
         d -= ( 60 - mm );
         mm = 0;
        }
        mm += d;

        d1 = 0;
        if ( hh == 0 && mm > 0 ) //12
         d1 = 20;
        if ( hh == 6 && mm == 0 ) //6
         d1 = 20;
        if ( hh > 0 && hh < 6 )
         d1 = 20;
        if ( lash >= 0 && lash < 6 )
         d1 = 20;
         
        act++;
        if ( act <= 10 )
         sol += (1000) + ( ( 1000 * d1 ) / 100 );
        else
        if ( act <= 30 )
         sol += (250) + ( ( 250 * d1 ) / 100);
        else
        if ( act > 30 )
         sol += (100) + ( ( 100 * d1 ) / 100 );
     }
    }
    
    double cc = ( (double)k1 / 60 );
    cc = (double)k2 / cc;
    if ( cc < 30 )
     sol += (sol * 10) / 100;

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
