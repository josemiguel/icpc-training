/*
*
*	UVA 572 AC
*
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define N 102

int dx[] = {0,0,1,-1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n,m;
char g[N][N];

inline int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;	
}

void dfs(int x, int y){
	g[x][y] = '*';
	for(int i = 0 ; i < 8 ; i++){
		if (in(dx[i]+x,dy[i]+y)){
			if (g[dx[i]+x][dy[i]+y] == '@'){
				dfs(dx[i]+x,dy[i]+y);				
			}
		}
	}
}

int main(){
	int c = 1;
	while(scanf("%d%d",&n,&m)!=-1 && n+m){
		getchar();
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m ; j++){
				g[i][j] = getchar();
			}
			getchar();
		}
		
		int cmp = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if (g[i][j] == '@'){
					dfs(i,j);
					cmp++;
				}
			}
		}
		
		printf("%d\n",cmp);
		
	}
	return 0;
}
