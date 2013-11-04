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
#define MAX 10024

vector<vector<int> > g;
int seen[MAX];
int nds;
void dfs(int z){
	nds++;
	seen[z] = true;
	for(int i = 0; i < g[z].size(); i++){
		if (!seen[g[z][i]]){
			dfs(g[z][i]);
		}
	}
}

int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1 ; r <= runs ; r++){
		int n,m,l;
		scanf("%d%d%d",&n,&m,&l);
		g = vector<vector<int> > (n);
		
		for(int i = 0; i < m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--; v--;
			g[u].push_back(v);
		}
		memset(seen,0,sizeof(seen));
		nds = 0;
		for(int i = 0; i < l; i++){
			int z;
			scanf("%d",&z);
			z--;
			if (!seen[z])
				dfs(z);
		}
		printf("%d\n",nds);
	}
	
	return 0;
}
