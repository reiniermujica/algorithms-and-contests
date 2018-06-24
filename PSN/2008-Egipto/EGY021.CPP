//Reinier César Mujica
//12/3/08 PSN - 2008

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	mx = 2002;
	
int n,m,sol=0,act,t[mx][mx],next[mx],prev[mx];

int main(){
	int i,j,k;
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++){
	   for (j=1; j<=m; j++){
  	    scanf("%d",&k);
        if (k) t[i][j]=t[i-1][j] + k;      
       } //read full file
        
	   for (j=2; j<=m; j++){ //<----
		 k=j-1;
		 while (k && t[i][k] >= t[i][j]) k=prev[k];
		 prev[j]=k;
	   }
       for (j=m-1; j>0; j--){ //---->
		 k=j+1;
		 while (k && t[i][k] >= t[i][j]) k=next[k];
		 next[j]=k;
	   }
	   for (j=1; j<=m; j++){
		 act=(next[j] - prev[j] - 1);
		 act*=t[i][j];
		 sol=max(sol,act);
	   }  
	}
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}