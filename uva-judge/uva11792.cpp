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
#define MAXN 10005

vector<vector<int> > g;

int imp[MAXN];
int dist[MAXN];
int seen[MAXN];
int n;

void bfs(int s){
	memset(dist,0,sizeof(dist));
	memset(seen,0,sizeof(seen));	
	queue<int> q;
	q.push(s);
	seen[s] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (!seen[u]){
				dist[u] = dist[v] + 1;
				seen[u] = 1;
				q.push(u);	
			}
		}
	}
}

int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		int l;
		scanf("%d %d",&n,&l);
		memset(imp,0,sizeof(imp));
		g = vector<vector<int> > (n);
		vector<int> important;
		for(int i = 0; i < l; i++){
			int v,ant = -1;
			while(scanf("%d",&v) && v){
				
				v--;
				imp[v]++;
				if (imp[v] == 2){
					important.push_back(v);
				}
				if (ant != -1) {g[v].push_back(ant);g[ant].push_back(v);}
				ant = v;
			}
		}
		sort(important.begin(),important.end());
		int avg = 1<<30;
		int est;
		for(int i = 0; i < important.size(); i++){
			bfs(important[i]);
			int drest = 0;
			for(int j = 0; j < important.size(); j++){
				drest += dist[important[j]];
			}
			if (drest < avg){
				avg = drest;
				est = important[i];
			}
		}
		printf("Krochanska is in: %d\n",est+1);
		
	}
	return 0;
}

