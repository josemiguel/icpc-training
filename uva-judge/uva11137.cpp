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

int n;
long long dp[10005];
int coins[22];
int main(){
	for(int i = 1; i <= 21 ; i++){
		coins[i] = i*i*i;
	}
	while(scanf("%d",&n) != -1 && n){
		for(int i = 0; i <= n; i++) dp[i] = 0LL;
		dp[0] = 1LL;
		for(int i = 1; i <= 21 ;i++){
			for(int j = coins[i]; j <= n; j++){
				dp[j] += dp[j-coins[i]];
			}
		}
		printf("%lld\n",dp[n]);
	}
	
	return 0;
}
