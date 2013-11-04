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
#define MAX 105
int g[MAX][MAX];
int n,m;

int main(){

	
	for(int r = 1 ; scanf("%d",&n) && n; r++){
		
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++) 
				if (i == j) g[i][j] = 0; 
				else g[i][j] = 1<<20;
				
		for(int i = 0 ; i < m ;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			g[u][v] = g[v][u] = 1;
		}
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					g[i][j] = g[j][i] = min(g[i][j],g[i][k] + g[k][j]);
		
		int s,d;
		scanf("%d %d",&s,&d);
		int best = 0;
		for(int i = 0; i < n; i++){
			if (g[s][i] != 1<<20 && g[i][d] != 1<<20)
				best = max(best,g[s][i] + g[i][d]);
		}
		printf("Case %d: %d\n",r,best);
	}
	
	return 0;
}
