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
int n,m;


#define MAX 50005

int id[MAX], sz[MAX]; 

void Init(int n){
	for(int i = 0; i < n; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

int Find(int u){
	if (u == id[u]) return u;
	return id[u] = Find(id[u]);
}

void Union(int v, int w){
	v = Find(v) ; w = Find(w);
	if (v == w) return;
	if (sz[v] > sz[w]) swap(v,w);
	id[v] = w;
	if (sz[v] == sz[w]) sz[w]++;
}

int f[MAX];
int main(){
	int u,v;
	for(int r = 1 ; scanf("%d%d",&n,&m) && n+m; r++){
		Init(n);
		for(int i = 0 ; i < m ;i++){
			scanf("%d%d",&u,&v);
			if (Find(u) != Find(v)) Union(u,v);
		}
		set<int> s;
		for(int i = 0; i < n ; i++){
			s.insert(Find(i));
		}
		printf("Case %d: %d\n",r,s.size());
	}
	
	return 0;
}
