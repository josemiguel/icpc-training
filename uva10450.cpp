#include<iostream>
using namespace std;
long long F[55];
int main(){
	F[0] = F[1] = 1;
	for(int i = 2; i <= 52; i++) F[i] = F[i-1] + F[i-2];
	int n,runs;
	cin>>runs;
	for(int r = 1; r<=runs; r++){
		cin>>n;
		cout<<"Scenario #"<<r<<":"<<endl<<F[n+1]<<endl<<endl;
	}
}
