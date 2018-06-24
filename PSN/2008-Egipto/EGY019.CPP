//Reinier César Mujica
//7/3/08 10:10 45s a.m
//PSN - 2008

#include <cstdio>
#include <cmath>

int n,k,i;
double sol=0;

int main(){
    freopen("suburbio.in","r",stdin);
    freopen("suburbio.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (i=1; i<=n; i++) sol+=log10(i);
    for (i=1; i<=n-k; i++) sol-=log10(i);
    for (i=1; i<=k; i++) sol-=log10(i);
    printf("%.0lf\n",sol+1);
    fflush(stdout);
    return 0;
}
