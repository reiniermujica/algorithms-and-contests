/*
 
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
	
int N, M, K;
char line[20];
int i, j, k;

int main() {
	
	freopen( "cowsignal.in", "r", stdin );
	freopen( "cowsignal.out", "w", stdout );
	
	scanf("%d %d %d\n", &N, &M, &K);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s\n", line);
		
		int L = strlen(line);
		
		for (k = 0; k < K; k++)	//down
		{
			for (j = 0; j < L; j++)
			{
				for (int kk = 0; kk < K; kk++)	//side
					printf("%c", line[j]);
			}
			
			printf("\n");
		}
		
		
	}
	
	
	fflush(stdout);
	return 0;
}
