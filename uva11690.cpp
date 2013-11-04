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
#define MAX 10005
//int g[MAX][MAX];
vector<vector<int> > g;
int n,m;
int seen[MAX];
int debt[MAX];
int total;

void dfs(int u){
	total += debt[u];
	seen[u] = true;
	for(int i = 0; i < g[u].size(); i++){
		if (!seen[g[u][i]]){
			dfs(g[u][i]);
		}
	}
}

bool solve(){
	memset(seen,0,sizeof(seen));
	for(int i = 0; i < n; i++){
		if (!seen[i]){
			total = 0;
			dfs(i);
			if (total != 0) return false;
		}
	}
	return true;
}
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		g = vector<vector<int> > (n);
		for(int i = 0 ; i < n ;i++){
			scanf("%d",&debt[i]);
		}
		for(int i = 0 ; i < m ;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);			
		}
		if (solve()){
			puts("POSSIBLE");
		}else{
			puts("IMPOSSIBLE");
		}
	}
	
	return 0;
}

