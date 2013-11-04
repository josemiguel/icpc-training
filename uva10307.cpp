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
#define pb push_back
#define All(v) v.begin(),v.end()
#define INF 1<<30
#define x first
#define y second
#define MAX 1002

int n,m;
int id[MAX],sz[MAX];
vector< pair<int, pair<int, int> > > edg;
vector<pair<int,int> > nodes;
char g[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

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


void bfs(int si, int sj){
	queue<pair<int,int> > q;
	q.push(mp(si,sj));
	memset(dist,-1,sizeof(dist));
	dist[si][sj] = 0;
	while(!q.empty()){
		pair<int,int > v = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			pair<int,int> u(v.x + dx[i], v.y + dy[i]);
			if (u.x >= 0 && u.y >=0 && u.x < n && u.y < m){
				if (dist[u.x][u.y] != -1) continue;
				if (g[u.x][u.y] == '#') continue;
				dist[u.x][u.y] = dist[v.x][v.y] + 1;
				q.push(u);
			}
		}
	}
}

long long kruskal(int n, int ne) {
	long long cost = 0;
	sort(edg.begin(),edg.end());
	Init(n); 
	int k = 0;
	for (int i = 0; i < ne && k < n; i++) {
		int u = edg[i].second.first, v = edg[i].second.second;
		int w = edg[i].first;
		if (Find(u) != Find(v)) {
			Union(u,v);
			cost += w; 
			k++;
		}
	}
	return cost;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&m,&n);
		cin.ignore();
		nodes = vector<pair<int,int> > ();
		edg	= vector< pair<int, pair<int, int> > >() ;
		for(int i = 0 ; i < n ;i++){
			for(int j = 0; j < m ;j++){
				g[i][j] = getchar();
				if (g[i][j] == 'A' || g[i][j] == 'S')  nodes.pb(mp(i,j));
			}
			getchar();
		}
		int vs = nodes.size();
		
		for(int i = 0; i < vs; i++){
			int si = nodes[i].x;
			int sj = nodes[i].y;
			bfs(si,sj);
			for(int j = i+1; j < vs; j++){
				int di = nodes[j].x;
				int dj = nodes[j].y;
				if (di == si && dj == sj) continue;
				edg.pb(mp(dist[di][dj],mp(i,j)));
			}
		}
		printf("%lld\n",kruskal(vs,(vs*(vs-1))/2)); 
	}
	return 0;
}
