#include<iostream>
using namespace std ;

int a[5005], b[5005];

int main(){

	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> a[i];
		b[a[i]]++;
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if ( b[i] == 0) res++;
	}
	cout << res << endl;
	

	return 0;
}
