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
#define N 102
int grid[N][N];


int main(){
	int n,m;
	int runs;
	scanf("%d",&runs);
	for(int r = 0; r < runs; r++){
		if (r) putchar(10);
		scanf("%d%d",&n,&m);
		cin.ignore();
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				grid[i][j] = 0;
			}
		}
		
		string s;
		for(int i = 0; i < n; i++){
			getline(cin,s);
			istringstream is(s);
			int u,v;
			is>>u;
			while(is>>v){
				grid[u][v] = -1;
			}
		}
		grid[0][1] = 1;
		if (grid[1][1] == -1) {printf("0\n"); continue;}
		for(int i = 1; i <= n ; i++)
			for(int j = 1; j <= m; j++){
				if (grid[i][j] < 0) continue;
				grid[i][j] = (grid[i-1][j] < 0 ? 0 : grid[i-1][j]) + (grid[i][j-1] < 0 ? 0 : grid[i][j-1]);
			}

		printf("%d\n",grid[n][m]);
		

	}
	
	return 0;
}
