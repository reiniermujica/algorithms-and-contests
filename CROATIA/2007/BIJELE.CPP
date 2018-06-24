//Reinier César Mujica
//Croatia #2

#include <iostream>

using namespace std;

const int
	cant[6] = {1,1,2,2,2,8};
	
int main(){
	int i,j,k;
	for (i=0; i<5; i++){
	 cin >> k;
	 cout << cant[i] - k << ' ';
	}
	cin >> i;
	cout << cant[5] -  i << endl;
	fflush(stdout);
	return 0;
}
