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

#define MAX 124
#define INF 1<<30
int f[MAX];
bool seen[MAX];

vector<vector<int> > g;
int nds;
void dfs(int u){
	seen[u] = true;
	nds++;
	for(int i = 0; i < g[u].size(); i++){
		if (!seen[g[u][i]]){
			dfs(g[u][i]);
		}
	}
}

int main(){
	int n;
	while(scanf("%d",&n) && n){
		g = vector<vector<int> > (n);

		for(int u = 0; u < n ; u++){
			int m;
			scanf("%d",&m);
			for(int i = 0; i < m ; i++){
				int v;
				scanf("%d",&v);v--;
				g[u].push_back(v);

			}
		}
		int best = 0;
		
		memset(f,0,sizeof(f));
		int i = 0;
		int low = INF;
		for(int i = 0; i < n; i++){
			memset(seen,0,sizeof(seen));
			nds = -1;
			dfs(i);
			f[i] = nds;
			best = max(nds,best);
		}
		
		for(int i = 0; i < n; i++){
			if (f[i] == best){
				printf("%d",i+1);
				break;
			}
		}
		putchar(10);
		
	}
	
	return 0;
}
