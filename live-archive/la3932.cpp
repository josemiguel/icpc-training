#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[305][305];

int vacios(int x, int y, int xx, int yy){
	return dp[x][y] - dp[xx][y] - dp[x][yy] + dp[xx][yy];
}
#define Min(x,y) x < y ? x : y
int main(){

	int n,m,k;
	while(scanf("%d %d %d",&n,&m,&k) && n+m+k){
		memset(dp,0,sizeof dp);
		for(int i = 1; i <= n; i++){ 
			for(int j = 1; j <= m; j++) {
				char c;cin>>c;
				dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (c == '.' );
			}
		}
		int res = 1<<30;
		for(int xx = 0; xx <= n; xx++){
			for(int x = xx + 1; x <= n; x++){
				int yy = 0, y = 1;
				while ( yy <= y && y <= m){
				//	cout<<vacios(x,y,xx-1,yy)<<endl;
					while( vacios( x , y , xx , yy ) < k && y <= m ) y++;
					if ( y <= m ) {
						while( vacios( x, y, xx , yy + 1 ) >= k && (yy + 1) < y ) yy++;
						
						res = Min(res, (x-xx)*(y-yy) );

					}
					y++;
				}

			}
		}
		
		printf("%d\n",res);
		
	}

	return 0;
}
