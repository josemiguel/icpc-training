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

#define MAX 20000
#define INF 1<<30

int dp[MAX+2];

int main(){
	int runs,n,t,c,i,j;
	scanf("%d",&runs);
	while(runs--){
		scanf("%d%d",&n,&t);
		for(i = 1; i <= MAX; i++) dp[i] = INF;
		dp[0] = 0;
		for(i = 0; i < t; i++){
			scanf("%d",&c);
			for(j = MAX ; j >= c; j--)
				if (dp[j] > dp[j-c] + 1) dp[j] = dp[j-c] + 1;
		}
		for(i = n; i <= MAX; i++)
			if (dp[i] != INF){
				printf("%d %d\n",i,dp[i]);
				break;
			}
	}
	return 0;
}
