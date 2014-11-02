#include<iostream>
#include<cstring>
using namespace std;
int n,m;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int B;

char g[22][22];

int in (int x, int y){
	return x>=0 && x<m && y<n && y>=0;
}

int dfs(int x, int y){
	g[x][y] = '#';
	B++;
	for(int i = 0; i<  4; i++)
	{
		if (in(x+dx[i],y+dy[i])){
			if (g[x+dx[i]][y+dy[i]] == '.')
				dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main(){
	while(cin>>n>>m && n+m){
		int x,y;
		for(int i = 0; i < m ;i++){
			for(int j = 0; j < n;j++){
				cin>>g[i][j];
				if (g[i][j] == '@'){
					x = i;
					y = j;
				}
			}
		}
		B = 0;
		dfs(x,y);
		cout<<B<<endl;
		
	}
}

