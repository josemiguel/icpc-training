#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<string>
#include<cctype>
#include<set>
#include<map>
#include<numeric>

#define ll long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<20)
#define ones(x) __builtin_popcount(x)
#define clr(x) memset((x),0,sizeof(x))
#define rclr(x) memset((x),-1,sizeof(x))
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define MAX 30

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;
int n,m;

vector<vector<int> > g,rg;
bool usd[MAX];
int scc[MAX];
bool e[MAX][MAX];
bool seen[MAX][MAX];
int in[MAX],out[MAX];
stack<int> S;
int nscc;
void dfs1(int u){ usd[u] = true; for(int i = 0; i < g[u].size(); i++) if (!usd[g[u][i]]) dfs1(g[u][i]); S.push(u); }
void dfs2(int u){ scc[u]=nscc;usd[u] = true; for(int i = 0; i < rg[u].size(); i++) if (!usd[rg[u][i]]) dfs2(rg[u][i]); }


int main(){
	int runs;
	scanf("%d",&runs);
	while(runs--){
		scanf("%d%d",&n,&m);		
		clr(e);	clr(usd);clr(seen);clr(in);clr(out);clr(scc);
		g = rg = vector<vector<int> > (n);
		rep(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].pb(v); rg[v].pb(u);			
			e[u][v] = 1;
		}
		rep(i,n) if (!usd[i]) dfs1(i);
		clr(usd);
		nscc=0;
		while(!S.empty()){
			int v = S.top();S.pop();
			if (!usd[v]){
				dfs2(v);
				nscc++;
			}
		}
		rep(i,n){
			rep(j,n){
				if (seen[scc[i]][scc[j]]) continue;
				if (scc[i]!=scc[j] && e[i][j]){
					out[scc[i]]++;
					in[scc[j]]++;
					seen[scc[i]][scc[j]]=true;
				}
			}
		}
		int o=0,ii=0;
		for(int i=0;i<nscc&&nscc!=1;i++) {
			if (out[i]==0) o++;
			if (in[i]==0) ii++;
		}
		printf("%d\n",min(o,ii));
		
	}
	return 0;
}
