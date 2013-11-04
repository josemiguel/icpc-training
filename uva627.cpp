#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define MAXN 305

vector<vector<int> > g;
int pai[MAXN];
int n;

bool bfs(int ini, int fin){
	queue<int> q;
	q.push(ini);
	for(int i = 0; i < n ; i++) pai[i] = -1;
	pai[ini] = -2;
	while(!q.empty()){
		int v = q.front(); q.pop();
		if (v == fin) return true;
		for(int i = 0;  i < g[v].size(); i++){
			int u = g[v][i];
			if (pai[u] == -1){
				q.push(u);
				pai[u] = v;
			}
		}
	}
	return false;
}	

void track(int s, int e){
	if (bfs(s,e)){
		stack<int> p;
		for(int pos = e; pos != -2; pos = pai[pos]){
			p.push(pos);
		}
		printf("%d",p.top()+1);
		p.pop();
		while(!p.empty()){
			printf(" %d",p.top()+1);
			p.pop();
		}
		putchar(10);
	}else
		printf("connection impossible\n");
}

int main(){
	
	while(cin>>n){
		cin.ignore();
		g = vector<vector<int> > (n);
		for(int i = 0; i < n ;i++){
			string s; 
			getline(cin,s);
			for(int j = 0; j < s.size(); j++) s[j] = isdigit(s[j])?s[j]:' ';
			istringstream is(s);
			int u,v;
			is>>u;
			u--;
			while(is>>v){
				v--;
				g[u].push_back(v);
			}
		}
		int q,u,v;
		scanf("%d",&q);
		puts("-----");
		while(q--){
			scanf("%d%d",&u,&v);
			
			track(u-1,v-1);
		}
	}
	return 0;
}
