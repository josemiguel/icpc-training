/**
*
*	UVA 260 --
*
**/
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
#define N 205
int n;

char g[N][N];
char res;
int dx [] = {-1, -1, 0, 0, 1, 1};
int dy [] = {-1, 0, -1, 1, 0, 1};


inline int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;	
}

void dfs (int x, int y, char c)
{
	if (y == n-1 && g[x][y] == 'w') {res = 'W'; return; }
	if (x == n-1 && g[x][y] == 'b') {res = 'B'; return; }
	g[x] [y] = 'V';
	for (int i = 0; i < 6; i++)
		if (in(x+dx[i],y+dy[i]))
			if (g[x+dx[i]][y+dy[i]] == c)
				dfs(x+dx[i],y+dy[i],c);
	
}

int main() {
	int r = 0;

	while (scanf ("%d", &n) && n) {
		for(int i = 0; i < n; i++) scanf("%s",g[i]);
		for(int i = 0; i < n; i++)
			if (g[0] [i] == 'b') 
				dfs(0,i,'b');
		for(int i = 0; i < n; i++)
			if (g[i] [0] == 'w') 
				dfs(i,0,'w');
		printf("%d %c\n",++r,res);
	}

	return 0;
}


