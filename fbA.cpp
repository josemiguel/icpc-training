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
#define mp make_pvxr 
#define All(v) v.begin(),v.end()
#define INF 1<<30
#define N 150
int C,R;

struct node{
	int x, y;
	node (){}
	node (int x, int y): x(x), y(y){}
};

string g[N];
int seen[N][N];
int dist[N][N];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(node s, node e){

	int si = s.x , sj = s.y;
	int ei = e.x , ej = e.y;
	memset(dist,-1,sizeof(dist));
	queue< int > q;
	q.push(si); q.push(sj);
	dist[si][sj] = 0;
	while( !q.empty() ){

		int vx = q.front(); q.pop();
		int vy = q.front(); q.pop();

		if( vx == ei && vy == ej ) break;
		
		if( g[vx][vy] != '0' ){
			for( int xx = 0 ; xx < R ; xx++ ){
				for( int yy = 0 ; yy < C ; yy++ ){	
					if( g[vx][vy] == g[xx][yy] && dist[xx][yy] == -1){
							dist[xx][yy] = dist[vx][vy] +1;
							q.push(xx) ; q.push(yy);
					}
				}
			}
		}

		for( int i = 0 ; i < 4 ; i++ ){
			int ux = vx + dx[i], uy = vy + dy[i];
			if( ux < 0 || ux >= R || uy < 0 || uy >=C ) continue;
			if( g[ux][uy] != 'W' ){
				if( dist[ux][uy] != -1 ) continue;
				if( g[ux][uy] == '0' || g[ux][uy] == 'E' ){
					dist[ux][uy] = dist[vx][vy] + 1;
					q.push(ux); 
					q.push(uy);
				}
				else{
					q.push(ux); 
					q.push(uy);
					dist[ux][uy] = dist[vx][vy] + 1;
				}
			}
		}

		}

	return dist[ei][ej];

}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&R,&C);
		node s,e;
		for(int i = 0; i < R; i++) g[i] = "";
		for(int i = 0 ; i < R ;i++){
			cin>>g[i];
			for(int j = 0; j < g[i].size(); j++){
				if (g[i][j] == 'S'){
					s.x = i;
					s.y = j;
				}else if (g[i][j] == 'E'){
					e.x = i;
					e.y = j;
				}
			}
		}
				
		cout<<bfs(s,e)<<endl;
	}
	
	return 0;
}
