#include<iostream>
using namespace std;
	
int main(){
	int t;
	cin>>t;
	for(int r = 1 ; r <= t; r++){
		int a,b;
		cin>>a>>b;
		int s = 0;
		for(int i = a; i <= b; i++){
			if (i%2) s+=i;
		}
		cout<<"Case "<<r<<": "<<s<<endl;
	}
	return 0;
}
