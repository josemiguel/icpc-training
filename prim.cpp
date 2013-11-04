#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
#define MAXN 101 
#define INF INT_MAX 

vector<vector<int> > adj;
vector<vector<int> > W;

int prim(int n, int start) {
	priority_queue<pair<int, int> > q;
	vector<int> dist(n,INF);
	vector<bool> used(n,false);
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
		for (int i = 0; i < adj[v].size(); i++) {
			int u = adj[v][i];
			if (used[u]) continue;
			cost = W[v][i];
			if (cost >= dist[u]) continue;
			dist[u] = cost;
			q.push(make_pair(-1*cost,u));
		}
	}
	return ret;
}
