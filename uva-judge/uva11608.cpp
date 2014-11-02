#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int r = 0;
	while(cin>>n && n >= 0){
		int a[13],b[13];
		for(int i = 0; i < 12; i++) cin>>a[i];
		for(int i = 0; i < 12; i++) cin>>b[i];
		cout<<"Case "<<++r<<":"<<endl;
		
		for(int i = 0; i < 12; i++){
			if (b[i] > n) cout<<"No problem. :("<<endl;
			else cout<<"No problem! :D"<<endl, n -= b[i];
			n += a[i];
		}	
		
		
	}
	return 0;
}
