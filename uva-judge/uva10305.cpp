#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<list>
using namespace std;
#define N 102

vector<vector<int> > g;
list<int> tops;
int visited[N];

int dfs_visit(int v){
	visited[v]=1;
	for(int i = 0;  i < g[v].size() ; i++){
		int u = g[v][i];
		if (!visited[u]) dfs_visit(u);
	}
	tops.push_front(v);
}

void dfs(int n){
	memset(visited,0,sizeof(visited));
	for(int v = 1 ; v <= n; v++)
		if (!visited[v]) dfs_visit(v);
}

int main(){
	int n,m;
	while(cin>>n>>m && n+m){
		g = vector<vector<int> > (n+1);
		while(m--){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		tops = list<int> ();

		dfs(n);
		if(tops.size() > 0){
			list<int>::iterator i = tops.begin();
			printf("%d",*i);			
			i++;
			for(; i != tops.end() ; i++){
				printf(" %d",*i);
			}
			putchar(10);
		}
		
		
	}
	

	return 0;
}
