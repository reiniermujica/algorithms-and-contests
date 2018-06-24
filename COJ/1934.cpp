#include <cstdio>
#include <cmath>

using namespace std;

long long S, D, s;
long long low, hi, mid;

int main()
{
    while ( scanf( "%lld %lld", &S, &D ) != EOF )
    {
          S--;
          s = ( S * ( S + 1 ) ) / 2;
          s--;
          s += D;
          s *= 2;

          low = (long long)sqrt( s );
          
          while ( ( low * ( low + 1 ) ) <= s ) low++;
          
          printf( "%lld\n", low );
    }

    return 0;
}
