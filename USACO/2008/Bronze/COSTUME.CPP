//Reinier César Mujica
//7/3/08 2:20 16s p.m

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	mx = 20002;
	
int t[mx],n,m,sol,cont,i,j;

int main(){
	freopen("costume.in","r",stdin);
	freopen("costume.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<=n; i++) scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	i=1; j=n;
	while (i<j) {
		while (i<j && t[i] + t[j] > m) j--;
		if (i < j) sol+=j-i;
		i++;
	}
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
