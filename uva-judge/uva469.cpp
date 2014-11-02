/*
*
*	UVA 469 AC
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
#define N 102

char g[102][102];
int dx[] = {0,0,1,-1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n,nds,m, pre[N][N];

inline int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;	
}

int dfs(int x, int y, int f,char m, char p){
	g[x][y] = m;
	!f?nds++:pre[x][y]=nds;//si f es 0 cuenta nodos, sino, asigna en pre el numero ya calculado
	for(int i = 0; i < 8 ; i++)
		if (in(x+dx[i],y+dy[i]))
			if (g[x+dx[i]][y+dy[i]] == p)
				dfs(x+dx[i],y+dy[i],f,m,p);
}

int main(){
	int runs;
	scanf("%d",&runs);
	getchar();getchar();
	while(runs--){
		n = 0;
		while(fgets(g[n],N,stdin) && !isdigit(g[n][0])){
			n++;
		}
		m = strlen(g[0]);
//		for(int i = 0 ; i < n; i++) for(int j = 0 ; j < m; j++) pre[i][j] = 0;
		memset(pre,0,sizeof(pre));
		//genera una matriz con los querys ya resueltos en pre
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++, nds = 0)//se inicializa el numero de nodos
				if (g[i][j] == 'W'){ //si es agua
					dfs(i,j,0,'*','W');
					dfs(i,j,1,'M','*');
				}
		
		int u,v;
		sscanf(g[n],"%d%d",&u,&v);
		do{
			printf("%d\n",pre[u-1][v-1]);
		}while(scanf("%d%d",&u,&v)==2);
		if (runs!=0) putchar(10);
	}
	return 0;
}
