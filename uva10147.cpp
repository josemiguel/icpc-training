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

double dist(pair<double,double> a, pair<double,double> b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) putchar(10);
		scanf("%d",&n);
		vector<pair<double,double> > pp(n);
		int x,y;
		for(int i = 0 ; i <n ;i++){
			scanf("%d%d",&x,&y);
			pp[i] = mp((double)x,(double)y);
		}
		scanf("%d",&m);
		vector< pair<double, pair<int, int> > > edg;
		vector<vector<int> > mst(n,vector<int> (n));
		Init(n);
		for(int i = 0; i < m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			Union(u-1,v-1);
			mst[u-1][v-1] = mst[v-1][u-1] = true;
		}
		for(int i = 0; i < n - 1; i++){
			for(int j = i +1; j < n; j++){
				edg.push_back(mp(dist(pp[i],pp[j]),mp(i,j)));
			}
		}
		sort(All(edg));
		
		int ne = (n*(n-1))/2;
		set<pair<int,int> > T;
		for(int i = 0, k = 0 ; i < ne && k < n; i++){
			int u = edg[i].second.first;
			int v = edg[i].second.second;
			int w = edg[i].first;
			if (mst[u][v] || mst[v][u]) continue;
			if (Find(u) != Find(v)){
				Union(u,v);
				T.insert(mp(u,v));
				k++;
			}
		}
		if (T.size()){
			for(set<pair<int,int> >::iterator it = T.begin(); it!=T.end(); it++){
				printf("%d %d\n",it->first+1,it->second+1);
			}
		}else{
			puts("No new highways need");
		}
	}
	
	return 0;
}
