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
#define MAX 105
int n,m;
stack<int> topsort;
vector<vector<int> > g;
int seen[MAX];
int dist[MAX];
void dfs(int u){
	seen[u] = true;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (seen[v]) continue;
		dfs(v);
	}
	topsort.push(u);
}

int longestPathDAG(int s, int &e){
	memset(dist,0,sizeof(dist));
	memset(seen,0,sizeof(seen));
	dfs(s);
	int best = 0,w,v,low = 1<<30;
	while(!topsort.empty()){
		v = topsort.top(); topsort.pop();
		for(int i = 0; i < g[v].size(); i++){
			w = g[v][i];
			dist[w] = max(dist[w],dist[v]+1);
			best = max(dist[w],best);
		}
	}
	for(int i = 0; i < n ; i++)
		if (dist[i] == best){
			e = i+1; break;
		}
	return best;
}

int main(){
	int r = 1;
	while(scanf("%d",&n) && n){
		g = vector<vector<int> > (n);
		int s,v,u;
		scanf("%d",&s);
		while(scanf("%d%d",&u,&v) && u+v)
			g[u-1].push_back(v-1);
			
		int e,d;
		d = longestPathDAG(s-1,e);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",r++,s,d,e);
	}
	
	return 0;
}
