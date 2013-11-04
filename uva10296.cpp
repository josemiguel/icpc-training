#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int g[20][20] , a[20] , dp[1<<16], grado[20];
int n,m;

int main(){

	while(scanf("%d",&n) && n){
		scanf("%d",&m);
		
		int res = 0;
		
		memset(grado,0,sizeof grado);
		memset(g,-1,sizeof g);
		
		
		for(int i = 0; i < m; i++) {
			int x,y,w; scanf("%d%d%d",&x,&y,&w);
			res += w;
			
			x--; y--;
            int u = x > y ? x : y;
            int v = x < y ? x : y;
            
            if( g[v][u] == -1 ) g[v][u] = w;
            g[u][v] = g[v][u] = g[v][u] < w ? g[v][u] : w;
            
			grado[u]++;	grado[v]++;
		}
		
		for(int k = 0 ; k < n ; k++ )
			for(int i = 0 ; i < n ; i++ )
				for(int j = 0 ; j < n ; j++ ){
					if( g[i][k] == -1 || g[k][j] == -1 ) continue;
					if( g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j] ) g[i][j] = g[i][k] + g[k][j];
		}

		int sz = 0;
		for(int i = 0; i < n; i++)	if ( grado[i] & 1 ) a[sz++] = i;
		int N = 1<<sz;
		
		for(int mask = 0; mask < N ; mask++) dp[mask] = 1<<30;
		dp[0] = res;
		
		for(int mask = 0; mask < N ; mask++){
			for(int i = 0; i < sz; i++){
				if ( mask & (1<<i) ) continue;
				for(int j = i + 1; j < sz; j++){
					if ( mask & (1<<j) ) continue;
					int nmask = mask | (1<<i) | (1<<j);
					dp[nmask] = min ( dp[nmask] , dp[mask] + g[a[i]][a[j]] ) ;
				}
			}
		}
		
		printf("%d\n", dp[N-1] );
	}

	return 0;
}
