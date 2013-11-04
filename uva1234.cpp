#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int p[10005];
void Init(int n){for(int i = 1; i <= n; i++) p[i]=i;}
int Find(int u){return  (u == p[u])? u : Find(p[u]);}
void Union(int u, int v) { p[Find(u)] = Find(v);}
#define All(x) x.begin(),x.end()
int main(){
	int runs;
	scanf("%d",&runs);
	while(runs--){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<pair<int,pair<int,int> > > edg;
		int tot = 0;
		for(int i = 0; i < m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			tot += w;
			edg.push_back(make_pair(-w,make_pair(u,v)));
		}
		int cost = 0;
		Init(n);
		sort(All(edg));
		for(int i = 0; i < m; i++){
			int u = edg[i].second.first;
			int v = edg[i].second.second;
			int w = edg[i].first;
			
			if (Find(u) != Find(v)){
				Union(u,v);
				cost += -w;
			}
		}
		printf("%d\n",tot-cost);


	}
	scanf("%d",&runs);
	return 0;
}
