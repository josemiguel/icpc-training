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

//int g[MAX][MAX];
//vector<vector<int> > g;
int n


void print(int N){
	for(int i = n-1; i >= 0; i--){
		printf("%d",(N >> i) & 1);
	}
	putchar(10);
}	

void solve(int N, int h,int max){
	int bits = __builtin_popcount(N);
	if (bits == h){
		print(N);
	}
	if (N == max) return;
	solve(N+1,h,max);
	
}

int main(){
	int r,h;
	scanf("%d",&r);
	for(int j = 0; j < r;j++){
		if (j!=0) putchar(10);
		scanf("%d %d",&n,&h);
		int N = 0;
		for(int i = 0; i < h; i++){
			N = (N << 1) | 1;
		}
		solve(N,h,(1<<n) - 1);
	}
}
