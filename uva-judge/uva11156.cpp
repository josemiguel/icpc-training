#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std ;


int mp[22][22];
bool b[22][22];
double g[22][22];
double dist( int x1, int y1, int x2, int y2 ){
	double xx = (x1-x2);
	xx = xx*xx;
	double yy = (y1-y2);
	yy = yy*yy;
	return sqrt( xx + yy );
}
int grado[ ( 1 << 20 ) + 5 ], a[22];
double dp[ ( 1 << 20 ) + 5 ] ;

int main(){
	int runs, r = 1;
	scanf("%d\n",&runs);
	while(runs--){
		int n;
		scanf("%d\n",&n);
		int N  = 0;
		memset( grado, 0,sizeof grado );
		memset( mp, -1,sizeof mp);
		for( int i = 0; i < 22; i++)
			for( int j = 0; j < 22; j++){
				if ( i == j ) g[i][j] = -1000;
				else g[i][j] = 1e15;
				b[i][j] = 0;
			}

		double res = 0.0;
		for( int i = 0; i < n; i++){
			char x1, x2;
			int y1,y2;
			scanf("%c%d %c%d\n", &x1,&y1,&x2,&y2);
			x1 -= 'A';
			x2 -= 'A';
			y1--; y2--;
			if ( mp[x1][y1] == -1 ) mp[x1][y1] = N++;
			if ( mp[x2][y2] == -1 ) mp[x2][y2] = N++;
			
			cout <<(int) x1 << " " << y1 << " " << mp[x1][y1] << endl;
			cout << (int )x2 << " " << y2 << " " << mp[x2][y2] << endl;

			int u = mp[x1][y1], v = mp[x2][y2]  ;

			g[u][v] = g[v][u] = dist( x1,y1, x2,y2 );
			b[u][v] = b[v][u] = 1;
			grado[u]++;
			grado[v]++;
			res += g[u][v];
		}
		cout << N << endl;
		for( int k = 0; k < N ; k++){
			for( int i = 0; i < N ; i++){
				for( int j = 0; j < N ; j++){
					if ( i == j || i == k || j == k ) continue;
					b[i][j] = b[j][i] = b[i][j] | ( b[i][k] & b[k][j] );
					g[i][j] = g[j][i] = min( g[i][j], g[i][k] + g[k][j] );
				}
			}
		}
		bool cag = false;

		for( int i = 0; i < N ; i++){
			for( int j = 0; j < N ; j++)
				cout << b[i][j] <<" " ;
			cout << endl;
		}
		printf("Case %d: ", r++);
		if ( cag ) {
			puts("~x(");
			continue;
		}

		int sz = 0;
		for( int i = 0; i < N; i++ ) if ( grado[i] & 1 ) a[sz++] = i;
		int m = 1 << sz ;
		for( int i = 0; i < m; i++) dp[i] = 1e10;
		dp[0] = res;

		for( int mask = 0; mask < ( 1 << sz ); mask++ ){
			for( int i = 0; i < sz; i++ ){
				if ( mask & ( 1 << i ) ) continue;
				for( int j = i + 1 ; j < sz; j++ ){
					if ( mask & ( 1 << j ) ) continue;

					if ( g[a[i]][a[j]] < 0 ) continue;

					int nmask = mask | ( 1 << i ) | ( 1 << j ) ;
					dp[nmask] = min( dp[nmask], dp[mask] + g[a[i]][a[j]]);
				}
			}
		}

		printf("%.2lf\n", dp[m-1]);

	}
}
