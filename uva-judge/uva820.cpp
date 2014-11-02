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
#define INF 1<<20
#define MAX 1002

int res[MAX][MAX],mf,f,s,t;
vector<int> pai;
int n,m;
void augment(int v, int minEdge){
	if (v == s) {f = minEdge; return;}
	else if (pai[v] != -1) {
		augment(pai[v],min(minEdge,res[pai[v]][v]));
		res[pai[v]][v] -= f;
		res[v][pai[v]] += f;
	}
}

int main(){
	int r = 1;
	while(scanf("%d",&n) && n){
		int c;
		scanf("%d%d%d",&s,&t,&c);
		s--;t--;
		int u,v,w;
		memset(res,0,sizeof(res));
		for(int i = 0; i < c; i++){
			scanf("%d%d%d",&u,&v,&w);
			u--;v--;
			res[u][v] += w;
			res[v][u] += w;			
		}
		mf = 0;
		while(1){
			f = 0;
			queue<int> q;
			vector<int> dist(n+1,INF);
			q.push(s);
			dist[s] = 0;
			pai = vector<int> (n+1,-1);
			while(!q.empty()){
				int u = q.front();q.pop();
				if (u == t) break;
				for(int v = 0; v < n; v++){
					if (res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						pai[v] = u;
					}
				}
			}
			
			augment(t,INF);

			if (f == 0) break;
			mf += f;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",r++,mf);
	}
	
	
}
