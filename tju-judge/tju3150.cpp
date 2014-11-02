#include<iostream>
#include<algorithm>
#include<cctype>
#include<map>
#include<string>
using namespace std;

int main(){
	int runs;
	cin>>runs;
	for(int r = 1; r <= runs; r++){
		int a,b;
		cin>>a>>b;
		cout<<r<<" "<<(a*b)/__gcd(a,b)<<" "<<__gcd(a,b)<<endl;
	}
	return 0;
}
