#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10002

struct arista{
	arista(int a, int b){dst=a;weig=b;}
	int dst;
	int weig;
};

vector<arista> aristas[MAX];

bool visited[MAX];
int dist[MAX];

void clear(int n){
	for(int i=0;i<n+1;i++) dist[i]=visited[i]=0;
}

int Max(int u, int n){
	for(int i=0;i<n+1;i++) if (dist[i] > dist[u]) u = i;
	return u;
}


void dfs(int u, int w)
{
	visited[u]=true;
	dist[u] = w;
	for(int i=0;i<aristas[u].size();i++){
		arista v = aristas[u][i];
		if (!visited[v.dst]) {
			dfs(v.dst,v.weig+w);
		}
	}
}


void diametro(int n){
	int u = 0;
	clear(n);
	dfs(0,0); //1
	u = Max(0,n);
	clear(n);
	dfs(u,0);//2
	u = Max(0,n);
	printf("%d\n",dist[u]);
}

int main(){
	string s;
	int n = 0;	
	while(getline(cin,s)){
		int u,v,w;	
		if (s !=""){
			istringstream is(s);
			is>>u>>v>>w;
			aristas[u-1].push_back(arista(v-1,w));
			aristas[v-1].push_back(arista(u-1,w));
			n=max(max(v,u),n);
		}else{
			diametro(n);
			for(int i = 0;i<MAX;i++) aristas[i].clear();
			n = 0;
		}
		
	}
}
