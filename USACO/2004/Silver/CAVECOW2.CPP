//Reinier César Mujica
//3/3/08 3:30 15s pm.
//PSN - 2008

#include <cstdio>

const
 int mx = 25002;
 
int n,m,t[mx],nl[mx];

int build_table(){
	int i,k;
	for (i=2; i<=n; i++){
		k=i-1;
		while (k != 0){
			  if (t[i] > t[k]){
			     nl[i]=k;
				 break;
				}
			  else
			   k=nl[k];		  
		}
	}
}

int min_element(int ini,int fin){
	int k,sol=t[fin];
	k=nl[fin];
	while (k!=0){
		  if (k >= ini){
			 sol=t[k];
			 k=nl[k];
		  }
		  else break;
	}
    return sol;
}
	
int main(){
	int i,j,x,y;
	freopen("cavecow2.in","r",stdin);
	freopen("cavecow2.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
	 scanf("%d",&t[i]);
	build_table();
	for (i=1; i<=m; i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",min_element(x,y));
	}
    fflush(stdout);
	return 0;
}
