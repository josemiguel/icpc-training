#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long Int;

Int dp[65][33][102];
int n,k;
Int F(int pos, int unos, int T){
	if (unos > n/2) return 0LL;
	if (pos == -1 && unos == n/2 && T % k== 0) {
		return 1LL;
	}
	if (pos == -1) return 0LL;
	if (dp[pos][unos][T] != -1) return dp[pos][unos][T];
	Int res = 0;
	
	res += F(pos - 1,unos, T % k);
	res += F(pos-1,unos +1, (T % k + (1LL<<pos)%k )%k);
	
	return dp[pos][unos][T] = res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1; r <= runs; r++){
		memset(dp,-1,sizeof dp);
		scanf("%d %d",&n,&k);
		Int res = 0;
		if (k && n%2==0) res = F(n-2,1,(1LL<<(n-1)) % k);
		printf("Case %d: %lld\n",r,res);
	}
	return 0;
}
