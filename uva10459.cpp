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

int n;

vector<vector<int> > g;
vector<int> h;
vector<int> seen;
int heigth(int u){
	int hei = 0;
	vector<int> dist(n+1,0);
	queue<int> q;
	q.push(u);
	seen[u] = 1;	
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < g[v].size(); i++){
			if (!seen[g[v][i]]){
				dist[g[v][i]] = dist[v] + 1;
				hei = max(dist[g[v][i]],hei);
				q.push(g[v][i]);
				seen[g[v][i]] = 1;
			}
		}
	}
	return hei;
}

int maxh,minh;
void solve(){
	
	for(int i = 0; i < n ;i++){
		seen = vector<int> (n,0);
		
		h[i] = heigth(i);
		maxh = max(h[i],maxh);
		minh = min(h[i],minh);

	}
}

int main(){
	while(scanf("%d",&n)!=-1){
		g = vector<vector<int> > (n);
		h = vector<int> (n,0);
		for(int i = 0 ; i < n ;i++){
			int m,v;
			scanf("%d",&m);
			for(int j = 0; j < m; j++){
				scanf("%d",&v);v--;
				g[i].push_back(v);
			}
		}
		maxh = 0;
		minh = INF;
		solve();		
		printf("Best Roots :");
		for(int i = 0 ; i < n;i++){
			if (minh == h[i])
				printf(" %d",i+1);
		}
		putchar(10);
		printf("Worst Roots :");
		for(int i = 0; i < n; i++){
			if (maxh == h[i]){
				printf(" %d",i+1);
			}	
		}		
		putchar(10);		
	}
	
	return 0;
}
