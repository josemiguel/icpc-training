#include<iostream>
using namespace std;

int MOD(int a, int b){
	if ( a < 0 ) return -(-a % b - b) % b;
	return a % b;
}

int f(char c){
	int res = 0;
	for(int i = 0; i < 8; i++){
		if ( c & ( 1 << i ) ){
			res += ( 1 << ( 7 - i) );
		}
	}
	return res;
}

int main(){


	string s;
	getline( cin , s);
	int ant = 0;
	for(int i = 0; i < s.size(); i++){
		int piv = f(s[i]);
		cout << MOD(ant-piv, 256) <<endl;
		ant = piv;
		
	}

	return 0;
}
