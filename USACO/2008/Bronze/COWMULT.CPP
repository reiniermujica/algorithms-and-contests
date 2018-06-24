//Reinier César Mujica
//6/3/08 4:30 p.m.

#include <cstdio>

int n,m,sol,h1,h2,t;

int main(){
	freopen("cowmult.in","r",stdin);
	freopen("cowmult.out","w",stdout);
	scanf("%d %d",&n,&m);
	while (n > 0){
	 h1=n % 10; t=m;
	 while (t > 0){
	  h2=t % 10;
	  sol+=h1*h2;
	  t/=10;
	 }
	 n/=10;	
	}
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
