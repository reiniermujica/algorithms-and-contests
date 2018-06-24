#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 1000010
#define LL long long

LL N;
LL low, hi;
LL i, j, k;
LL cant = 0;
LL primes[MAXN];
bool mark[MAXN];

int main()
{
    fill( mark, mark + MAXN, true );
    for ( i = 2; i < MAXN; i++ )
    {
        if ( mark[i] )
        {
             primes[cant++] = i;
             k = i;
             while ( k * i < MAXN )
             {
                  mark[k*i] = false;
                  k++;
             }
        }
    }

    scanf( "%lld", &N );
    while ( N-- )
    {
          scanf( "%lld %lld", &low, &hi );
          
          LL ll = (LL)sqrt( low );
          LL lh = (LL)sqrt( hi );

          LL h = upper_bound( primes, primes + cant, lh ) - primes;

          LL sol = 0;
          for ( i = 0; i < h; i++ )
          {
              LL o = primes[i];
              for  ( k = 2; ; k++ )
              {
                 LL v = pow((double)o,(int)k);
                 if ( v >= low && v <= hi )
                 {
                      sol++;
                 }
                 if ( v >= hi ) break;
              }
          }
          printf( "%lld\n", sol );
    }

    return 0;
}
