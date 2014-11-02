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
#define MAX 10024
#define vv vector<vector<int> >
int n,m;

vv g;
stack<int> p;
bool seen[MAX];

int dfs(int u){
	seen[u] = true;
	for(int i = 0; i < g[u].size() ; i++){
		if (!seen[g[u][i]]){
			dfs(g[u][i]);	
		}
	}
	p.push(u);
}

int dfs2(int u){
	seen[u] = true;
	for(int i = 0; i < g[u].size() ; i++){
		if (!seen[g[u][i]]){
			dfs2(g[u][i]);	
		}
	}
}

int scc(){
	memset(seen,0,sizeof(seen));

	for(int i = 0; i < n; i++){
		if (!seen[i]){
			dfs(i);
		}
	}
	int	num_scc = 0;	
	memset(seen,0,sizeof(seen));
	while(!p.empty()){	
		int v = p.top(); p.pop();
		if (!seen[v]){
			dfs2(v);
			num_scc++;
		}
	}
	return num_scc;
}

int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1 ; r <= runs ; r++){
		int u,v;
		scanf("%d %d",&n,&m);
		g = vv (n);
		for(int i = 0; i < m ; i++) {
			scanf("%d%d",&u,&v);
			u--; v--;
			g[u].push_back(v);
		}
		printf("Case %d: %d\n",r,scc());
	}
	
	return 0;
}
