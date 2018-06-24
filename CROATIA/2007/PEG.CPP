//Reinier César Mujica
//Crotia #1

#include <iostream>

const int
	mx = 9,
	mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
	
using namespace std;

int sol,i,j,k,x,y,cx,cy;
char t[mx][mx];

int main(){
	for (i=1; i<=7; i++)
     gets(t[i]);
	for (i=1; i<=7; i++)
	 for (j=0; j<7; j++){
	  if (t[i][j] != 'o') continue;
	  for (k=0; k<4; k++){
		x=i+mov[k][0]; y=j+mov[k][1];
		cx=x+mov[k][0]; cy=y+mov[k][1];
		if (t[x][y] == 'o' && t[cx][cy] == '.') sol++;
	  }
     }
	cout << sol << endl;
	fflush(stdout);
	return 0;
}
