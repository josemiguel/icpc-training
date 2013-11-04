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

#define INF 1<<30
#define MAX 502

int id[MAX], sz[MAX]; 
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


long long kruskal(int n, int ne, int root) {
	long long cost = 0;
	sort(edg.begin(),edg.end()); 
	Init(n); 
	int k = 0;
	for (int i = 0; i < ne && k < n-1; i++) {
		int u = edg[i].second.first, v = edg[i].second.second;
		int w = edg[i].first;
		if (Find(u) != Find(v)) {
			Union(u,v);
			cost += w; 
			k++;
		}
	}
	int c = Find(root);
	for(int i = 0; i < n ; i++){
		if (c != Find(i)) return INF;
	}
	return cost;
}


int main(){
	int n,ne;
	while(cin>>n>>ne && n+ne){
		map<string,int> mp;
		string s,a,b;

		for(int i = 0 ; i < n ; i++){
			cin>>s;
			mp[(s)] = i;
		}
		int w;
		edg = vector< pair<int, pair<int, int> > > ();
		for(int i = 0 ; i < ne ; i++){
			cin>>a>>b>>w;
			int aa = mp[(a)];
			int bb = mp[(b)];
			edg.push_back(make_pair(w,make_pair(aa,bb)));
		}
		
		cin>>a;
		int cost = kruskal(n,ne,mp[(a)]);
		if (cost != INF){
			cout<<cost<<endl;
		}else{
			cout<<"Impossible"<<endl;
		}

	}
	return 0;
}

