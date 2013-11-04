#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;


int main(){
	int r,a,b,c,n;
	cin>>r;
	for(int i=0;i<r;i++){
		cin>>n;
		int s=0;
		while(n--){
			cin>>a>>b>>c;
			s+=a*c;
		}
		cout<<s<<endl;
		//if (i<r-1) cout<<endl;
	}
	
}
