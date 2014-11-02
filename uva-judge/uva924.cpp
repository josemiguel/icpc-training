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
#define MAX 2505

int n,m;
vector<vector<int> > g;
int dia,cant;
int dist[MAX];
int seen[MAX];
int emp[MAX];

void bfs(int src){
	memset(dist,0,sizeof(dist));
	memset(seen,0,sizeof(seen));	
	memset(emp,0,sizeof(emp));
	queue<int> q;
	q.push(src);
	seen[src] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (!seen[u]){
				dist[u] = dist[v] + 1;
				emp[dist[u]]++;	
				if (emp[dist[u]] > cant){
					cant = emp[dist[u]];
					dia = dist[u];
				}
				seen[u] = true;
				q.push(u);
			}
		}
	}
}

int main(){
	cin>>n;
	g = vector<vector<int> > (n);
	for(int i = 0; i < n ; i++){
		cin>>m;
		for(int j = 0; j < m ; j++){
			int v;
			cin>>v;
			g[i].push_back(v);
		}
	}
	int t,src;
	cin>>t;
	while(t--) {
		cin>>src;
		cant = dia = 0;
		bfs(src);
		if(g[src].size() != 0)
			cout<<cant<<" "<<dia<<endl; 
		else 
			cout<<0<<endl;
	}
	
	return 0;
}
