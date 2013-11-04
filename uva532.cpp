#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define MAXN 32


int seen[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
char g[MAXN][MAXN][MAXN];
int dx[] = {0 , -1 , 0 , 0 , 1 , 0};
int dy[] = {0 , 0 , -1 , 1 , 0 , 0};
int dz[] = {-1 , 0 , 0 , 0 , 0 , 1};



int L,C,R;

bool may(int x, int y, int z){
	return x>=0 && y>=0 && z>=0 && x<R && y<C && z<L && g[x][y][z]!='#';
}

int bfs(int x, int y, int z,int xf, int yf, int zf){
	queue<int> q;
	q.push(x);	q.push(y);	q.push(z);
	memset(seen,0,sizeof(seen));
	memset(dist,0,sizeof(dist));
	seen[x][y][z] = 1;
	while(!q.empty()){
		int vx = q.front();q.pop();
		int vy = q.front();q.pop();
		int vz = q.front();q.pop();
		for(int i = 0; i < 6; i++){
			int ux = vx + dx[i];
			int uy = vy + dy[i];
			int uz = vz + dz[i];
			if (may(ux,uy,uz)){
				if (!seen[ux][uy][uz]){
					q.push(ux);
					q.push(uy);
					q.push(uz);
					seen[ux][uy][uz] = 1;
					dist[ux][uy][uz] = dist[vx][vy][vz] + 1;

				}				
			}
		}
	}
	return dist[xf][yf][zf];
	
}

int main(){
	while(scanf("%d%d%d",&L,&R,&C)!=-1 && L+R+C){
		getchar();
		int x,y,z,xf,yf,zf;
		for(int k = 0; k < L; k++){
			for(int i = 0; i < R;i++){
				for(int j = 0; j < C; j++){
					g[i][j][k] = getchar();
					if (g[i][j][k]=='S'){
						x = i;
						y = j;
						z = k;	
					}else if(g[i][j][k] == 'E'){
						xf = i;
						yf = j;
						zf = k;
					}
				}
				getchar();
			}
			getchar();
		}
				
		int minutes = bfs(x,y,z,xf,yf,zf);
		if (minutes)
			printf("Escaped in %d minute(s).\n",minutes);
		else
			printf("Trapped!\n");
	}
	return 0;
}


