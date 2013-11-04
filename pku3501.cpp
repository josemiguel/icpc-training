#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second

int DIST(int x1,int y1,int x2,int y2){
     return abs((double)x1-x2) + abs((double)y1-y2);
}

int dx[]= {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool usd[1005][1005];

int d[1005][1005];
int d2[1005][1005];
int n,m,sx,sy,ex,ey,q;

pii Q[1000000]; 

int go(){
	int l = 0, h = 0;
	memset(d,-1,sizeof d);
	memset(usd,0,sizeof usd);
	
	for(int i = 0; i < q; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		pii t(a,b);
		Q[h++] = t;
		d[t.x][t.y] = usd[t.x][t.y] = 0;
	}

	int res = 0;

	while(l < h){
		pii v = Q[l++]; 
		for(int i = 0; i < 4; i++){
			pii u = v;
			u.x += dx[i];
			u.y += dy[i];
			if (u.x < 0 || u.y < 0 || u.x >= n || u.y >= m) continue;
			if (usd[u.x][u.y]) continue;
			usd[u.x][u.y] = true;
			d[u.x][u.y] = d[v.x][v.y] + 1;			
			if(d[u.x][u.y] > res) res = d[u.x][u.y];
			Q[h++] = u;
		}
	}
	return res;
}

int bfs(int sep){
	if (d[sx][sy] < sep) return 1<<30;
	int l = 0, h = 0;
	Q[h++] = mp(sx,sy);
	memset(usd,0,sizeof usd);	
	usd[sx][sy] = true; 
	d2[sx][sy] = 0;
	while(l<h){
		pii v = Q[l++]; 
		for(int i = 0; i < 4; i++){
			pii u = v;
			u.x += dx[i];
			u.y += dy[i];
			if (u.x == ex && u.y == ey) return d2[v.x][v.y]+1;
			if (u.x < 0 || u.y < 0 || u.x >= n || u.y >= m) continue;
			if (usd[u.x][u.y] || d[u.x][u.y] < sep) continue;

			usd[u.x][u.y] = true;
			d2[u.x][u.y] = d2[v.x][v.y] + 1;
			Q[h++] = u;
		}
	}
	return 1<<30;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	while(runs--){
		int A = -1,B = -1;
		scanf("%d%d%d",&q,&n,&m);
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		
		int lo = 0, hi = go();
		while(lo <= hi){
			int mid = (lo+hi)/2;
			int BFS = bfs(mid);
			if (BFS != 1<<30){
				B = BFS;
				A = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
				
		printf("%d %d\n",A,B);
	}

	return 0;
}


