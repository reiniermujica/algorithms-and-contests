//Reinier César Mujica
//Croatia #1

#include <iostream>

using namespace std;

int t[3][2],sol[2],i,j;

int main(){
	for (i=0; i<3; i++){
		cin >> t[i][0] >> t[i][1];	
		for (j=0; j<i; j++){
		 if (t[i][0] == t[j][0])
	      sol[0]=t[i][0];
	     if (t[i][1] == t[j][1])
	      sol[1]=t[i][1]; 
		}
	 }
	for (i=0; i<3; i++)
	 if (sol[0] != t[i][0]){
	  sol[0]=t[i][0]; break;
     }
    for (i=0; i<3; i++)
	 if (sol[1] != t[i][1]){
	  sol[1]=t[i][1]; break;
     }
	cout << sol[0] << ' ' << sol[1] << endl;
	fflush(stdout);
	return 0;
}
