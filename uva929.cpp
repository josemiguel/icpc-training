#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int INF = 1<<30;

int g[1001][1001];
int r,n,m;
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dist[1001][1001];

struct Edge {
    int x, y;
    int w;
    Edge() {}
    Edge(int x, int y, int w) : x(x), y(y), w(w) {
    }
};

queue<Edge> q[10];
int current_q;

void enqueue(Edge e){
  q[e.w % 10].push(e);
}

bool dequeue(Edge &v){
  int started_at = current_q;
  while (q[current_q].empty()){
    current_q = (current_q + 1)%10;
    if (current_q == started_at) return false;
  }
  v = q[current_q].front();
  q[current_q].pop();
  return true;
}

int main(){
	scanf("%d",&r);
	while(r--){
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				scanf("%d",&g[i][j]);
				dist[i][j] = INF;
			}
		}
		
		for (int i=0; i<10; ++i){
			for (; q[i].size(); q[i].pop());
		}
		current_q = dist[0][0] = g[0][0];
		enqueue(Edge(0,0,g[0][0]));
		Edge v;
		while(dequeue(v)){
			if (v.x == n-1 && v.y == m-1) break;
			if (dist[v.x][v.y] < v.w) continue;
			for(int i = 0; i < 4 ; i++){
				int xx = v.x + d[i][0], yy = v.y + d[i][1];			
				if (xx >= 0 && yy >= 0 && xx < n && yy < m){
					if (dist[xx][yy] > v.w + g[xx][yy]){
						dist[xx][yy] = v.w + g[xx][yy];
						enqueue(Edge(xx,yy,dist[xx][yy]));
					}
				}
			}
		}		
		
		printf("%d\n", dist[n-1][m-1]);
	}
		
	return 0;
}

