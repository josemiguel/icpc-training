#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 10005
#define mp make_pair
vector<pair<int,int> > g[MAX];
bool usd[MAX];
long long dfs(int u){
	usd[u] = true;
	long long res=0;
	for(int i = 0;i < g[u].size();i++){
		int v=g[u][i].first;
		int w=g[u][i].second;
		if(!usd[v]){
			res=max(res,dfs(v)+w);
		}
	}
	return res;
}

int main(){
	bool sale=false;
	while(!sale){
		for(int i=0; i<MAX;i++) g[i].clear(), usd[i]=false;
		int n=0;		
		while(1){
			string s;
			if(!getline(cin,s)) {sale=true;break;}
			if (s=="") break;
			int u,v,w;
			istringstream is(s);
			is>>u>>v>>w;
			g[u].push_back(mp(v,w));
			g[v].push_back(mp(u,w));
			n = max(n,max(u,v));
			u--,v--;
		}
		long long res=0LL;
		for(int i =0;i<n;i++){
			memset(usd,0,sizeof usd);
			res=max(res,dfs(i));
		}
		cout<<res<<endl;
	}
}
