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
#define MAX 120
int n;
int grid[MAX][MAX];
int nodos;
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool in(int x,int y) {return x>=0 && x<n && y>=0 && y<n;}
void dfs(int x, int y, int color){
	grid[x][y] = -1;
	nodos++;
	for(int i = 0; i < 4 ; i++){
		if (in(d[i][0]+x,d[i][1]+y)){
			if (grid[d[i][0]+x][d[i][1]+y] == color){
				dfs(d[i][0]+x,d[i][1]+y,color);
			}
		}
	}
}

bool solve(){
	for(int color = 0; color < n; color++){
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < n; j++){
				if (grid[i][j] == color){
					nodos = 0;
					dfs(i,j,color);
					if (nodos != n)return false;
				}
			}
		}
	}
	return true;
}

int main(){
	while(cin>>n && n){
		cin.ignore();
		string s;
		memset(grid,0,sizeof(grid));
		for(int i = 1 ; i < n  ;i++){
			getline(cin,s);
			istringstream is(s);
			int x,y;
			while (is>>x>>y) grid[x-1][y-1] = i;
		}
		if (solve() ){
			puts("good");
		}else{
			puts("wrong");		
		}
	}
	
	return 0;
}
