#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int n,m;

vector<vector<int> > g;
int p[55],F[55],C[55][55];
bool exist[55][55];

int path(int s, int t){
	for(int i = 0; i < n; i++) p[i] = -1,F[i] = 1<<30;
	queue<int> Q;
	Q.push(s);
	p[s] = -2;
	while(!Q.empty()){
		int v = Q.front();Q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (p[u] != -1) continue;
			if (C[v][u] == 0) continue;
			p[u] = v;
			F[u] = min(F[v],C[v][u]);
			Q.push(u);
		}
	}

	if (p[t] == -1) return 0;
	int f = F[t];
	for(int cur = t; cur != -2; cur = p[cur]){
		int pai = p[cur];
		C[cur][pai] -= f;
		C[pai][cur] += f;
	}
	return f;
}

int max_flow(int s, int t){
	int f = 0, res = 0;
	do{
		f = path(s,t);
		res += f;
	}while(f);
	return res;
}


void min_cut(int s , int t) {
	for(int u = 0; u < n; u++){
		for(int j = 0; j < g[u].size(); j++){
			int v = g[u][j];
			if( p[v] == -1 && p[u] != -1 ){
				printf("%d %d\n",u+1,v+1);
			}
		}
	}
	putchar(10);	
}


int main(){
	while(scanf("%d %d",&n,&m) && n+m){
		g = vector<vector<int> > (n);
		memset(C,0,sizeof C);
		memset(exist,0,sizeof exist);		
		for(int i = 0; i < m ; i++){
			int c,u,v;
			scanf("%d %d %d",&u,&v,&c);
			u--,v--;
			C[u][v] += c;
			C[v][u] += c;			
			if (exist[u][v]) continue;
			exist[u][v] = exist[v][u] = 1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		max_flow(0,1);
		min_cut(0,1);

	}
	
	return 0;
}
