#include<iostream>
#include<sstream>
#include<set>
#include<string>
using namespace std;

int main(){
	int n, r = 0;
	while(cin>>n && n){
		if (r) cout<<endl; r = 1;
		int a[n+1];
		for(int i = 0; i < n; i++)	cin>>a[i];
		for(int mask = 0; mask < (1<<n)-1; mask++)
			if (n - __builtin_popcount(mask) == 6){
				for(int i = n-1, f = 0; i >= 0; i--){
					if ((mask>>i) & 1) continue;
					if (f)	cout<<" "; f = 1;
					cout<<a[n-i-1];
				}
				cout<<endl;
			}
	}
	
	return 0;
}
