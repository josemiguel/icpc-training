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
#define MAX 10002

int n,m;
map<int,int >indegree;
vector<vector<int> >g;
int seen[MAX];

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		if (!seen[g[u][i]]){
			dfs(g[u][i]);
		}
	}
}

bool isTree(){

	int root = 0;
	if (m != n-1) return false;
	for(map<int,int>::iterator it = indegree.begin(); it != indegree.end(); it++){
		if (it->second > 1){
			return false;
		}
		if (it->second == 0) root++;
	}
	if (root > 1) return false;
	int cmp = 0;
	memset(seen,0,sizeof(seen));	
	for(int i = 0; i < n ; i++){
		if (!seen[i]){
			dfs(i);
			cmp++;
			if (cmp > 1) return false;
		}
	}
	return true;
}
int main(){

	int r = 1;
	int u,v;	
	while(scanf("%d%d",&u,&v)){
		if (v==-1 && u ==-1) break;
		else if (v==0 && u==0) {printf("Case %d is a tree.\n",r++); continue;}
		n = 0; m = 0;
		map<int,int> mp;
		if (mp.find(u) == mp.end()) mp[u] = n,n++;
		if (mp.find(v) == mp.end()) mp[v] = n,n++;
		indegree = map<int,int> ();

		g = vector<vector<int> > (MAX);
		g[mp[u]].push_back(mp[v]);
		g[mp[v]].push_back(mp[u]);		
		indegree[mp[v]]++;
		m++;
		while(scanf("%d%d",&u,&v) && u+v){
			if (mp.find(u) == mp.end()) mp[u] = n, n++;
			if (mp.find(v) == mp.end()) mp[v] = n, n++;
			g[mp[u]].push_back(mp[v]);
			g[mp[v]].push_back(mp[u]);		
			indegree[mp[v]]++;
			m++;
		}
		if (isTree()){
			printf("Case %d is a tree.\n",r);
		}else{
			printf("Case %d is not a tree.\n",r);		
		}
		r++;
	}
	
	return 0;
}
