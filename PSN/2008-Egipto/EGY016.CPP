#include <cstdio>
#include <string>
#define mx 151

long n,lcs[mx][mx],sol;
char t[mx],cad[mx],inv[mx],cam[mx][mx];

void open(){
     long i,k;
     freopen("spl.in","r",stdin);
     scanf("%s",t);
     n=strlen(t); k=0; cad[0]=' '; inv[0]=' ';
     for (i=1; i<=n; i++){
         cad[i]=t[k];
         inv[i]=t[n-i];
         k++;
         }
     }

long longest_cs(){
     long i,j;
     for (i=1; i<=n; i++){
      for (j=1; j<=n; j++){
          if (cad[i] == inv[j]){
             lcs[i][j]=lcs[i-1][j-1] + 1;
             cam[i][j]='0';
             }
          else
          if (lcs[i-1][j] > lcs[i][j-1]){
             lcs[i][j]=lcs[i-1][j];
             cam[i][j]='1';
             }
          else
             {
             lcs[i][j]=lcs[i][j-1];
             cam[i][j]='2';
             }
          }
         }
     return (lcs[n][n]);
     }

void print(){
     long i,j,k;
     freopen("spl.out","w",stdout);
     printf("%d\n",sol);
     i=n; j=n; k=0;
     while (i*j!=0){
           if (cam[i][j] == '0'){
               k++;
               t[k]=cad[i];
               i--; j--;
              }
           else
           if (cam[i][j] == '1') i--;
           else j--;
           }
     for (i=1; i<=sol; i++)
      printf("%c",t[i]);
     }

int main(){
    open();
    sol=longest_cs();
    print();
    return 0;
}
