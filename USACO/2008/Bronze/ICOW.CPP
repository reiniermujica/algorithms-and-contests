//Reinier César Mujica
//7/3/08 2:40 p.m

#include <cstdio>

const int
	mx = 1002;
	
int n,m,act,t[mx];

int main(){
	int i,j,k,r,s;
	freopen("icow.in","r",stdin);
	freopen("icow.out","w",stdout);	
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
		scanf("%d",&t[i]);
	for (i=0; i<m; i++){
	   k=-1; act=0;
	   for (j=1; j<=n; j++)
	    if (t[j] > k){
			k=t[j];
			act=j;
		}
	   printf("%d\n",act);
       r=t[act] / (n-1);
	   s=t[act] % (n-1);
	   t[act]=0;
	   for (j=1; j<=n; j++)
	    if (j!=act) t[j]+=r;
       j=0;
	   while (s > 0){
          j++;
          if (act == j) continue;
          t[j]+=1;
          s--;       
        }
	}
	fflush(stdout);
    return 0;
}
