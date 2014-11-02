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
#define MAX
//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;
vector<vector<pair<int,int> > > g;
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		g = vector<vector<pair<int,int> > > (n);
		for(int i = 0 ; i < m ;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(mp(v,w));
		}
		vector<int> dist(n,1<<20);
		for(int i = 0; i < n ; i++){
			for(int u = 0; u < n ; u++){
				for(int j = 0; j < g[u].size(); j++){
					pair<int,int> v = g[u][j];
					dist[v.first] = min(dist[v.first],dist[u] + v.second);
				}
			}
		}
		bool backTime = false;
		for(int u = 0; u < n ; u++){
			for(int j = 0; j < g[u].size(); j++){
				pair<int,int> v = g[u][j];
				if (dist[v.first] > dist[u] + v.second){
					backTime = true;
					break;
				}
			}
		}
		if (backTime){
			puts("possible");
		}else{
			puts("not possible");
		}
	}
	
	return 0;
}
