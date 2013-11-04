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
vector< pair<double, pair<int, int> > > edg;

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
double kruskal(int n, int ne) {
	double cost = 0;
	sort(edg.begin(),edg.end()); //ordena las aristas por peso
	Init(n); //inicializa el Union-Find
	int k = 0;
	for (int i = 0; i < ne && k < n; i++) {
		int u = edg[i].second.first, v = edg[i].second.second;
		double w = edg[i].first;
		if (Find(u) != Find(v)) {
			Union(u,v);
			cost += w; 
			k++;
		}
	}
	return cost;
}
inline double dist(double a,double b, double c, double d){
	return sqrt((a-b)*(a-b) + (c-d)*(c-d));
}
int main(){
	int runs,r;
	scanf("%d",&runs);
	r = 0;
	while(runs--){
		if (r) putchar(10);
		r=1;
		int n;
		scanf("%d",&n);
		int m  = (n*(n-1))/2; // grafo completo
		vector<pair<double,double> > puntos(n);
		edg.clear();
		for(int i = 0; i < n ; i++){
			double u,v;
			scanf("%lf%lf",&u,&v);
			pair<double,double> p(u,v);
			puntos[i] = p;
		}
		for(int i = 0; i < n-1 ; i++){
			for(int j = i+1; j < n; j++){
				double w = dist(puntos[i].first,puntos[j].first,puntos[i].second,puntos[j].second);
				edg.push_back(make_pair(w,make_pair(i,j)));
			}
		}
		printf("%.2lf\n",kruskal(n,m));
	}
	return 0;
}

