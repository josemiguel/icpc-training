#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define MAX 1024
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
stack<int> path;

int dijkstra(int start,int end, int n){
    priority_queue<Edge, vector<Edge>, greater<Edge> > q;
	vector<int> d(n+1,INF);
	vector<int> pai(n+1,-1);
	q.push(Edge(start,0));
	d[start] = 0;
	pai[start] = -2;
	
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
				pai[u] = v;
				q.push(Edge(u,d[u]));
			}
		}
	}
	
	for(int pos = end; pos != -2; pos = pai[pos]){
		path.push(pos);
	}
	return d[end];
}

int main(){
	int n;	
	for(int r = 1 ;cin>>n && n; r++){

		for(int i = 0; i < n ; i++) g[i].clear();
		for(int u = 0; u < n ; u++){
			int e;
			cin>>e;
			while(e--){
				int v,w;
				cin>>v>>w;
				v--;
				g[u].push_back(Edge(v,w));
			}
		}
		int e,s;
		cin>>s>>e;
		s--; e--;
		int d = dijkstra(s,e,n);
		printf("Case %d: Path =",r);
		while(!path.empty()){ printf(" %d",path.top()+1); path.pop();}
		printf("; %d second delay\n",d);
	}

	return 0;
}
