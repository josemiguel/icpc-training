#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while(cin>>n && n){
		ll res = 1;
		for(ll i = 2; i <= n; i++) res = (i*res)/__gcd(i,res);
		while(!(res%10)) res/=10;
		cout<<res%10<<endl;
	}
	return 0;
}
