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
#define BLACK 2
#define WHITE 1
int color[MAX];

vector<vector<int> > g;
vector<int> nds;
vector<int> bestnds;
int n,m;
int res;
void solve(int curr, int opt){
	if (curr == n){
		if (opt > res){
			res = opt;
			for(int i = 0; i < n; i++){
				if (color[i] == BLACK){
					nds.push_back(i+1);
				}
			}
			bestnds = nds;
			nds.clear();
		}
		return;
	}
	bool ciclo = 0;
	for(int i = 0; i < g[curr].size(); i++){
		int u = g[curr][i];
		if (color[u] == BLACK) ciclo = 1;
	}
	if (!ciclo){
		color[curr] = BLACK;
		solve(curr+1,opt+1);
		color[curr] = 0;
	}
	//blancos o negros puede ser cualquiera
	color[curr] = WHITE;
	solve(curr+1,opt);
	color[curr] = 0;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		g = vector<vector<int> > (n);
		for(int i = 0 ; i < m ;i++){
			int v,u;
			scanf("%d %d",&u,&v);
			u--,v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		res = 0;
		memset(color,0,sizeof(color));
		solve(0,0);
		cout<<res<<endl;
		for(int i = 0; i < bestnds.size(); i++){
			if (i!=0) cout<<" ";
			cout<<bestnds[i];
		}
		cout<<endl;
	}
	
	return 0;
}
