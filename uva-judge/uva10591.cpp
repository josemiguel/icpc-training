#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;

ll F(ll x, int n){
	if (n == 1) return x;
	ll xx = F(x,n/2);
	if (n%2) return xx*xx*x;
	return xx*xx;
}

ll next(ll n){
	ll res = 0;
	while(n){
		res += (n%10) * (n%10);
		n/=10;
	}
	return res;
}

int main(){

	ll n;
	int rr;
	scanf("%d",&rr);
	for(int r = 1; r <= rr; r++){
		scanf("%lld",&n);
		printf("Case #%d: %lld ",r,n);
		set<ll> b;
		b.insert(n);
		bool f = true;
		while(1){
			n = next(n);
			if ( n == 1 ) break;
			if (!b.count(n))  b.insert(n);
			else { f = false ; break;}
		}
		if (f) puts("is a Happy number.");
		else   puts("is an Unhappy number.");
	}
	return 0;
}
