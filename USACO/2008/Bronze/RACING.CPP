//Reinier César Mujica 
//6/3/08 4:15 15s p.m.

#include <cstdio>

int n,m,u,f,d,sol,cont,i,act;
char c[3];

int main(){
	freopen("racing.in","r",stdin);
	freopen("racing.out","w",stdout);
	scanf("%d %d %d %d %d",&m,&n,&u,&f,&d);
    scanf("%c",&c);
	for (i=1; i<=n; i++){
        scanf("%s",&c);
		if (c[0] == 'u' || c[0] =='d') act=u+d;
		if (c[0] == 'f') act=2*f;
		if (cont + act <= m){
		 cont+=act;
		 sol++;
		}
		else break;
	}
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
