#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 550

vector<char> vv;
vector<vector<char> > g;
char res[MAX];
int seen[MAX];
int n,t;
void dfs(int u){
	seen[u] = true;
	for(int i = 0; i < g[u].size();i++){
		int v = g[u][i];
		if (!seen[v]) dfs(v);
	}
}

void topsort(char u){
	seen[u] = 1;

	for(int i = 0; i < g[u].size();i++){
		if (!seen[g[u][i]]){
			topsort(g[u][i]);
		}
	}
	res[t--] = u;
	if (t == 0){
		for(int i = 1; i <= n; i++){
			printf("%c ",res[i]);
		}
		putchar(10);
	}
	
}

int main(){
	string s;
	while(getline(cin,s)){
		istringstream is(s);
		char c,u,v;
		vv = vector<char> ();
		
		while(is>>c){
			vv.push_back(c);
		}
		n = vv.size();
		g = vector<vector<char> > (n);
		getline(cin,s);
		istringstream os(s);
		while(os>>u>>v){
			g[u].push_back(v);
		}
		memset(seen,0,sizeof(seen));		
		for(int i = 0; i < n; i++){
			if (!seen[vv[i]]){
				dfs(vv[i]);
				g[0].push_back(vv[i]);
			}
		}
		memset(seen,0,sizeof(seen));
		t = n;
		for(int i = 0; i < vv.size(); i++){
			topsort(vv[i]);
		}

	}
	
	return 0;
}
