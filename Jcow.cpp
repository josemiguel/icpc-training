#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		int a[n+1];
		for(int i = 1; i <= n; i++)	cin>>a[i];
		int b[n+1];
		memset(b,0,sizeof b);
		for(int i = 1; i <= n; i++){
			for(int j = 0 ; j < a[i] ; ){
				if (!b[i] || b[i] > a[i]) j++;
				b[j] = i;
			}
		}
		for(int i = 0; i < n; i++){
			if (i >= 0 && i <= n-1) cout<<",";
			cout<<b[i];
		}
		cout<<endl;
		
		
	}
	return 0;
}
