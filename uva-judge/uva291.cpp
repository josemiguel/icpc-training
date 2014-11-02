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
const int N = 5;

int g[N][N] = {{0,1,1,0,1},{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{1,1,1,1,0}};

int res[9];
int pos = 0;
void dfs(int r, int idx){
	if (r == 0){
		res[pos] = idx+1;
		for(int i = 0;i < 9; i++){
			printf("%d",res[i]);
		}
		putchar(10);
	}else{
		for(int i = 0; i < N; i++){
			if (g[idx][i]){
				g[idx][i] = g[i][idx] = 0;
				int j;
				for(j = 0; j < N; j++){
					if (g[i][j]) break;
				}
				if (j == N && r-1) {
					g[idx][i] = 1;
					g[i][idx] = 1;				
					continue;
				}
				r--;
				res[pos++] = idx+1;
				dfs(r,i);
				g[idx][i] = g[i][idx] = 1;
				r++;
				pos--;
			}
		}
	}
}

int main(){
	dfs(8,0);
	return 0;
}
