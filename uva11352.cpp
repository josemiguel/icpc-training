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
#define MAXN 105
using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define pq priority_queue

#define INF 1<<30
int n,m;
int dist[MAXN][MAXN];
char g[MAXN][MAXN];

int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<m && (g[x][y]!='X' && g[x][y]!='Z');
}

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int wx[] = {-1,1,2,2,1,-1,-2,-2};
int wy[] = {2,2,1,-1,-2,-2,-1,1};


int bfs(int x,int y,int xf,int yf){
	queue<int> q;
	q.push(x);q.push(y);
	memset(dist,0,sizeof(dist));
	while(!q.empty()){
		int vx = q.front(); q.pop();
		int vy = q.front(); q.pop();
		for(int i = 0; i < 8; i++){
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
	int r;
	scanf("%d",&r);
	while(r--){
		scanf("%d%d",&n,&m);
		getchar();
		int x,y,xf,yf;
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				g[i][j] = getchar();
				if (g[i][j]=='A'){
					x = i; y = j;
				}else if (g[i][j]=='B'){
					xf = i; yf = j;
				}
			}
			getchar();
		}
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m ; j++){
				if (g[i][j]=='Z'){
					for(int k = 0; k < 8; k++){
						if (in(i+wx[k],j+wy[k])){
							char c = g[i+wx[k]][j+wy[k]];
							if (c != 'A' && c != 'B' && c != 'Z')
								g[i + wx[k]][j + wy[k]] = 'X';
						}
					}
				}
			}
		}
		
		int d = bfs(x,y,xf,yf);
		if (d){
			printf("Minimal possible length of a trip is %d\n",d);
		}else{
			printf("King Peter, you can't go now!\n");
		}
		
	}
	return 0;
}
/*



*/
