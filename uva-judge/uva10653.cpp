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
#define MAXN 1002
int n,m;
int g[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

int in(int x , int y){
	return x>=0 && y>=0 && x<n && y<m && !g[x][y];
}

int bfs(int x, int y, int xf, int yf){
	queue<int> q;
	q.push(x);q.push(y);
	
	memset(dist,0,sizeof(dist));
	while(!q.empty()){
		int vx = q.front(); q.pop();
		int vy = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int ux = vx + dx[i];
			int uy = vy + dy[i];			
			if (in(ux,uy)){
				if (!dist[ux][uy]){
					q.push(ux);q.push(uy);
					dist[ux][uy] = dist[vx][vy] + 1;
				}
			}
		}
	}
	return dist[xf][yf];
}



int main(){
	while(scanf("%d%d",&n,&m)!=-1 && n+m){
		memset(g,0,sizeof(g));
		int b,nb,r,c,x,y,xf,yf;
		scanf("%d",&b);
		while(b--){
			scanf("%d%d",&r,&nb);
			while(nb--){
				scanf("%d",&c);
				g[r][c] = 1;
			}
		}
		scanf("%d%d%d%d",&x,&y,&xf,&yf);
		printf("%d\n",bfs(x,y,xf,yf));
		
	}

	return 0;
}
