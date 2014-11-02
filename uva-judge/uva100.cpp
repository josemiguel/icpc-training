#include<iostream>
#include<cstring>
using namespace std;

typedef unsigned long long ll;
#define MAX 1000005
#define _max(x,y) x > y ? x : y
int dp[MAX];
int F(ll n){
	if (n == 1) return 1;
	if (n < MAX && dp[n] != -1) return dp[n];
	if (n & 1) {
		if (n < MAX) return dp[n] = 2 + F((3*n+1)>>1);
		return 2 + F((3*n+1)>>1);
	}
	if (n < MAX) return dp[n] = 1 + F(n>>1);
	return 1 + F(n>>1);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int a, b;
	memset(dp,-1,sizeof dp);	
	while(cin>>a>>b){
		bool f = 0;
		if (a>b) { f = 1; swap(a,b); }
		int res = 0;
		for(int i = a; i <= b; i++){
			res = _max(res,F(i));
		}
		if (f) swap(a,b);
		cout<<a<<" "<<b<<" "<<res<<endl;
	}
	return 0;
}
