#include<iostream>
using namespace std;
int main(){

	int n;
	while(cin>>n && n){
		long long res = 0;
		for(int i = 0; i <= n; i++) res+=(n-i)*(n-i);
		cout<<res<<endl;
	}
	return 0;
}
