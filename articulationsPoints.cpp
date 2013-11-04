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
int low[MAXN], part[MAXN];
int dt;
int seen[MAXN];

inline int where(int u, int i){
	return orig[adj[u][i]] != u ? orig[adj[u][i]] : dest[adj[u][i]];
}


int dfsbcc(int u, int p) {
	int ch = 0;
	seen[u] = dt++;
	low[u] = seen[u];
	for (int i = 0; i < nadj[u]; i++) {
		int v = where(u, i);
		if (!seen[v]) {
			dfsbcc(v, u); 
			ch++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= seen[u]) {
				part[u] = 1;
			}
		} else if (v != p) {
			low[u] = min(low[u], seen[v]);
		}
	}
	return ch;
}

void bcc() {
	memset(low, 0, sizeof(low));
	memset(seen, 0, sizeof(seen));
	memset(part, 0, sizeof(part));
	dt = 1;
	for (int i = 0; i < n; i++)
		if (!seen[i])
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
	printf("Puntos de articulacion:");
	for (i = 0; i < n; i++)
		if (part[i]) printf(" %d", i);
	printf("\n");
	return 0;
}

