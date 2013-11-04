#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool usd[105];
vector<vector<int> > g;
int dfs(int u){ 
	usd[u] = true;
	int res = 1;
	for(int i = 0; i < g[u].size() ; i++){
		int v = g[u][i];
		if (!usd[v]){
			res = max ( res, 1 + dfs( v ) );
		}
	}
	return res;
}

int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		int n;
		scanf("%d",&n);
		int inicios[n],fines[n];
		for(int i  = 0; i < n; i++)	scanf("%d",&inicios[i]);
		for(int i  = 0; i < n; i++) scanf("%d",&fines[i]);
		
		g = vector<vector<int> > (n);	
		
		for(int i = 0; i < n; i++){
			int ini = inicios[ i ], fin = fines[ i ];
			for(int j = 0; j < n; j++){
				if ( i == j ) continue;
				int pto = inicios[ j ];
				if ( pto >= ini && pto < fin) g[i].push_back(j), g[j].push_back(i);
			}
		}
		int res = 1;
		for(int i = 0; i < n; i++){
			memset(usd, 0 ,sizeof usd);
			res = max( res, dfs( i ) );
		}
		printf("%d\n",res);

	}
	return 0;
}

