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
#define MAX 250

int n,m;
double dist(pair<int,int> a, pair<int,int> b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

double dp[MAX][MAX];
int main(){

	
	for(int r = 1 ; scanf("%d",&n) && n ; r++){
		vector<pair<int,int> > pp(n);
		for(int i = 0 ; i < n ;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			pp[i] = mp(x,y);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dp[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n -1; i++)
			for(int j = i+1; j < n; j++){
				dp[i][j] = dp[j][i] = dist(pp[i],pp[j]);
			}
				
		for(int k = 0; k < n; k++){		
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (dp[i][k] && dp[k][j])
						dp[i][j] = dp[j][i] = min(dp[i][j],max(dp[i][k],dp[j][k]));
				}
			}
		}
		
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",r,dp[0][1]);
	}
	
	return 0;
}
