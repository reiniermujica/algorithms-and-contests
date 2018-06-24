//Reiner César Mujica 
//6/3/08 3:35 p.m

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	mx = 202;

struct pto{
	int x,y;
};

int n,sol,cant;
bool h1,h2;
pto t[mx];
double rec[mx*mx];

int main(){
	int i,j;
	double d1, d2;
	freopen("lines.in","r",stdin);
	freopen("lines.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	 scanf("%d %d",&t[i].x,&t[i].y);
	for (i=1; i<=n; i++)
	 for (j=i+1; j<=n; j++){
		d1=(t[i].y - t[j].y);
		d2=(t[i].x - t[j].x);
		if (d1 == 0){
           if (!h1){
			h1=true;
			sol++;
           }
		}
		else
		if (d2 == 0){
           if (!h2){
			h2=true;
			sol++;
           }
		}
		else
		{
		cant++;
		rec[cant]=d1/d2;
		}	
	 }
	sort(rec+1,rec+cant+1); sol++; 
	for (i=2; i<=cant; i++)
	 if (rec[i] != rec[i-1]) sol++;
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
