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
#define MAX 1502
#define All(v) v.begin(),v.end()
int id[MAX], sz[MAX]; 
vector< pair<int, pair<int, int> > > edg;
vector<int> res;

map<int,int> pp;

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


void kruskal(int n, int ne) {
	long long cost = 0;
	sort(edg.begin(),edg.end()); 
	Init(n); 
	int k = 0;
	for (int i = 0; i < ne && k < n-1; i++) {
		int u = edg[i].second.first, v = edg[i].second.second;
		int w = edg[i].first;
		if (Find(u) != Find(v)) {
			Union(u,v);
			pp[w]--;
			cost += w;
			k++;
		}
	}
	for(map<int,int>::iterator it = pp.begin(); it != pp.end(); it++){
		if (it->second > 0)
			res.push_back(it->first);
	}
}


int main(){
	int n,ne;
	while(cin>>n>>ne && n+ne){
		int aa,bb;
		int w;
		pp = map<int,int> ();
		edg = vector< pair<int, pair<int, int> > > ();
		for(int i = 0 ; i < ne ; i++){
			cin>>aa>>bb>>w;
			pp[w]++;
			edg.push_back(make_pair(w,make_pair(aa,bb)));
		}

		res = vector<int>();		
		kruskal(n,ne);
		if (res.size()){
			sort(All(res));
			cout<<res[0];
			for(int i = 1; i < res.size(); i++){
				cout<<" "<<res[i];
			}
			cout<<endl;
		}else{
			cout<<"forest"<<endl;
		}

	}
	return 0;
}

