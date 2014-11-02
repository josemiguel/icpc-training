#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std ;
int R,C,N;
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int dp[5][5][1 << 16][16];
int F( int mask, int jmp){
	if ( jmp == N - 1 ) return 1;
	if ( dp[R][C][mask] != -1) return dp[R][C][mask];
	int res = 0;
	for( int i = 0; i < R; i++){
		for( int j = 0; j < C; j++){
			int pos = i * R + j;
			if ( mask & ( 1 << pos ) ){
				for(int k = 0; k < 8; k++){
					int ni = i + dx[k], ti = i + 2 * dx[k];
					int nj = j + dy[k], tj = j + 2 * dy[k];
					
					int npos = ni * R + nj, tpos = ti * R + tj;
					
					if ( ni < 0 || nj < 0 || ni >= R || nj >= C ) continue;
					if ( ti < 0 || tj < 0 || ti >= R || tj >= C ) continue;
					if ( (mask & ( 1 << npos )) && !( mask & ( 1 << tpos ))){
						res += F ( mask ^ ( 1 << npos ) ^ ( 1 << pos ) | ( 1 << tpos )  ,  jmp+1);
					}
				}
			}
		}
	}
	return dp[R][C][mask] = res;
}

int main(){

	int runs;
	scanf("%d",&runs);
	memset( dp, -1, sizeof dp);
	for( int r = 1; r <= runs; r++){
		scanf("%d %d %d",&R,&C,&N);
		int g = 0;
		for( int i = 0; i < N; i++){
			int x, y;
			scanf("%d %d",&x,&y);
			x--,y--;
			g |= ( 1 << ( x * R + y ) );
		}
		int res = F( g, 0 );
		printf("Case %d: %d\n", r, res );

	}

	return 0;
}
