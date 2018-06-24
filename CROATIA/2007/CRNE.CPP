//Reinier César Mujica
//Croatia #2

#include <iostream>

using namespace std;

int n,sol,b1,b2;

int main(){
	cin >> n;
	b1=n / 2;
	b2=n % 2;
	sol=b1+1;
	sol*=(b1 + b2 + 1);
	cout << sol << endl;
	fflush(stdout);
	return 0;
}
