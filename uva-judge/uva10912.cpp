#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int N;
int dp[30][30][505];
int F(int last,int pos, int W){
	if (pos == N && W == 0) return 1;
	if (dp[last][pos][W] != -1) return dp[last][pos][W];	
	int res = 0;
	for(int i = last+1; i <= 26; i++) res += F(i,pos+1,W-i);
	return dp[last][pos][W] = res;
}

int main(){
	int r = 1,T;
	while(scanf("%d%d",&N,&T) && N+T){
		memset(dp,-1,sizeof dp);
		if(N >= 27 || T >= 352) printf("Case %d: %d\n",r++,0);
		else printf("Case %d: %d\n",r++,F(0,0,T));
	}
}
