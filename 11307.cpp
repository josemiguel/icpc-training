#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> Edge;

const int N = 10002;
const int C = 8;

vector<vector<int> > adj;
int color[C];
int dp[N][C];

int main(){
	int n;
	while(scanf("%d",&n) !=-1 && n){
	
		adj = vector<vector<int> > (n);
		
		for(int u = 0 ; u < n; u++){
			int v;
			char c;
			scanf("%d: ",&v);
			while(scanf("%d%c",&v,&c) && c!='\n'){
				adj[u].push_back(v);
				adj[v].push_back(u);
				color[u]=color[v]=0;
			}
		}
		
		for(int i = 0; i < n;i++){
			for(int j = 0; j < C; j++){
				dp[i][j] = 0;
			}
		}
		color[0] = 1;
				
		for(int u = 0 ; u < n ; u++){
			for(int i = 0; i < adj[u].size();i++){
				int v = adj[u][i];
				for(int j = 0; j < u ; j++){
					dp[u][color[j]] = min(dp[v][color[v]],dp[u][color[j]]) + color[v];
					cout<<dp[u][color[j]]<<endl;
				}						
			}
		}

	}
} 
