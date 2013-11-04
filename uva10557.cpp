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
	
	for(int r = 1 ; scanf("%d",&n) != -1 && n != -1 ; r++){
		g = vector<vector<pair<int,int> > > (n);
		for(int i = 0 ; i < n ;i++){
			int v,w;
			scanf("%d%d",&w,&m);
			if (!w && !m) break;
			for(int j = 0; j < m ;j++){
				scanf("%d",&v);
				v--;
				g[i].push_back(mp(v,w));
			}
		}
		vector<int> dist(n,-1<<20);
		vector<int> pai(n,-1);
		dist[0] = 100;
		pai[0] = -2;
		for(int i = 0; i < n ; i++){
			for(int u = 0; u < n ; u++){
				for(int j = 0; j < g[u].size(); j++){
					pair<int,int> v = g[u][j];
					dist[v.first] = max(dist[v.first],dist[u] + v.second);
					pai[u] = v.first;
				}
			}
		}
		bool nc = false;
		for(int u = 0; u < n ; u++){
			for(int j = 0; j < g[u].size(); j++){
				pair<int,int> v = g[u][j];
				if (dist[v.first] > dist[u] + v.second){
					nc = true;
				}
			}
		}
		
		if (win){
			puts("winnable");
		}else{
			puts("hopeless");
		}
	}
	
	return 0;
}

