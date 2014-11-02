#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std ;


vector<vector<int > > g;

struct state{
	int mask, r;
	state(){}
	state(int mask, int r):mask(mask),r(r){}

};
int dist[1<<11][11];
int mov[1<<11][11];
int pai[1<<11][11];
int e[1<<11];
int main(){

	int n,m,l;


	while(cin>> n>> m >> l && n+m+l){
		for(int i = 0;  i < m; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 0; i < l; i++){
			int u,v;
			cin >> u >> v;
			e[u] |= (1<<v);
		}
		
	}

	queue<int> Q;
	Q.push(state(0,1));

	while(!Q.empty()){
		state cur = Q.front();Q.pop();
		int v = cur.r;
		int mask = cur.mask;
		
		for(int i = 0 ; i < g[v].size(); i++){
			int u = g[v][i];
			if (mask & (1<<u)){
				if (dist[mask | (1<<u)][u] == -1){
					Q.push(state(mask | (1<<u), u));
					dist[mask | (1<<u)][u] = dist[mask][v] + 1;
					mov[mask | 
				}

			}
		}
	}

	

	

	return 0;
}
