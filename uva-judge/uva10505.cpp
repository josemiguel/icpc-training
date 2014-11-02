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

#define MAX 10000
int color[MAX];
bool seen[MAX];
vector<vector<int> > g;


int bfs(int s){
	memset(color,0,sizeof(color));
	queue<int> q;
	q.push(s);
	color[s] = 5;
	seen[s] = true;
	int nodos = 0;
	bool t = false;
	while(!q.empty()){
		nodos++;
		int v = q.front();q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (!color[u] && !seen[u]){
				color[u] = -color[v];
				seen[u] = true;
				q.push(u);
			}else if (color[u] == color[v]) t = true;
		}
	}
	if (t) return 0;
	return nodos;
}

int solve(int n){
	memset(seen,false,sizeof(seen));
	int best = 0;
	for(int i = 0; i < n; i++){
		if (!seen[i]){
			if (!bfs(i)) continue;
			int a = 0 ,b = 0;
			for(int j = 0; j < n; j++){
				if (color[j] > 0) a++;
				else if (color[j] < 0) b++;
			}

			best += max(a,b);
		}
	}
	return best;
}

int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1 ; r <= runs ; r++){
		int n;
		scanf("%d",&n);
		g = vector<vector<int> > (MAX);
		for(int i = 0 ; i < n ; i++){
			int m;
			scanf("%d",&m);
			while(m--){
				int v;
				scanf("%d",&v);
				v--;
				g[i].push_back(v);
				g[v].push_back(i);		
			}
		}

		printf("%d\n",solve(n));
	}
	
	
	return 0;
}
