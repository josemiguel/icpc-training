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
#define MAX 1024
int n,m;
int seen[MAX];
int f;
int res[MAX];
vector<vector<int> > g;

void dfs_visit(int u){
	seen[u] = true;
	for(int i = 0 ; i < g[u].size(); i++){
		if (!seen[g[u][i]]){
			dfs_visit(g[u][i]);
		}
	}
}

void topsort(int u, int r){
	for(int i = 0; i < g[u].size();i++){
		seen[g[u][i]] = true;
		r--;
		topsort(g[u][i],r);
		seen[g[u][i]] = false;			
		r++;
		f++;
	}
	res[f--] = u;
	
}

void dfs(){
	memset(seen,0,sizeof(seen));
	for(int i = 1; i <= n ; i++){
		if (!seen[i]){
			dfs_visit(i);
			g[0].push_back(i);
		}
	}
	for(int i = 0; i < n; i++){
		cout<<i<<": ";
		for(int j = 0; j < g[i].size(); j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	n++;
	memset(seen,0,sizeof(seen));
	f = n-1;
	topsort(0,n);
}


int main(){
	
	scanf("%d%d",&n,&m);
	g = vector<vector<int> > (n+1);	
	for(int i = 0; i < m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	dfs();
	
	return 0;
}
