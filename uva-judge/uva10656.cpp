#include<iostream>
using namespace std;

int main(){
	int N;
	while(cin>>N && N){
		int first = 0;
		for(int i = 0; i < N; i++){
			int k;
			cin>>k;
			if (k){
				if (first) cout<<" ";
				first = 1;
				cout<<k;
			}
		}
		if ( !first  ) cout<<0;
		cout<<endl;
	}
}
