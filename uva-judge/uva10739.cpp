#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

#define Min(x,y) ((x) < (y) ? (x) : (y))

char s[1005];
int dp[1005][1005];

int F(int i, int j){
	if (i>=j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j]) return dp[i][j] = F(i+1,j-1);
	return dp[i][j] = 1 + Min(F(i+1,j),Min(F(i,j-1),F(i+1,j-1)));
}

int main(){
	int T = 1,n;
	scanf("%d",&n);
	while(scanf("%s",s) && n--){
		memset(dp,-1,sizeof dp);
		printf("Case %d: %d\n",T++,F(0,strlen(s)-1));
	}
	return 0;
}
