#include <iostream>

using namespace std;

#define MAXN 8005

int Q, N;
int cant = 0;
int i, j, k = 0;
int dp[MAXN];

int pow( int x, int a )
{
    int res = 1;
    for ( int i = 1; i <= a; i++ )
        res *= x;
    return res;
}

int main()
{
    while ( cant < 8000 )
    {
        k++;
        dp[++cant] = pow( 5, k );
        
        int temp = cant - 1;
        for ( i = 1; i <= temp; i++ )
        {
            dp[++cant] = dp[i] + dp[temp + 1];                
            if ( cant >= 8000 ) break;
        }        
    }
    
    cin >> Q;
    while ( Q-- )
    {
        cin >> N;
        cout << dp[N] << endl;    
    }

    return 0;
}
