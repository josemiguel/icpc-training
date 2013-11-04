#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long Int ;
int n;
Int dp[100][15];

Int F(int pos, int last){
	if (pos == 0)  return 1; 
	if (dp[pos][last] != -1)  return dp[pos][last];
	Int res = 0;
	for(int i = 9; i >= last; i--) res += F(pos-1,i);
	return dp[pos][last] = res;	
}

int main(){

	int runs,r;
	scanf("%d",&runs);
	memset(dp,-1,sizeof dp);	
	while(runs--){
		scanf("%d %d",&r,&n);
		printf("%d %lld\n",r,F(n,0));
	}

	return 0;
}
