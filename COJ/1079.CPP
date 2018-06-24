#include <cstdio>
int T,N,s,i,j,d[150][150];int main(){scanf("%d",&T);while(T--){scanf("%d",&N);s=0;for(i=1;i<=N;i++)for(j=1;j<=i;j++){scanf("%d",&d[i][j]);d[i][j]+=(d[i-1][j]>?d[i-1][j - 1]);if(i==N)s>?=d[i][j];}printf("%d\n",s);}return 0;}
