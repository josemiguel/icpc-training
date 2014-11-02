/*
*
*	UVA 657
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
#include<map>

using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()

int n,m;
vector<int> res;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char g[500][500];
inline int in(int x, int y){
	return x>=0 && y>=0 && x<m && y<n;	
}

void dfs2(int x, int y){
	g[x][y] = '*';
	for(int i = 0 ; i < 8 ; i++){
		if (g[dx[i]+x][dy[i]+y] == 'X'){
			dfs2(dx[i]+x,dy[i]+y);				
		}
	}
	
}
int cmp = 0;
void dfs(int x, int y){
	if (g[x][y] == 'X'){
		dfs2(x,y);
		cmp++;		
	}
	g[x][y] = '.';
	for(int i = 0 ; i < 8 ; i++){
		if (in(dx[i]+x,dy[i]+y)){
			if (g[dx[i]+x][dy[i]+y] != '.'){
				dfs(dx[i]+x,dy[i]+y);				
			}
		}
	}

}

int main(){
	int r = 1;	
	while(scanf("%d%d",&n,&m) && n+m){
		getchar();
		res = vector<int> ();
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n ; j++){
				g[i][j] = getchar();
			}
			getchar();
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n ; j++){
				if (g[i][j] == '*' || g[i][j] == 'X'){
					cmp = 0;
					dfs(i,j);
					res.push_back(cmp);	
				}
			}
		}
		printf("Throw %d\n", r++);
		
		if (res.size() > 0){
			sort(All(res));
			printf("%d",res[0]);
			for(int i = 1; i < res.size(); i++){
				printf(" %d",res[i]);
			}
		}
		putchar(10);
		putchar(10);		

	}	

	return 0;
}
