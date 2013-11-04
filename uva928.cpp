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
#define MAX 355

struct node{
	int p,x,y;
	node(){}
	node(int p, int x, int y): p(p), x(x), y(y){}
};

char g[MAX][MAX];
int dist[MAX][MAX][4];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int n,m;

bool in(node u){
	return u.x>=0 && u.y>=0 && u.x<n && u.y<m;	
}

int bfs(int x, int y, int ex, int ey){
	queue<node> q;
	memset(dist,-1,sizeof(dist));
	dist[x][y][0] = 0;
	q.push(node(0,x,y));
	while(!q.empty()){
		node v = q.front();q.pop();
		for(int i = 0; i < 4; i++){
			node u;
			bool cannot = false; 
			u.p = v.p % 3 + 1;
			u.x = v.x;
			u.y = v.y;
			for(int j = 0; j < u.p ; j++){
				u.x = u.x + dx[i];
				u.y = u.y + dy[i];
				if (!in(u)) {cannot = true; break;}
				if (g[u.x][u.y] == '#') {cannot = true; break;}
			}
			if (cannot) continue;
			if (dist[u.x][u.y][u.p] != -1) continue;
			q.push(u);
			dist[u.x][u.y][u.p] = dist[v.x][v.y][v.p] + 1;
		}
	}
	
	int d = 1<<30;
	for(int i = 1; i<=3; i++)
		if (dist[ex][ey][i] != -1){
			d = min(dist[ex][ey][i],d);
		}
	return d;
	
}

int main(){
	int runs;
	cin>>runs;
	while(runs--){
		cin>>n>>m;
		int s[2],e[2];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				cin>>g[i][j];
				switch(g[i][j]){
					case 'S': 
						s[0] = i;
						s[1] = j;
						break;
					case 'E':
						e[0] = i;
						e[1] = j;
						break;
				}
			}
		}
//		cout<<"start : "<<s[0]<<" "<<s[1]<<endl;
	//	cout<<"end : "<<e[0]<<" "<<e[1]<<endl;
		int d = bfs(s[0],s[1],e[0],e[1]);
		if (d != 1<<30){
			cout<<d<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	
	}
	return 0;
}

