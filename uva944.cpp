#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;

ll next(ll n){
	ll res = 0;
	while(n){
		res += (n%10) * (n%10);
		n/=10;
	}
	return res;
}

ll dp[100000][2];


int main(){
	for(int i = 2; i <= 99999; i++){
		ll n = i;
		set<ll> b;
		b.insert(n);
		dp[i][0] = dp[i][1] = true;
		while(1){
			n = next(n);
			dp[i][0]++;				
			if (n == 1) break;
			if (!b.count(n)) b.insert(n);
			else { dp[i][1] = false ; break;}
		}
	}
	ll a,b;
	int r = 0;
	while(scanf("%lld %lld",&a,&b)!=-1){
		if (r) putchar(10);
		r = 1;
		dp[1][1] = dp[1][0] = 1;
		for(int i = a; i <= b; i++){
			if (dp[i][1]) cout<<i<<" "<<dp[i][0]<<endl;
		}
	}
	
	return 0;
}
