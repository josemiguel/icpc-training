#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
 
int id[10002], sz[10002]; 
vector< pair<int, pair<int, int> > > edg;

void Init(int n) {
	for (int i = 0; i < n; i++)
		id[i] = i, sz[i] = 1;
}

int Find(int i) {
	if (i == id[i]) return i;
	return id[i] = Find(id[i]);
}

void Union(int v, int w) {
	v = Find(v); w = Find(w);
	if (v == w) return;
	if (sz[v] > sz[w]) swap(v,w);
	id[v] = w;
	if (sz[v] == sz[w]) sz[w]++;
}



long long kruskal(int n, int ne) {
	long long cost = 0;
	sort(edg.begin(),edg.end());
	Init(n);
	int k = 0;
	for (int i = 0; i < ne && k < n; i++) {
		if (Find(edg[i].second.first) != Find(edg[i].second.second)) {
			Union(edg[i].second.first,edg[i].second.second);
			cost += edg[i].first; k++;
		}
	}
	return cost;
}


int main(int nargs, char **args) {
	int n, m;
	FILE *file = fopen(args[1],"r");
	fscanf(file,"%d %d",&n,&m);
	for (int i = 0; i < m; i++) {
		int u,v,peso;
		fscanf(file,"%d %d %d",&u,&v,&peso);
		edg.push_back(make_pair(peso, make_pair(u, v)));
	}
	printf("%lld\n",kruskal(n,m));
}


