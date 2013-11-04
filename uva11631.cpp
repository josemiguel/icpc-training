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

#define MAX 10002

int id[MAX], sz[MAX]; 
vector< pair<int, pair<int, int> > > edg;

/*ESTRUCTURA UNION-FIND*/
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
/*FIN DE UNION-FIND*/

//llamar con n=numero de vertices, ne=numero de aristas
long long kruskal(int n, int ne) {
	long long cost = 0;
	sort(edg.begin(),edg.end()); //ordena las aristas por peso
	Init(n); //inicializa el Union-Find
	int k = 0;
	for (int i = 0; i < ne && k < n; i++) {
		int u = edg[i].second.first, v = edg[i].second.second;
		int w = edg[i].first;
		if (Find(u) != Find(v)) {
			Union(u,v);
			cost += w; 
			k++;
		}
	}
	return cost;
}



int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && n+m){
		int W = 0;
		edg.clear();
		for(int i = 0; i < m ; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			W+=w;
			edg.push_back(make_pair(w,make_pair(u,v)));
		}
		printf("%lld\n",W-kruskal(n,m));
	}
	return 0;
}
