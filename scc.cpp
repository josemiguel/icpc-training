#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


#define MAXN 1024
int adj[MAXN][MAXN], nadj[MAXN];
int comp[MAXN], vis[MAXN], stck[MAXN], t, high[MAXN], num, ncomp; 

void dfscc(int u) { 
	int i, v; 
	high[u] = vis[u] = num--; 
	stck[t++] = u;
	
	for (i = 0; i < nadj[u]; i++) { 
		v = adj[u][i]; 
		if (!vis[v]) { 
			dfscc(v); 
			high[u] = max(high[u], high[v]); 
		} else if (vis[v] > vis[u] && !comp[v]) 
			high[u] = max(high[u], vis[v]); 
	}
	
	if (high[u] == vis[u]) { 
		ncomp++; 
		do { 
			v = stck[--t]; 
			comp[v] = ncomp; 
		} while (v != u); 
	} 
} 
void scc(int n) {
	int i;
	ncomp = t = 0; num = n;
	
	memset(vis, 0, sizeof(vis));
	memset(comp, 0, sizeof(comp));
	
	for (i = 0; i < n; i++)
		if (!vis[i])
			dfscc(i);
}
/**** Exemplo simples de uso ****/
#include <cstdio>
int main(void){
	int u, v;
	int n,m;
	while(scanf("%d%d", &n, &m)!=-1 && n+m){
		getchar();
		map<string,int> mp;
		memset(nadj,0,sizeof(nadj));
		for(int i = 0; i < n ; i++){
			string s;
			getline(cin,s);
			mp[s] = i;
		}
		for (int i = 0; i < m; i++) {
			string s1,s2;
			getline(cin,s1); getline(cin,s2);			
			 u = mp[s1]; v = mp[s2];
			adj[u][nadj[u]++] = v;
		}
		scc(n);
		printf("%d\n", ncomp);
	}
	return 0;
}
