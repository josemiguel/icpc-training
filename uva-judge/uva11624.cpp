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
#define INF 1<<30
#define MAX 1024
char g[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
//vector<vector<int> > g;
int n,m;

struct node{
	int x, y; char c;
	node(){}
	node(int x, int y,char c): x(x), y(y), c(c){}
};

int main(){
	int runs;
	cin>>runs;
	
	for(int r = 1 ; r <= runs ; r++){
		cin>>n>>m;

		int ij,jj;
		for(int i = 0 ; i < n ;i++){
			for(int j = 0; j < m; j++){
				cin>>g[i][j];
				if (g[i][j] == 'J'){
					ij = i;
					jj = j;
				}
			}
		}
		queue<node> q;
		memset(dist,-1,sizeof(dist));		
		q.push(node(ij,jj,'J'));
		dist[ij][jj] = 0;
		for(int i = 0 ; i < n ;i++){
			for(int j = 0; j < m; j++){
				if (g[i][j] == 'F'){
					q.push(node(i,j,'F'));
				}
			}
		}		
		
		int res = -1;
		while(!q.empty()){
			node v = q.front();q.pop();
			if (v.c == 'J' && g[v.x][v.y] == 'F') continue;
			if (v.x == 0 || v.x == n-1 || v.y == 0 || v.y == m-1) {
				if (v.c == 'J')	{res = dist[v.x][v.y]; break;}
			}
			for(int i = 0; i < 4; i++){
				node u(v.x + dx[i], v.y + dy[i],0);
				if (u.x < 0 || u.x >= n || u.y < 0 || u.y >= m) continue;
				u.c = g[u.x][u.y];
				if (v.c == 'J' && u.c == '.'){
					if (dist[u.x][u.y] == -1){
						dist[u.x][u.y] = 1 + dist[v.x][v.y];
						u.c = 'J';
						q.push(u);
					}
				}else if (v.c == 'F' && u.c == '.'){
					g[u.x][u.y] = 'F';
					u.c = 'F';
					q.push(u);
				}
			}
		}
		if (res != -1){
			printf("%d\n",res+1);
		}else{
			puts("IMPOSSIBLE");
		}

	}
	
	return 0;
}
