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
#define MAX 10005
struct Edge{
	int v,w,ht;
	Edge(){}
	Edge(int v, int w, int ht):v(v),w(w),ht(ht){}
};
//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;
bool hotel[105];
int dist[MAX][602];
vector<vector<Edge> > g;

int main(){
	
	while(scanf("%d",&n) && n){
		memset(hotel,0,sizeof(hotel));
		memset(dist,-1,sizeof(dist));
		g = vector<vector<Edge> > (n+1);
		int h,hs;
		scanf("%d",&hs);
		while(hs--) {scanf("%d",&h); hotel[h-1] = 1;}
		scanf("%d",&m);
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			g[u].push_back(Edge(v,w,0));
			g[v].push_back(Edge(u,w,0));
		}
		deque<Edge> q;
		q.push_front(Edge(0,0,0));
		dist[0][0] = 0;
		int res = -1;
		while(!q.empty()){
			int v = q.front().v;
			int w1 = q.front().w;
			int ht = q.front().ht;
			q.pop_front();
			if (v == n - 1) { res = ht; break;}
			if (hotel[v]){
				if (dist[v][0] == -1 || dist[v][0] > ht + 1){
					dist[v][0] = ht + 1;
					q.push_back(Edge(v,0,ht+1));
				}					
			}			
			for(int i = 0; i < g[v].size(); i++){
				int u = g[v][i].v;
				int w = g[v][i].w + w1;
				if (w > 600) continue;
				if (dist[u][w] == -1 || dist[u][w] > ht){
					dist[u][w] = ht;
					q.push_front(Edge(u,w,ht));
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

