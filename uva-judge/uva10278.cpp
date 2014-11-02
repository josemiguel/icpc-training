/*
*
*	UVA 10278 AC
*
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

const int INF = 1<<30;

struct Edge {
    int src, dest;
    int w;
    Edge() {}
    Edge(int src, int dest, int w) : src(src), dest(dest), w(w) {
    }
};

bool operator>(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


int dijkstra(Graph& g, vector<bool>& fires) {
    int n = g.size();

    priority_queue<Edge, vector<Edge>, greater<Edge> > q;
    for(int i = 0; i < n; i++)
        if (fires[i])
            q.push(Edge(-1, i, 0));

    vector<int> dist(n, INF);

    while(!q.empty()) {
        Edge e = q.top();
        q.pop();

        if (dist[e.dest] == INF) {
            dist[e.dest] = e.w;
            Edges& v = g[e.dest];
            for(int i = 0; i < v.size(); i++) {
                Edge& f = v[i];
                if (dist[f.dest] == INF) {
                    q.push(Edge(f.src, f.dest, e.w + f.w));
                }
            }
        }
    }
    int best = -INF;
	for(int i = 0; i < dist.size() ; i++){
		if (dist[i] > best){
			best = dist[i];
		}
	}
    return best;
}



int main() {
    int runs;
    scanf("%d",&runs);

    for(int i = 0; i < runs; i++) {
        if (i > 0)
            printf("\n");
		int nFires, n;
		scanf("%d%d", &nFires, &n);
		vector<bool> fires(n, false);
		Graph g(n);
		for(int i = 0; i < nFires; i++) {
		    int a;
		    scanf("%d", &a);
		    a--;
		    fires[a] = true;
		}

		char line[100];
		fgets(line,100,stdin);
		while(fgets(line,100,stdin) && line[0]!='\n') {
		    int a, b, w;
		    sscanf(line, "%d%d%d", &a, &b, &w);
		    a--; b--;
		    g[a].push_back(Edge(a, b, w));
		    g[b].push_back(Edge(b, a, w));
		}

		int k = 0;
		int best = INF;

		for(int i = 0; i < n; i++) {
		    if (!fires[i]) {
		        fires[i] = true;
		        int value = dijkstra(g, fires);
		        if (value < best) {
		            best = value;
		            k = i;
		        }
		        fires[i] = false;
		    }
		}

		printf("%d\n", k+1);
    }

    return 0;
}

