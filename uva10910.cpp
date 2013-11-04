#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int N,T,P;
typedef long long Int;
Int dp[100][100];
Int F(int pos, int W){
	if (pos == N && W == 0) return 1;
	if (pos == N || W <= 0) return 0;
	if (dp[pos][W] != -1) return dp[pos][W];
	Int res = 0;
	for(int i = P; i <= T; i++)	res += F(pos+1,W-i);
	return dp[pos][W] = res;
}

int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		scanf("%d%d%d",&N,&T,&P);
		memset(dp,-1,sizeof dp);
		cout<<F(0,T)<<endl;
	}
}
