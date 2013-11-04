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


#define MAX 10002

int id[MAX], sz[MAX]; 

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

int f[MAX];
int main(){
	int runs;
	scanf("%d",&runs);
	int u,v;
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i = 0 ; i < m ;i++){
			scanf("%d%d",&u,&v);
			if (Find(u) != Find(v)) Union(u,v);
		}
		memset(f,0,sizeof(f));
		int best = 0;
		for(int i = 0; i < n ; i++){
			int _f = Find(i);
			f[_f]++;
			best = max(f[_f],best);
		}
		cout<<best<<endl;
	}
	
	return 0;
}
