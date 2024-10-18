#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> numeros;
	
	int num;
	
	cout << "Introduce varios numeros. Escribe 0 para salir" << endl;
	
	while(cin >> num && num!=0){
		numeros.push_back(num);
	}
	
	cout << "Has introducido las siguientes numeros: " << endl;
	for (int n: numeros){
		cout << n << endl;
	}
}