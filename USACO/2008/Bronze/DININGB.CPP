//Reinier César Mujica
//6/3/08 5:20 32s p.m

#include <cstdio>

const int 
	mx = 30001,
	oo = 1<<29;
	
int t[mx][3],n,sol=oo;

int main(){
	int i,j,k;
	freopen("diningb.in","r",stdin);
    freopen("diningb.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++){
		scanf("%d",&k);
		t[i][1]=t[i-1][1] + (k == 1);
		t[i][2]=t[i-1][2] + (k == 2);
	}
	for (i=0; i<=n; i++){
        if (t[n][1]  - t[i][1] + t[i][2] < sol)
         sol=t[n][1] - t[i][1] + t[i][2];        
    }
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
