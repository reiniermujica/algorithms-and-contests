//Reinier César Mujica
//12/3/08 PSN-2008

#include <cstdio>
#include <cstring>

using namespace std;

const int
   mx = 1000002,
   n0 = '0';
   
int n,sol[mx];
char num[mx];

int main(){
    int i,j,k,co,res=0;
    gets(num);
    n=strlen(num);
    for (i=n-1; i>=0; i--){
      sol[i]=num[i] - n0 - sol[i+1] - res;
      if (sol[i] < 0){
        sol[i]+=10;
		res=1;   
      }
	  else res=0;      
    }
    if (!sol[0]) printf("IMPOSSIBLE");
    else 
	for (i=0; i<n; i++) printf("%d",sol[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}