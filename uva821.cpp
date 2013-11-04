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
#define MAX 105
#define mmax(x,y) (x)>(y)?(x):(y)
#define mmin(x,y) (x)<(y)?(x):(y)
int g[MAX][MAX];
int main(){
	int u,v;	
	int r = 1;
	while(scanf("%d %d",&u,&v) && u+v){
		int n = 0,np = 0;

		for(int i = 0; i < MAX; i++) 
			for(int j = 0; j < MAX; j++) 
				if (i!=j)
					g[i][j] = 1<<10;
				else g[i][j] = 0;
		
		g[u][v] = 1;

		n = mmax(n,mmax(u,v));
		
		while(scanf("%d %d",&u,&v) && u+v){
			g[u][v] = 1;
			n = mmax(n,mmax(u,v));
		}
		
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					g[i][j] = min(g[i][k]+g[k][j],g[i][j]);
					
		int avg = 0;
	
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if (g[i][j] != 1<<10 && g[i][j]){
					avg += g[i][j];
					np++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n",r++,avg/(double)(np));

	}
	
	
	return 0;
}
