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
#define MAXN 1002
vector<vector<int> > g;
int dist[MAXN];
int seen[MAXN];

void bfs(int s){
	memset(seen,0,sizeof(seen));
	memset(dist,0,sizeof(dist));
	seen[s] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (!seen[u]){
				seen[u] = 1;
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
}
int n,m;
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) cout<<endl;
		scanf("%d%d",&n,&m);
		g = vector<vector<int> > (n);
		for(int i = 0 ; i < m ;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		bfs(0);
		for(int i = 1 ; i < n; i++){
			printf("%d\n",dist[i]);
		}
		
		
	}
	
	return 0;
}
