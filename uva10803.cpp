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
double g[105][105];
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d",&n);
		int x[105],y[105];
		for(int i = 0 ; i < n ;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (i == j) g[i][j] = 0;
				else g[i][j] = 1<<20;
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				g[i][j] = g[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				if (g[i][j] >= 10){
					g[i][j] = g[j][i] = 1<<20;
				}
			}
		}
			for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<g[i][j]<<"\t ";
			}
			cout<<endl;
		}
		double ans = 0.0;
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (g[i][k] + g[k][j] < g[i][j]){
						g[i][j] = g[j][i] = g[i][k] + g[k][j];
					}
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<g[i][j]<<"\t ";
			}
			cout<<endl;
		}
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				ans = max(g[i][j],ans);
			}
			cout<<endl;
		}
		printf("Case #%d:\n%.4lf\n\n",r,ans);		
		//ans = fabs(ans*1e4 - floor(ans*1e4) - 0.5);
		
		if (ans <= 10 + 1e-2){
			printf("Case #%d:\n%.4lf\n\n",r,ans);
		}else{
			puts("Send Kurdy\n");
		}
		
		
	}
	
	return 0;
}
