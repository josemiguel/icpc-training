#include<iostream>
#include<cstring>
using namespace std ;
int n,m;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int g[25][25];
bool usd[25][25];
int f(int x, int y, int p ){
	usd[x][y] = true;
	if ( p == 4 ) return 1;
	int res  = 0;
	for( int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;

		if ( usd[nx][ny]) continue;
		res = max( res,  g[nx][ny] * f( nx, ny , p + 1 ) );
	}
	return res ;
}

int main(){
	cin >> n >> m;
	for( int i = 0; i < n; i++)
		for( int j = 0; j < m; j++)
			cin >> g[i][j];
	int res = 0;
	for( int i = 0; i < n; i++)
		for( int j = 0; j < m; j++){
			memset(	usd, 0, sizeof usd );
			res = max( res, g[i][j]*f(i,j,1 ));		
		}

	cout << res << endl;

	return 0;
}
