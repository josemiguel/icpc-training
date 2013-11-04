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
#define MAX 10

bool b[MAX][MAX][MAX][MAX];

struct node{
	int x, y;
	node(){ x = y = -1;}
	node(int x, int y) : x(x), y(y){}
};

int n,m;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

char ori(node a, node b){
	if (a.x > b.x && a.y == b.y) return 'W';
	if (a.x < b.x && a.y == b.y) return 'E';
	if (a.x == b.x && a.y > b.y) return 'N';
	if (a.x == b.x && a.y < b.y) return 'S';
	return '_';
}

int main(){
	int sx,sy,ex,ey;
	for(int r = 1 ; scanf("%d%d",&sx,&sy) && sx+sy ; r++){
		scanf("%d%d",&ex,&ey);
		node s(sx,sy);
		node e(ex,ey);
		memset(b,0,sizeof(b));
		for(int i = 0; i < 3;i++){
			int x,y,xx,yy;
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			if (y == yy){
				for(int i = x+1; i<=xx; i++){
					b[i][y][i][y+1] = b[i][y+1][i][y] =true;
				}
			}
			if (x == xx){
				for(int i = y+1; i<=yy; i++){
					b[x][i][x+1][i] = b[x+1][i][x][i] = true;
				}	
			}

		}
		queue<node> q;
		q.push(s);

		node pai[MAX][MAX];
		bool seen[MAX][MAX];
		memset(seen,0,sizeof(seen));
		pai[s.x][s.y] = node(-2,-2);
		seen[s.x][s.y] = 1;
		while(!q.empty()){

			node v = q.front();q.pop();
			if (v.x == e.x && v.y == e.y) break;
			for(int i = 0; i < 4; i++){
				node u(v.x + dx[i], v.y + dy[i]);
				
				if (u.x >= 1 && u.x <= 6 && u.y >= 1 && u.y <= 6){
					if (seen[u.x][u.y]) continue;
					if (b[v.x][v.y][u.x][u.y]) continue;
					seen[u.x][u.y] = true;
					pai[u.x][u.y] = v;
					q.push(u);
				}
			}
		}


		vector<node> path;
		for(node pos = e; pos.x != -2 && pos.y != -2; pos = pai[pos.x][pos.y]){
			path.push_back(pos);
		}

		node ant = path[path.size() - 1];
		string sp = "";		
		for(int i = path.size() - 2; i >= 0; i--){
			sp += ori(ant,path[i]);
			ant = path[i];
		}
		cout<<sp<<endl;
	}
	
	return 0;
}


