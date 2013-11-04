#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void print( int mask ){
	int g[3][3], y = 0;
	memset( g,0 ,sizeof g);
	for( int i = 0; i < 9 ; i++){
		if ( mask & ( 1 << i ) ){
			g[ i/3 ][ y ] = 1;
		}
		y = ( y + 1 ) % 3;
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int F( int mask ){
	int nmask = 0;
	int y = 0;
	int g[3][3],h[3][3];
	for( int i = 0; i < 3; i++)
		for( int j = 0; j < 3; j++)
			g[i][j] = h[i][j] = 0;

	for( int i = 0; i < 9 ; i++){
		if ( mask & ( 1 << i ) ){
			g[ i/3 ][ y ] = 1;
			h[ i/3 ][ y ] = 1;
		}
		y = ( y + 1 ) % 3;
	}
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			int sum = 0;
			for(int k = 0; k < 4; k++){
				int ni = i+dx[k];
				int nj = j+dy[k];
				if ( ni < 0 || nj < 0 || ni >= 3 || nj >= 3) continue;
				sum = (sum % 2 + h[ni][nj] % 2) % 2;
			}
			g[i][j] = sum;
		}
	}
	for( int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			if ( g[i][j] ) 
			nmask |= ( 1 << i * 3 + j );
		}
	}
	return nmask;
			
}
int tmp ;
int dp [ 1 << 9 ];
bool cagao  = false;
int dfs( int last, int mask, int lvl ){
	if ( mask == last) return -1;
	if ( mask == tmp ) return lvl ;
	if (dp[ mask ] != -1) return dp[ mask ];
	dp[ mask ] = 0;
	return dp[ mask ] = dfs(mask, F( mask ), lvl +1 );
}

int main(){

	int runs;
	cin >> runs;
	while( runs-- ){
		tmp = 0;
		memset( dp, -1, sizeof dp );
		for( int i = 0; i < 3 ; i++) {
			for(int j = 0; j < 3; j++){
				char c;
				cin >> c;
				if ( c == '1') 	tmp |= (1 << ( i * 3 + j ));
			}
		}
		int res = 0;
		if ( tmp == 0 ) {
			cout << -1 << endl;
		}else{
			while ( (tmp = F(tmp)) != 0) {
				res++;
			}
			cout << res  << endl;
		}
	}

	return 0;
}
