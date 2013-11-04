#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dist[10005];
int usd[10005];
vector<vector<int> > g;
void dfs(int u ){
 
	usd[u] = true;
	
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (!usd[v]){
			dist[v] = dist[u] + 1;
			dfs(v);
		}
	}
}


vector<pair<int,int> > p;

int main(){
	int n;
	while (cin >> n && n != -1){
		g = vector<vector<int> > (n);
		for(int i = 0; i < n-1; i++){
			int u;
			cin >> u;
			u--;
			g[u].push_back(i+1);
			g[i+1].push_back(u);
		}

		dfs(0);
		int far = 0;
		memset(dist,0,sizeof dist);
		memset(usd,0,sizeof usd);
		for(int i = 0; i < n; i++){
			if ( dist[i] > dist[far]){
				far = i;
			}
		}

		memset(usd,0,sizeof usd);
		memset(dist,0,sizeof dist);
		
		dfs(far);

		far = 0;
		for(int i = 0; i < n; i++){
			if ( dist[i] > dist[far]){
				far = i;
			}
		}
		if ( dist[far] == 3) cout << 2 <<endl;
		else cout << dist[far] / 2  << endl;
	}

	return 0;
}
