#include<iostream>
using namespace std;
int main(){

	int n;
	cin>>n;
	int a[4];
	a[0]=a[1]=a[2]=a[3]=0;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a[t]++;
	}
	cout << n - max(a[1],max(a[2],a[3])) << endl;
	return 0;
}
