#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
#include <bitset>
using namespace std;

vector<bool> seen;
vector<int> pai, low, d;
vector< vector<int> > g;
vector< vector<bool> > is_bridge;
int n, ticks;

void dfs(int u){
    seen[u] = true;
    d[u] = low[u] = ticks++;
    for (int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if (pai[u] != v){
            if(!seen[v]){
               pai[v] = u;
               dfs(v);
               if (d[u] < low[v]){
                   is_bridge[u][v] = is_bridge[v][u] = true;
               }
               low[u] = min(low[u], low[v]);
            }else{
               low[u] = min(low[u], d[v]);
            }
        }
    }
}

int main(){
    while (scanf("%d", &n)==1){
        seen = vector<bool> (n,false);
        pai = vector<int> (n, -1);
		low = d = vector<int>  (n);
		g = vector<vector<int> > (n);
        is_bridge = vector<vector<bool> > (n, vector<bool>(n, false));
        if (n == 0){ printf("0 critical links\n\n"); continue; }
        
        for (int i=0; i < n; i++){
            int u,v,m;
            scanf("%d (%d)", &u, &m);
			while(m--){
				scanf("%d",&v);
				g[u].push_back(v);
				g[v].push_back(u);				
			}
        }
        
        ticks = 0;
        for (int i=0; i<n; ++i){
            if (!seen[i]){
                dfs(i);
            }
        }
        
        int C = 0;
        for (int i = 0; i < n; i++) 
	        for (int j = i+1; j < n; j++) 
		        C += is_bridge[i][j];
		        
        printf("%d critical links\n", C);
        for (int i=0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (is_bridge[i][j]){
                    printf("%d - %d\n", i, j);
                }
            }
        }
        printf("\n");
        
    }
    return 0;
}


