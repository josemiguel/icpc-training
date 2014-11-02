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
#include <numeric>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define MAX 100024
#define vv vector<vector<int> >
#define pb push_back

int n,m;

vv g;
vv rg;
stack<int> p;
bool seen[MAX];
int scc[MAX];

int dfs(int u){
	seen[u] = true;
	for(int i = 0; i < g[u].size() ; i++){
		if (!seen[g[u][i]]){
			dfs(g[u][i]);	
		}
	}
	p.push(u);
}
int	num_scc;
int dfs2(int u){
	seen[u] = true;
	scc[u] = num_scc;
	for(int i = 0; i < rg[u].size() ; i++){
		if (!seen[rg[u][i]]){
			dfs2(rg[u][i]);	
		}
	}
}

int _scc(){
	memset(seen,0,sizeof(seen));
	
	for(int i = 0; i < n; i++){
		if (!seen[i]){
			dfs(i);
		}
	}

	memset(seen,0,sizeof(seen));
	num_scc = 0;		
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
		g = rg = vv (n);
		for(int i = 0; i < m ; i++) {
			scanf("%d%d",&u,&v);
			u--; v--;
			g[u].pb(v);
			rg[v].pb(u);
		}
		int nn = -1;
		int num_scc = _scc();
		vector<bool> in (num_scc,false);
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < g[i].size(); j++){
				if (scc[i] != scc[g[i][j]]){
					in[scc[g[i][j]]] = true;
				}
			}
		}
		nn = count(in.begin(),in.end(),false);
		printf("%d\n",nn);
	}
	
	return 0;
}
