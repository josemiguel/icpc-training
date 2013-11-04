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

vector<vector<int> > g;
int color[215];
int seen[215];

int bfs(int s){
	memset(color,0,sizeof(color));
	queue<int> q;
	q.push(s);
	color[s] = 1;
	seen[s] = true;
	int nodos = 0;
	while(!q.empty()){
		int v = q.front();q.pop();
		nodos++;
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (!color[u] && !seen[u]){
				color[u] = -color[v];
				seen[u] = true;
				q.push(u);
			}else if (color[u] == color[v]){
				return 0;
			}
		}
	}
	return nodos;
}

int placeGuards(int n){
	int c = 0;
	for(int i = 0; i < n ; i++){
		if (!seen[i]){
			int nodos = bfs(i);
			if (!nodos) return -1;
			if (nodos == 1) {c += 1; continue; }
			int a = 0, b = 0;
			for(int j = 0; j < n; j++){
				if (color[j] < 0)	a++;
				else if (color[j] > 0) b++;
			}
			c += min(a,b);
		}
	}
	return c;
}

int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1 ; r <= runs ; r++){
		int n,m;
		scanf("%d%d",&n,&m);
		g = vector<vector<int> > (n);
		memset(color,0,sizeof(color));
		memset(seen,0,sizeof(seen));	
		int k = 0;
		for(int i = 0 ; i < m ;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("%d\n",placeGuards(n));
	}
	
	return 0;
}
