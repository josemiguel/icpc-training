#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
using namespace std;

vector<vector<int> > g;
bool seen[32];
int dist[32];

int bfs(int ini,int nnodos, int ttl){
	queue<int> q;
	memset(seen,0,sizeof(seen));
	memset(dist,0,sizeof(dist));	
	q.push(ini);
	seen[ini] = 1;
	dist[ini] = 0;
	while(!q.empty()){
		int v = q.front();q.pop();
		if (dist[v]<ttl){
			for(int i = 0; i < g[v].size() ; i++){
				int u = g[v][i];

				if (!seen[u]){
					seen[u] = 1;
					dist[u] = dist[v]+1;
					q.push(u);
				}
			}
		}
	}
	int n = 0;
	for(int i = 0; i < nnodos;i++){
		if (!seen[i]){
			n++;
		}
	}
	return n;

}

int main(){
	int n;
	int r = 1;
	while(cin>>n && n){
		map<int,int> mp;
		int nodos=0;
		g = vector<vector<int> > (1200);
		int a,b;		
		for(int i = 0; i < n; i++){
			cin>>a>>b;
			if (mp.find(a)==mp.end()){mp[a]=nodos;nodos++;}
			if (mp.find(b)==mp.end()){mp[b]=nodos;nodos++;}
			g[mp[a]].push_back(mp[b]);
			g[mp[b]].push_back(mp[a]);
		}
		int ttl;

		while(cin>>a>>ttl && a+ttl){
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",r,bfs(mp[a],nodos,ttl),a,ttl);
			r++;			
		}
	}
	return 0;
}
