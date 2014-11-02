/*
*
*	UVA 352 AC
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
#define N 27

int dx[] = {0,0,1,-1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n;
int g[N][N];

inline int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;	
}

void dfs(int ux, int uy){
	for(int i = 0 ; i < 8 ; i++){
		if (in(dx[i]+ux,dy[i]+uy)){
			if (g[dx[i]+ux][dy[i]+uy] == 1){
				g[dx[i]+ux][dy[i]+uy] = 2;
				dfs(dx[i]+ux,dy[i]+uy);				
			}
		}
	}
}

int main(){
	int c = 1;
	while(scanf("%d",&n)!=-1 && n){
		getchar();
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < n ; j++){
				char c = getchar();
				g[i][j] = c - '0';
			}
			getchar();
		}
		
		int cmp = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if (g[i][j] == 1){
					dfs(i,j);
					cmp++;
				}
			}
		}
		
		printf("Image number %d contains %d war eagles.\n",c++,cmp);
		
	}
	return 0;
}
