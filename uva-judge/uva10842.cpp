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
#define MAX 300050

int n,m;
int  p[MAX];
void Init(int n){for(int i = 0; i <= n; i++) p[i] = i;}
void link(int a, int b){ p[a] = b;}
int Find(int a){return p[a] == a ? a : p[a] = Find(p[a]);}
void Union(int a, int b){link(Find(a), Find(b));}


int main(){
	
	int runs;
	scanf("%d",&runs);
	for(int r = 1; r <= runs; r++){
		
		scanf("%d%d",&n,&m);
		vector<pair<int,pair<int,int> > > edg;
		for(int i = 0; i < m ;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if (u == v) continue;
			edg.push_back(mp(-w,mp(u,v)));			
		}
		Init(n);
		sort(All(edg));
		int res;
		for(int i = 0; i < m; i++){
			int u = edg[i].second.first;
			int v = edg[i].second.second;
			int w = edg[i].first;
			if (!i) res = w;
			if (Find(u) != Find(v)){
				Union(u,v);
				res = max(res,w);
			}
		}
		printf("Case #%d: %d\n",r,-res);
	}
	
	
	return 0;
}
