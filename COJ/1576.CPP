#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXC 257

using namespace std;

int Q;
int N;
long long sol;
int i, j, k;
int cant[MAXC];
bool mark[MAXC];
int fct[32];
char cad[MAXC];

void split( int n, int act )
{
    int f = 2;
    while ( n > 1 )
    {
        while ( n % f != 0 ) f++;
        fct[f] += act;
        n /= f;    
    }
}

long long factorize( int l )
{
    fill( fct, fct + 32, 0 );
    
    /* numerator */
    for ( int i = 1; i <= l; i++ )
        split( i, 1 );
     
    /* denominator */
    for ( int i = 'A'; i <= 'Z'; i++ )
    {
        if ( cant[i] > 1 )
        {
            for ( int j = 2; j <= cant[i]; j++ )
                split( j, -1 );        
        }    
    }
    
    /* compute val */
    long long res = 1;
    for ( int i = 2; i < 32; i++ )
    {
        for ( int j = 1; j <= fct[i]; j++ )
        {
            res *= i;        
        }    
    }
    
    return res;
}

int main()
{
    scanf( "%d\n", &Q );
    while ( Q-- )
    {
        gets( cad + 1 );
        N = strlen( cad + 1 );
        
        fill( mark, mark + MAXC, false );
        fill( cant, cant + MAXC, 0 );
        sol = 0;
        
        for ( i = 1; i <= N; i++ )
            cant[cad[i]]++;
        
        for ( i = 1; i <= N; i++ )
        {
            for ( j = 'A'; j < cad[i]; j++ )
            {
                if ( cant[j] > 0 )
                {
                    cant[j]--;
                    sol += factorize( N - i );
                    cant[j]++;
                }
            }            
            cant[cad[i]]--;
        }
        
        printf( "%lld\n", sol );        
    }

    return 0;
}
