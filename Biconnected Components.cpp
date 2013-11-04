#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 1024
#define MAXM 1024*1024


int n, m;
int adj[MAXN][MAXN], nadj[MAXN];
int orig[MAXM], dest[MAXM];
int low[MAXN], part[MAXN], ponte[MAXM], ncomp, comp[MAXM];
int dt;
int vis[MAXN];
stack<int> stck;

inline int VIZ(int u, int i){
	return orig[adj[u][i]] != u ? orig[adj[u][i]] : dest[adj[u][i]];
}


int dfsbcc(int u, int p) {
	int ch = 0;
	vis[u] = dt++;
	low[u] = vis[u];
	for (int i = 0; i < nadj[u]; i++) {
		int e = adj[u][i], v = VIZ(u, i);
		if (!vis[v]) {
			stck.push(e);
			dfsbcc(v, u); ch++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= vis[u]) {
				part[u] = 1;
				ncomp++;
				while (stck.top() != e) {
					comp[stck.top()] = ncomp;
					stck.pop();
				}
				comp[stck.top()] = ncomp; stck.pop();
			}
			if (low[v] == vis[v]) ponte[e] = 1;
		} else if (v != p) {
			if (vis[v] < vis[u]) stck.push(e);
				low[u] = min(low[u], vis[v]);
		}
	}
	return ch;
}

void bcc() {
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(part, 0, sizeof(part));
	memset(ponte, 0, sizeof(ponte));
	memset(comp, 0, sizeof(comp));
	dt = 1;
	ncomp = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			part[i] = dfsbcc(i, -1) >= 2;
}



int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	memset(nadj, 0, sizeof(nadj));
	for (i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		orig[i] = u; dest[i] = v;
		adj[u][nadj[u]++] = adj[v][nadj[v]++] = i;
	}
	bcc();
	printf("Pontos de Articulacao:");
	for (i = 0; i < n; i++)
		if (part[i]) printf(" %d", i);
	printf("\n");
	return 0;
}

