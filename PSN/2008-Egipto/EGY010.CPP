//Reinier César Mujica
//25/2/08 11:33am 30s
//PSN-2008
#include <cstdio>
#include <cstring>

const int mx = 1000,ord0 = 'a' - 1;

long long n,m,sol,m1,m2,cant[27];
bool mk[27];
char cad[mx];

long long rest(){
    long long i,j,k;
    m2=1; m1=0;
    memset(mk,0,sizeof(mk));
    for (i=1; i<=26; i++) m1+=cant[i];
    for (i=1; i<=m1; i++) mk[i]=true;
    for (i=1; i<=26; i++){
        for (j=1; j<=cant[i]; j++){
            if (mk[j]) mk[j]=false;
            else m2*=j;
            }
        }
    k=1;
    for (i=1; i<=m1; i++)
     if (mk[i]) k*=i;
    return (k/m2);
    }

int main(){
    long long i,j,k;
    freopen("permut.in","r",stdin);
    freopen("permut.out","w",stdout);
    scanf("%s",cad);
    n=strlen(cad);
    for (i=0; i<n; i++) cant[cad[i] - ord0]++;
    for (i=0; i<n; i++){
     k=cad[i] - ord0;
     for (j=1; j<k; j++){
         if (cant[j] > 0) {
          cant[j]--;
          sol+=rest();
          cant[j]++;
         }
         }
     cant[k]--;
    }
    printf("%d\n",sol+1);
    fflush(stdout);
    return 0;
}
