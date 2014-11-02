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

int coins[] = {10000, 5000, 2000, 1000, 500,  200, 100, 50, 20, 10, 5};
long long dp[30005];

int main(){

	int d,c;
	while(scanf("%d.%d",&d,&c)==2 && d+c){
		int n = d*100 + c;
		for(int i = 0; i <= n; i++) dp[i] = 0LL;
		dp[0] = 1LL;
		for(int i = 0; i < 11; i++){
			for(int j = coins[i]; j <= n; j++){
				dp[j] += dp[j-coins[i]];
			}
		}
		printf("%3d.%02d%17lld\n",d,c,dp[n]);
	}
	
	return 0;
}
