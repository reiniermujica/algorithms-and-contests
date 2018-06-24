//============================================================================
// Name        : 1002.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int N, T, sol;
int dp[20][20];
char line[20][20];
int i, j, k;

int min_three(int a, int b, int c)
{
	return min(min(a,b),c);
}

int main()
{
	scanf("%d\n", &T);

	while (T--)
	{
		scanf("%d\n", &N);

		sol = 0;
		for (i = 0; i <= N; i++)
		{
			for (j = 0; j <= N; j++)
			{
				line[i][j] = '#';
			}
		}

		for (i = 0; i < N; i++)
		{
			gets(line[i+1] + 1);
		}

		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (line[i][j] == '#')
				{
					dp[i][j] = 0;
				}
				else
				{
					if (line[i-1][j] == '#' || line[i][j-1] == '#' || line[i-1][j-1] == '#')
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = min_three(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
					}
				}
				sol = max(sol, dp[i][j]);
			}
		}

		printf("%d\n", sol);
	}
	return 0;
}
