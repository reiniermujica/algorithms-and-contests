#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define MOD 1005

int a, c, M, q, N, f;
int i, j, k;
int L[MOD + 2];
string cad;

int main()
{
	scanf( "%d %d %d %d %d", &a, &c, &M, &f, &q );
	scanf( "%d", &N );
	cin >> cad;
	L[f]++;
	for ( i = 1; i < N; i++ )
	{
		k = ( (a * f) + c ) % M;
		L[k]++;
		f = k;
	}

	for ( i = 0; i < q; i++ )
	{
		scanf( "%d", &k );

		int cant = 0;
		if ( cad == "DESC" )
		{
			for ( j = M; j >= 0; j-- )
			{
				cant += L[j];
				if ( cant >= k )
				{
					printf("%d\n", j );
					break;
				}
			}
		}
		if ( cad == "ASC" )
		{
			for ( j = 0; j <= M; j++ )
			{
				cant += L[j];
				if ( cant >= k )
				{
					printf("%d\n", j );
					break;
				}
			}
		}
	}

	return 0;
}
