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

//int g[MAX][MAX];
vector<vector<int> > g;
int n,m;
vector<int> seen;
vector<int> pai;
vector<int> top;
bool dfs(int v){
	seen[v] = 1;
	bool ok = true;
	for(int i = 0; i < g[v].size();i++){
		int u = g[v][i];
		if (seen[u]==1 && pai[u] != v) return false;
		if (!seen[u]){
			pai[u] = v;
			ok = dfs(u);
		}
	}
	seen[v] = 2;
	top.push_back(v);
	return ok;
}

bool solve(){

	seen = vector<int> (n,0);
	top = vector<int> ();
	pai = vector<int> (n,-1);

	for(int i = 0; i < n; i++){
		if (!seen[i]){
			if (!dfs(i)) return false;
		}
	}
	return true;
}



int main(){
	for(int r = 1 ; scanf("%d%d",&n,&m) && n+m; r++){
		g = vector<vector<int> > (n);

		for(int i = 0 ; i < m ;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			g[u].push_back(v);
		}

		if (!solve()){
			puts("IMPOSSIBLE");
		}else{
			for(int i = top.size()-1; i>=0; i--){
				printf("%d\n",top[i]+1);
			}
		}
		
	}
	
	return 0;
}


