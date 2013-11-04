#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 102
using namespace std;

int cost[MAX];
bool visited[MAX];

vector<vector<int> > g;


void DFS(int u, int w){
	cost[u] = w;
	cout<<u<<": "<<w<<endl;
	visited[u] = true;
	for(int i = 0; i<g[u].size();i++)
	{
		int v = g[u][i];
		if (!visited[v]){
			DFS(v, w + cost[v]);
		}
	}
}

int main(){

	int n;
	int c = 1;
	while(scanf("%d",&n) && n){
		
		memset(visited,0,sizeof(visited));
		memset(cost,0,sizeof(cost));		
		g = vector<vector<int> > (n);
		int u;
		scanf("%d",&u);
		u--;
		int org,dst;
		while(scanf("%d %d",&org,&dst) && org+dst){
			g[org-1].push_back(dst-1);
			//g[dst-1].push_back(org-1);
			cost[org-1] = 1;
			cost[dst-1] = 1;
		}
		DFS(u,0);	
		int best = u;
		for(int i = 0; i < n;i++){
			if (cost[best] < cost[i]){
				best = i;
			}else if (cost[best] == cost[i]){
				best = min(best,i);
			}
		}
		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",c++,u+1,cost[best],best+1);
	}	
	
	
}
