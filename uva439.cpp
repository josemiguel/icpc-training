#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;

int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};

int d[65][65];

bool in(pii u){
	return u.x >=0 && u.y >=0 && u.x<8 && u.y<8;
}

bool seen[65][65];

int bfs(pii ini, pii fin){
	queue<pii > q;
	memset(seen,0,sizeof(seen));
	memset(d,0,sizeof(d));	
	q.push(ini);
	seen[ini.x][ini.y] = 1;
	while(!q.empty()){
		pii v = q.front();q.pop();
		if (v==fin) return d[fin.x][fin.y];
		for(int i = 0; i < 8 ; i++){
			pii u = mp(v.x+dx[i],v.y+dy[i]);
			if (in(u)){
				if (!seen[u.x][u.y]){
					seen[u.x][u.y] = 1;
					d[u.x][u.y] = d[v.x][v.y] + 1;
					q.push(u);
				}
			}
		}
	}
	return 0;
}

int main(){
	char a,b,c,d,e;
	while(scanf("%c%c%c%c%c",&a,&b,&c,&d,&e)!=-1){
		getchar();
		printf("To get from %c%c to %c%c takes %d knight moves.\n",a,b,d,e,bfs(mp(a-'a',b-'1'),mp(d-'a',e-'1')));
	}
	return 0;
}
