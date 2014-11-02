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
int n,m;
char g[26][26];
int nds;

int dx[] = {0,1,0,-1,1,-1,1,-1};
int dy[] = {1,0,-1,0,1,-1,-1,1};

void dfs(int x, int y){
	g[x][y] = '2';
	nds++;
	for(int i = 0; i < 8; i++){
		int xx = x + dx[i];		
		int yy = y + dy[i];
		
		if (xx >= 0 && yy >= 0 && xx < n && yy < m){
		
			if (g[xx][yy] == '1'){
			
				dfs(xx,yy);
				
			}
		}	
	}
}

int main(){
	int runs;
	scanf("%d\n",&runs);
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) putchar(10);
		n = 0,m = 0;
		while(fgets(g[n],sizeof(g),stdin) && g[n][0]!='\n'){
			n++;
		}
		m = strlen(g[0])-1;
		int best = 0;
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m ; j++){
				if (g[i][j] == '1'){
					nds = 0;
					dfs(i,j);
					best = max(nds,best);
				}
			}
		}
		printf("%d\n",best);
	}
	
	return 0;
}
