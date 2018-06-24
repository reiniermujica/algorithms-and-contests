//============================================================================
// Name        : 1025.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct segment
{
	int start, end, score;

	segment(int s = 0, int e = 0, int c = 0)
	{
		start = s;
		end = e;
		score = c;
	}

	bool operator < (const segment &other) const
	{
		return end < other.end;
	}

};

int T, N, S;
int x, y, c;
int i, j, k;
int best[MAXN];
vector <segment> V;

int main() {

	scanf("%d", &T);
	while (T--)
	{
		V.clear();
		fill(best, best + MAXN, 0);

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d %d %d", &x, &y, &c);
			V.push_back(segment(x, x + y, c));
		}

		sort(V.begin(), V.end());

		best[0] = 0;
		for (i = 1; i <= N; i++)
		{
			vector<segment>::iterator pos;

			segment tmp = segment(0, V[i-1].start, 0);
			pos = upper_bound( V.begin(), V.end(), tmp );

			if (pos != V.end())
			{
				k = pos - V.begin();
			}
			else
				k = 0;

			best[i] = max(best[i - 1], best[k] + V[i-1].score);
		}

		printf("%d\n", best[N]);
	}

	return 0;
}
