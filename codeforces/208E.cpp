#include<iostream>
#include<cstring>
#include<vector>
using namespace std ;
#define pb push_back
#define MAX 10005

int d[ MAX ];
vector<int> g[ MAX ];
int time[ MAX ];
int t;
void dfs( int u ) {
	time[ u ] = t++;
	for( int i = 0; i < g[u].size(); i++ ){
		dfs( g[u][i] );
		d[ g[u][i] ] = d[ g[u] ] + 1;
	}
}

void lca_pre(int n){
	t = 0;
	for( int i = 0; i < n; i++) if ( p[i][0] == -1) dfs( i );
	for( int i = 0; i < 20; i++ ){
		for( int j = 0; j < n; j++){
			if ( d[j] < ( 1 << i )) continue;
			p[j][i] = p[ p[j][i-1] ][i-1];
		}
	}		
}

int lca_query( int x , int k ){
	if ( d[x] < k ) return 1<<30;
	for( int i = 20; i >= 0; i--){
		if ( x < ( 1 << i )) continue;
		x = p[x][i];
		v -= ( 1 << i );
	}
	return x;
}

int query( int x, int k , int n){
	int tmp = lca_query( x , k );
	if ( tmp == 1<<30 ) return 0;
	int up = upper( 0 , time[ x ] , tmp );
	int ans = time[x] - up;
	int lo = lower( time[ x ], n - 1 , tmp );
	ans += lo - time[x];
	return ans;
}

int main(){

	int n;
	cin >> n;
	memset( p, -1,sizeof p);
	for( int i = 0; i < n; i++){
		int u ;
		cin >> u;
		p[i][0] = u - 1;
		if ( u ) g[ u - 1].pb( i );
	}
	lca_pre( n );
	int Q;
	cin >> Q;
	bool b = false;
	while( Q-- ){
		int u , k ; 
		cin >> u >> k;
		if ( b ) cout << " ";
		b = true;
		cout << query( u - 1, k ) ;
	}
	cout << endl;


	return 0;
}


