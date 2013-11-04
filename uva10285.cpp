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
#define MAX 100
int g[MAX+2][MAX+2];
int dp[MAX+2][MAX+2];
int n,m;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};


int solve(int x, int y){
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >=0 && yy >=0 && xx < n && yy < m)
			if (g[xx][yy] < g[x][y]){
				dp[x][y] = max(dp[x][y],1+solve(xx,yy));
			}
	}
	if (dp[x][y]) return dp[x][y];
}

int main(){
	char s[300];
	int runs;
	scanf("%d",&runs);
	while(runs--){
		scanf("%s %d %d",s,&n,&m);
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				scanf("%d",&g[i][j]);
				dp[i][j] = 0;
			}
		}

		int best = 0;
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				if (!dp[i][j]){
					solve(i,j);
					best = max(dp[i][j],best);
				}
			}
		}

		printf("%s: %d\n",s,best+1);
	}
	return 0;
}
