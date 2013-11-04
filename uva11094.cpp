#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;
char g[25][25];
char land;
bool usd[25][25];
int nds;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
void dfs(int x, int y){
	usd[x][y] = true;
	nds++;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (yy == -1) yy = m-1;
		else if (yy == m) yy = 0;
		if (xx < 0 || xx >= n) continue;
		if (usd[xx][yy]) continue;
		if (g[xx][yy] != land) continue;
		dfs(xx,yy);
	}
}

int main(){
	
	

	while(cin>>n>>m){
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>g[i][j], g[i][j] = tolower(g[i][j]);
		memset(usd,0,sizeof usd);
		int a,b;
		cin>>a>>b;
		land = g[a][b];		
		dfs(a,b);
		
		int res = 0;
		for(int i = 0 ; i < n; i++) for(int j = 0; j < m; j++) {
			if (g[i][j] != land) continue;
			if (usd[i][j]) continue;
			nds = 0;
			dfs(i,j);
			res = max(res, nds);
		}
		cout<<res<<endl;
	}
	
	return 0;
}
