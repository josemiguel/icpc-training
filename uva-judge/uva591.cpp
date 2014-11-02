#include<iostream>
using namespace std;

int main(){

	int n;	
	for(int r = 1; cin>>n && n ; r++){
		int a[n+1];
		int s = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			s += a[i];
		}
		int m = 0;
		s /= n;
		for(int i = 0; i < n; i++) a[i] -= s;
		
		for(int i = 0; i < n; i++){
			if (a[i] > 0) m+=a[i];
		}
		cout<<"Set #"<<r<<"\nThe minimum number of moves is "<<m<<".\n"<<endl;
	}
	return 0;
}
