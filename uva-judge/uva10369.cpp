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
#define MAX 10000
//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;

int  p[MAX];
void Init(int n){for(int i = 0; i <= n; i++) p[i] = i;}
void link(int a, int b){ p[a] = b;}
int Find(int a){return p[a] == a ? a : p[a] = Find(p[a]);}
void Union(int a, int b){link(Find(a), Find(b));}

double dist(pair<int,int> a, pair<int,int> b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		vector<pair<int,int> > pp(m);
		int u,v;
		for(int i = 0 ; i < m ;i++){
			scanf("%d %d",&u,&v);
			pp[i] = mp(u,v);
		}
		vector<pair<double,pair<int,int> > > edg;
		for(int i = 0; i < m -1 ; i++){
			for(int j = i +1 ; j < m; j++){
				edg.push_back(mp(dist(pp[i],pp[j]),mp(i,j)));
			}
		}
		Init(m);
		double cost = 0;
		sort(All(edg));
		int ne = (m*(m-1))/2;
		vector<double> T;
		for(int i = 0; i < ne; i++){
			double w = edg[i].first;
			int u = edg[i].second.first;
			int v = edg[i].second.second;
			if (Find(u) != Find(v)){
				Union(u,v);
				T.push_back(-w);
			}
		}
		sort(All(T));
		
		printf("%.2lf\n",-T[n-1]);
	}
	
	return 0;
}
