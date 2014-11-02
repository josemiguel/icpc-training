#include<iostream>
using namespace std;

int main(){
	int runs;
	cin>>runs;
	for(int r = 1; r <= runs; r++){
		int n;
		cin>>n;
		long long res = 0;
		for(int i = 1; i <= n; i++)	res += (i*(i+1)*(i+2)) / 2;
		cout<<r<<" "<<n<<" "<<res<<endl;
	}
	return 0;
}
