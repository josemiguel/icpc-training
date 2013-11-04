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

//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;
#define MAX 5002
int mst[MAX];
vector< pair<int, pair<int, int> > > edg;
int  p[MAX];
void Init(int n){for(int i = 0; i <= n; i++) p[i] = i;}
void link(int a, int b){ p[a] = b;}
int Find(int a){return p[a] == a ? a : p[a] = Find(p[a]);}
void Union(int a, int b){link(Find(a), Find(b));}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		edg = vector< pair<int, pair<int, int> > > ();
		for(int i = 0 ; i < m ;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			edg.push_back(mp(w,mp(u,v)));
		}
		printf("Case #%d : ",r);		
		sort(All(edg));
		Init(n);
		int cost = 0,t = 0;
		int k = n;
		memset(mst,0,sizeof(mst));
		for(int i = 0; i < m; i++){
			int u = edg[i].second.first, v = edg[i].second.second;
			int w = edg[i].first;
			if (Find(u) != Find(v)){
				Union(u,v);
				cost += w;
				
				mst[i] = true;
				k--;
			}
		}
		t = cost;

		if (k != 1) puts("No way");
		else{
			int bestsec = 1<<30;
			for(int j = 0; j < m; j++){
				if (!mst[j]) continue;
				Init(n);
				int cost = 0;
				int k = n;
				for(int i = 0; i < m; i++){
					if (i == j) continue;
					int u = edg[i].second.first, v = edg[i].second.second;
					int w = edg[i].first;
					if (Find(u) != Find(v)){
						Union(u,v);
						cost += w;
						k--;
					}
				}
				if (k == 1)	bestsec = min(bestsec,cost);
			
			}
			if (bestsec == 1<<30){
				puts("No second way");
			}else{
				printf("%d\n",bestsec);
			}
			
		}
		
	}
	
	return 0;
}
