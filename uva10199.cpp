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

int low[MAX],d[MAX],pai[MAX],seen[MAX],art[MAX];
int childs,nds,root,articulaciones;
vector<vector<int> > g;

void dfs(int u){
    seen[u] = true;
    d[u] = low[u] = nds++;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if (pai[u] != v){
            if(!seen[v]){
               pai[v] = u;
               dfs(v);
               if (u == root) childs++;
               if (d[u] <= low[v] && u != root){
                   art[u] = true;
               }
               if (d[u] <= low[v] && u == root && childs >= 2){
                   art[u] = true;
               }               
               low[u] = min(low[u], low[v]);
            }else{
               low[u] = min(low[u], d[v]);
            }
        }
    }
}

void solve(int n){
	memset(low,0,sizeof(low));
	memset(d,0,sizeof(d));
	memset(seen,0,sizeof(seen));	
	memset(pai,-1,sizeof(pai));
	memset(art,0,sizeof(art));
	articulaciones = 0;
	for(int i = 0; i < n; i++){
		if (!seen[i]){
			nds = 0;
			root = i;
			childs = 0;
			dfs(i);
		}
	}

}
int main(){
	int n,m;
	
	for(int r = 1;scanf("%d",&n) && n;r++){
		if (r!=1) putchar(10);
		map<string,int> ss;
		vector<string> s;
		string p,u,v;
		g = vector<vector<int> > (n);
		for(int i = 0; i < n; i++){
			cin>>p;
			ss[p] = i;
			s.push_back(p);
		}
		scanf("%d",&m);
		for(int i = 0; i < m; i++){
			cin>>u>>v;
			g[ss[u]].push_back(ss[v]);
			g[ss[v]].push_back(ss[u]);
		}
		solve(n);
		vector<string> vv;
		for(int i = 0; i < n; i++){
			if (art[i]){
				vv.push_back(s[i]);
			}
		}
		sort(All(vv));
		printf("City map #%d: %d camera(s) found\n",r,vv.size());
		for(int i = 0; i < vv.size(); i++){
			cout<<vv[i]<<endl;
		}
	}
}
