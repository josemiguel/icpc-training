#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define MAX 50002
struct Edge{
	int v,w;
	Edge(){}
	Edge(int v, int w): v(v), w(w){}
};

bool operator>(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

const int INF = 1<<30;

vector<Edge> g[MAX];


int dijkstra(int start,int end, int n){
    priority_queue<Edge, vector<Edge>, greater<Edge> > q;
	vector<int> d(n+1,INF);

	q.push(Edge(start,0));
	d[start] = 0;

	
	while(!q.empty()){
		Edge e = q.top(); q.pop();
		int v = e.v;
		int vw = e.w;
		if (v == end) break;
		if (d[v] < vw) continue;
		for(int i = 0; i < g[v].size(); i++){
			Edge f = g[v][i];
			int u = f.v;
			int uw = f.w;
			if (d[u] > vw + uw){
				d[u] = vw + uw;
				q.push(Edge(u,d[u]));
			}
		}
	}
	
	return d[end];
}

int main(){
	int runs;	
	cin>>runs;
	for(int r = 1 ; r <= runs; r++){
		int n,m,s,e;
		cin>>n>>m>>s>>e;
		for(int i = 0; i < n ; i++) g[i].clear();
		for(int i = 0; i < m; i++){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back(Edge(v,w));
			g[v].push_back(Edge(u,w));			
		}
		int d = dijkstra(s,e,n);
		if (d != INF) 
			printf("Case #%d: %d\n",r,d);
		else 
			printf("Case #%d: unreachable\n",r);
	}

	return 0;
}
