//Reinier César Mujica
//13/3/08 PSN - 2008

#include <cstdio>

int n,sol;

bool prime(int x){
     bool ok=true;
     for (int i=2; i*i<=x; i++){
        if (x % i == 0){
			ok=false;
			break;
		}
     }   
     return ok;    
}

int main(){
	int i,j;
	scanf("%d",&n);
	if (prime(n)) printf("%d\n",0);
	else
	{
    i=n-1; 
	while (!prime(i)) i--;
	j=n+1;
	while (!prime(j)) j++;
	sol=j-i;  
    printf("%d\n",sol);
    }
	fflush(stdout);
	return 0;
}
