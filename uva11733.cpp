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
vector<vector<int> > W;
vector<bool> used;
int n,m;
const int INF = 1<<30;

int prim(int start, int air) {
	priority_queue<pair<int, int> > q;
	vector<int> dist(n+1,INF);
	
	int cost, nv = 0;
	int ret = 0;
	dist[start] = 0;
	q.push(make_pair(0,start));
	while(!q.empty() && nv < n) {
		int v = q.top().second;
		q.pop();
		if (used[v]) continue;
		ret += dist[v];
		used[v] = true;
		nv++;
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v][i];
			if (used[u]) continue;
			cost = W[v][i];
			if (cost >= dist[u] || cost >= air) continue;
			dist[u] = cost;
			q.push(make_pair(-1*cost,u));
		}
	}
	return ret;
}

int traversal(int air, int &cmp){
	int total = 0;
	used = vector<bool> (n+1,false);
	for(int i = 0; i < n; i++){
		if (!used[i]){
			cmp++;
			total += prim(i,air);
		}
	}
	return cmp*air + total;

}

int main(){
	int runs;
	cin>>runs;
	for(int r = 1; r<=runs; r++){
		int cmp = 0, air;
		cin>>n>>m>>air;
		g = W = vector<vector<int> > (n);
		for(int i = 0; i < m ; i++){
			int u,v,w;
			cin>>u>>v>>w;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}
		int t = traversal(air,cmp);
		printf("Case #%d: %d %d\n",r,t,cmp);
	}
	return 0;
}
