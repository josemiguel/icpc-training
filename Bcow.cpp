#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int dist[1005];

vector<int> sacaFactores(int n){
	vector<int> res;
	int N = n;
	for(int i = 2; i*i <= n; i++){
		int a = -1;
		while(n % i == 0){
			a = i;
			n /= i;
		}
		if (a != -1) res.push_back(i);
	}
	if (n != 1 && n != N) res.push_back(n);
	return res;
}

int main(){

	int n,m;
	int r = 1;
	while(scanf("%d%d",&n,&m) != -1 && n+m){
		memset(dist,-1,sizeof dist);
		queue<int> Q;
		Q.push(n);
		dist[n] = 0;
		while(!Q.empty()){
			int v = Q.front();Q.pop();
			if (v == m)  break;
			vector<int> factores = sacaFactores(v);
			for(int i = 0; i < factores.size(); i++){
				int u = v + factores[i];
				if (u > m) continue;
				else{
					if (dist[u] == -1){
						dist[u] = dist[v] + 1;
						Q.push(u);
					}
				}
			}
		}
		printf("Case %d: %d\n",r++,dist[m]);
			
	}
	return 0;
}
