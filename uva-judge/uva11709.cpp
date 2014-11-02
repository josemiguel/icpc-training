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
#define MAX 1002
int n,m;
vector<vector<int> > g;
vector<vector<int> > rg;
stack<int> p;
int seen[MAX];

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
	for(int i = 0; i < rg[u].size() ; i++){
		if (!seen[rg[u][i]]){
			dfs2(rg[u][i]);	
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

	while(scanf("%d%d",&n,&m)!=-1 && n+m){
		getchar();	
		map<string,int> mp;
		g = rg = vector<vector<int> > (n);
		for(int i = 0; i < n ; i++){
			string s;
			getline(cin,s);
			mp[s]=i;
		}
		for(int i = 0; i < m ; i++){
			string s1,s2;
			getline(cin,s1); getline(cin,s2);			
			int u = mp[s1], v = mp[s2];
			g[u].push_back(v);
			rg[v].push_back(u);			
		}
		int num_scc = scc();
		printf("%d\n",num_scc);
	}
	return 0;
}
