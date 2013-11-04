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
#define N 15002

vector<vector<int> > g;
int out[N];
int dp[N];
int seen[N];

int count(int u, int d){
	if (u == d) return 1;
	if(seen[u]) return dp[u];
	seen[u] = true;
	dp[u] = 0;
	for(int i = 0; i < g[u].size() ; i++){
		dp[u] += count(g[u][i],d);
	}
	return dp[u];
}


int main(){
	int n,m;
	for(int r = 0;scanf("%d",&n) != -1 ; r++){
		if (r) putchar(10);
		
		memset(out,0,sizeof(out));
		memset(dp,0,sizeof(dp));
		memset(seen,0,sizeof(seen));
		
		g = vector<vector<int> > (n);
		
		for(int i = 0; i < n; i++){
			scanf("%d",&m);
			while(m--){
				int v;
				scanf("%d",&v);
				g[i].push_back(v);
				out[i]++;
			}
		}

		int W = 0;
		for(int i = 0; i < n; i++){
			if (!out[i]){
				memset(seen,0,sizeof(seen));
				W += count(0,i);
			}
		}
		
		printf("%d\n",W);
	}
	
	return 0;
}
