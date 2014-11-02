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
#define MAX 31

int n,m, ways,ei,ej;
int dp[MAX][MAX];

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d",&n);
		int si,sj;
		scanf("%d%d%d%d",&si,&sj,&ei,&ej);
		scanf("%d",&m);
		memset(block,0,sizeof(block));
		for(int i = 0; i < m ; i++){
			int u,v,di,dj;
			char c;
			scanf("%d %d %c",&u,&v,&c);
			di = u;
			dj = v;
			if (c == 'S'){
				dj--;
			}else if (c == 'W'){
				di--;
			}else if (c == 'E'){
				di++;
			}else if (c == 'N'){
				dj++;
			}
			block[v][u][dj][di] = 1;
		}
		ways = 0;
		dfs(sj,si);
		printf("%d\n",ways);
	}
	
	return 0;
}

