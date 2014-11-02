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

int n;
vector<pair<double,pair<int,int> > > roads;
vector<pair<double,pair<int,int> > > rails;
#define MAX 10002

int  p[MAX];
void Init(int n){for(int i = 0; i <= n; i++) p[i] = i;}
void link(int a, int b){ p[a] = b;}
int Find(int a){return p[a] == a ? a : p[a] = Find(p[a]);}
void Union(int a, int b){link(Find(a), Find(b));}


double kruskal(int f){
	vector<pair<double,pair<int,int> > > edg = f?roads:rails;
	double cost = 0;
	int m = edg.size();
	for(int i = 0; i < m; i++){
		int u = edg[i].second.first;
		int v = edg[i].second.second;
		double w = edg[i].first;
		if (Find(u) != Find(v)){
			Union(u,v);
			cost+=w;
		}
	}
	return cost;
}

double dist(pair<int,int> a, pair<int,int> b){
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		int s;
		roads = vector<pair<double,pair<int,int> > > ();
		rails = vector<pair<double,pair<int,int> > > ();
		scanf("%d%d",&n,&s);
		vector<pair<int,int> > pp(n);
		int m1, m2;
		for(int i = 0 ; i < n ;i++){
			scanf("%d%d",&pp[i].first,&pp[i].second);
		}

		for(int i = 0; i < n -1 ; i++){
			for(int j = i+1; j < n; j++){
				double dd = dist(pp[i],pp[j]);
				if (dd <= s){
					roads.push_back(mp(dd,mp(i,j)));
				}else{
					rails.push_back(mp(dd,mp(i,j)));
				}
			}
		}
		Init(n);
		sort(All(roads));
		sort(All(rails));
		double a = kruskal(1);
		set<int> states;
		for(int i = 0; i < n; i++){
			states.insert(Find(i));
		}
		double b = kruskal(0);
		printf("Case #%d: %d %d %d\n",r,states.size(),(int)round(a),(int)round(b));
		
	}
	
	return 0;
}
