#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > g;
int n;

int F(int u, int c){
	int res = 0;
	for(int K = 1; K <= 5; K++){
		if (K == c) continue;
		for(int i = 0; i < g[u].size(); i++){
			F(g[u][i],K);
			res += K;
		}
	}
	return res;
}
	
int main(){
	while(scanf("%d",&n) && n){
		int u,v;
		g = vector<vector<int> > (n);
		for(int i = 0; i < n; i++){
			char c;		
			scanf("%d:%c",&u,&c);
			if (c == '\n') continue;
			while(scanf("%d%c",&v,&c) && c != '\n')	g[u].push_back(v);
		}
		int res = 1<<30;
		for(int K = 1; K <= 5; K++){

			res = min(res,K+F(0,K));
	
		}

		printf("%d\n",res);
	}

	return 0;
}
