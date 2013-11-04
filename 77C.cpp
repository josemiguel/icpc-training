#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long Int;


void dijkstra(int ini, vector<Int> &dist, vector<vector<pair<int,Int> > > g){
	set<pair<Int,int> > Q;
	Q.insert(make_pair(0LL,ini));
	dist[ini] = 0;
	while(!Q.empty()){
		pair<Int,int> vv = *Q.begin(); Q.erase(Q.begin());
		int v = vv.second;
		Int w1 = vv.first;
		for(int i = 0; i < g[v].size(); i++){
			pair<int,Int> uu = g[v][i];
			int u = uu.first;
			Int w2 = uu.second;
		 	if (dist[u] == -1 || dist[u] > w1+w2){
				dist[u] = w1+w2;
				Q.insert(make_pair(dist[u],u));	
			}
		}
		
	}

}

int main(){

	int n,m;
	int ini,fin;
	cin>>n>>m>>ini>>fin;
	
	vector<vector<pair<int,Int> > > g(n+1),adj(n+1);
	vector<int> T(n+1),C(n+1);
	for(int i = 0; i < m; i++){
		int u,v;Int w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}

	for(int i = 1; i <= n; i++) cin>>T[i]>>C[i];
	
	for(int i = 1; i <= n; i++){
		vector<Int> dist(n+1,-1);

		dijkstra(i, dist, g);

		for(int j = 1; j <= n; j++){
			if (i == j) continue;
			if (dist[j] != -1  && dist[j] <= T[i]){
				adj[i].push_back(make_pair(j,C[i]));
			}
		
		}
	
	}
	vector<Int> dist(n+1,-1);
	dijkstra(ini, dist, adj);
	cout << dist[fin] <<endl;

	return 0;
}
