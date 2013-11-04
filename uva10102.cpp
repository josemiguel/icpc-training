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
#define mp make_pair 
#define x first
#define y second
typedef pair<int,int> pii;


int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main(){
	int n ;

	while(scanf("%d",&n)!=-1){
		char g[n][n];
		vector<pii> unos;
		getchar();
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < n ; j++){
				g[i][j] = getchar();
				if (g[i][j]=='1'){
					unos.push_back(mp(i,j));
				}
			}
			getchar();
		}
		
		//bfs
		int dist[n+1][n+1];
		int best = -1;
		for(int i = 0 ; i < unos.size(); i++){
			queue<pii> q;
			q.push(unos[i]);
			memset(dist,0,sizeof(dist));
			int low = 1<<30;
			while(!q.empty()){
				pii v = q.front();q.pop();
				for(int j = 0; j < 4 ; j++){
					pii u = mp(v.x+dx[j],v.y+dy[j]);
					if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < n)
						if (!dist[u.x][u.y]){
							q.push(u);
							dist[u.x][u.y] = dist[v.x][v.y] + 1;
							if (g[u.x][u.y] == '3') low = min(dist[u.x][u.y],low);
						}
				}
			}
			
			best = max(best,low);
		}
		printf("%d\n",best);
	}
	return 0;
}
