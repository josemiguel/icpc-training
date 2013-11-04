#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30

int n,m;
int dp[1005][35];
int p[1005],w[1005];

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ;i++){
			scanf("%d %d",&p[i],&w[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n ; i++)
			for(int j = 1; j <= 31; j++)
				dp[i][j] = (w[i] <= j) ? max(dp[i-1][j-w[i]] + p[i],dp[i-1][j]) : dp[i-1][j];		
		
		int q;
		scanf("%d",&q);
		int best = 0;
		while(q--){
			int M;
			scanf("%d",&M);
			best += dp[n][M];
		}
		printf("%d\n",best);
	}
	
	return 0;
}
