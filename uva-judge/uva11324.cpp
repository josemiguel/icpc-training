#include<iostream>
#include<stack>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

vector<vector<int> > g,rg,adj;
stack<int> S;
int scc[1005], nscc,n,m;
int Nscc[1005];
bool usd[1005],seen[1005][1005],e[1005][1005];
void dfs1(int u) { usd[u] = true; 	for(int i = 0; i < g[u].size(); i++) if (!usd[g[u][i]]) dfs1(g[u][i]);  S.push(u); } 
void dfs2(int u) { Nscc[nscc]++; 	scc[u] = nscc; usd[u] = true; for(int i = 0; i < rg[u].size(); i++){ if (!usd[rg[u][i]]) dfs2(rg[u][i]); } } 
int dfs(int u){ int res = 0; for(int i = 0; i < adj[u].size(); i++){ res = max( res, Nscc[adj[u][i]] + dfs(adj[u][i]) ); } return res; }

int main(){

	int r;
	scanf("%d",&r);
	while(r--){
		memset(Nscc,0,sizeof Nscc);
		memset(scc,0,sizeof scc);
		memset(e,0,sizeof e);
		memset(usd,0,sizeof usd);		
		memset(seen,0,sizeof seen);
		
		scanf("%d %d",&n,&m);
		g = rg = adj = vector<vector<int> > (n);
		for(int i = 0; i < m; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			u--,v--;
			g[u].push_back(v);
			e[u][v] = true;
			rg[v].push_back(u);
		}
		
		for(int i = 0; i < n ; i++) if (!usd[i]) dfs1(i);
		memset(usd,0,sizeof usd);
		nscc = 0;
		while(!S.empty()){
			int u = S.top(); S.pop();
			if (!usd[u]) {
				dfs2(u);
				nscc++;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if ( i == j ) continue;
				if (seen[scc[i]][scc[j]]) continue;
				if (scc[i] != scc[j] && e[i][j]){
					adj[scc[i]].push_back(scc[j]);
					seen[scc[j]][scc[i]] = seen[scc[i]][scc[j]] = true;

				}
			}
		}

		int res = 0;
		for(int i = 0; i < nscc; i++){
			res = max(res , Nscc[i] + dfs(i) );
		}
		printf("%d\n",res);
	}
	return 0;
}
