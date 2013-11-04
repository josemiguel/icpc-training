#include<iostream>
using namespace std;
typedef long long Int;
Int x;

int main(){

	int runs;
	cin >> runs;
	while( runs-- ){
		cin >> x;

		Int acc =  (x&(-x))  - 1;
		cout << x - acc  << " " ;
		cout << x + acc  << endl;
	}

	return 0;
}
