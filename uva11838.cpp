#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
vector<vector<int> > g,rg;
bool usd[2005];
stack<int> S;
void dfs1(int u){ usd[u] = true; for(int i = 0; i < g[u].size(); i++) if (!usd[g[u][i]]) dfs1(g[u][i]); S.push(u); }
void dfs2(int u){ usd[u] = true; for(int i = 0; i < rg[u].size(); i++) if (!usd[rg[u][i]]) dfs2(rg[u][i]); }

int main(){
	int n,m;
	while(cin>>n>>m && n+m){
		g = vector<vector<int> > (n);
		rg = vector<vector<int> > (n);
		int a,b,p;
		for(int i = 0; i < m; i++){
			cin>>a>>b>>p;
			a--,b--;
			g[a].push_back(b);
			rg[b].push_back(a);
			if (p == 2) g[b].push_back(a), rg[a].push_back(b);
		}
		memset(usd,0,sizeof usd);
		for(int i = 0; i < n; i++) if (!usd[i]) dfs1(i);
		memset(usd,0,sizeof usd);
		int cmps = 0;
		while(!S.empty()){
			int u = S.top();S.pop();
			if (!usd[u]){
				dfs2(u);
				cmps++;
			}
		}
		if (cmps > 1) cout<<0<<endl;
		else cout<<1<<endl;
	}

	return 0;
}

