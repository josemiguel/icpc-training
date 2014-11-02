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

int n = 9;
int nds;
bool B, W;
vector<string> g;
bool seen[10][10];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y){
	seen[x][y] = true;
	nds++;
	for(int i = 0; i < 4; i++){
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (xx>=0 && yy>=0  && xx < 9 && yy < 9){
			if (g[xx][yy] == 'X') B = true;
			else if (g[xx][yy] == 'O') W = true;
			
			if (!seen[xx][yy] && g[xx][yy] == '.'){
				dfs(xx,yy);
			}
		}
	}
}

int main(){
	int runs;
	cin>>runs;

	for(int r = 1 ; r <= runs ; r++){
		g = vector<string> (n,"");
		int b = 0,w = 0;		
		char c;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cin>>c;
				g[i]+=c;
				if (c == 'O') w++;
				else if (c=='X') b++;
			}
		}


		memset(seen,0,sizeof(seen));	
		for(int i = 0; i < 9;i++){
			for(int j = 0; j < 9 ;j++){
				if (g[i][j] == '.' && !seen[i][j]){
					B = W = false;
					nds = 0;
					dfs(i,j);
					if (B && !W)  b+=nds;
					else if (W && !B) w+=nds;
				}
			}
		}
		printf("Black %d White %d\n",b,w);
		
	}
	
	return 0;
}
