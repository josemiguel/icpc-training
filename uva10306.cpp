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

int n,m;
int dp[300*300 + 5];

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&m,&n);
		n *= n;
		vector<int> e(m);
		for(int i = 0 ; i < m ;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			e[i] = x*x + y*y;
		}
		for(int i = 0; i <= n; i++) dp[i] = 0;
		
		for(int i = 1; i <= n; i++){
			int low = 1<<30;
			for(int j = 0; j < m; j++){
				if (e[j] > i) continue;
				if (dp[i-e[j]] + 1 < low){
					low = dp[i-e[j]] + 1;
				}
			}
			dp[i] = low;
		}
		if (dp[n] == 1<<30) puts("not possible");
		else printf("%d\n",dp[n]);
	}
	
	return 0;
}
