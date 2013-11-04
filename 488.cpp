#include<iostream>
using namespace std;

int main(){
	int r,n,f;
	cin>>r;
	while(r--){
		cin>>n>>f;
		while(f--){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					cout<<i;
				}
				cout<<endl;
			}
			for(int i=n-1;i>=1;i--){
				for(int j=1;j<=i;j++){
					cout<<i;
				}			
				cout<<endl;				
			}
			if (f!=0) cout<<endl;
		}
		
	}
}
