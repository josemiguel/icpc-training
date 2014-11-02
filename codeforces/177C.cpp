#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std ;
char usd[ 2005 ];
bool like[2005][2005];

vector<vector<int> > g;

int ncmp = 0 ;
int n,m,k;

void dfs(int u, int f ){
	usd[u] = f;
	for( int i = 0 ; i < g[u].size(); i++){
		int v = g[u][i];
		if ( !like[u][v] ) {
			if ( usd[v] != 2 ) continue;
			dfs( v, 0 );
		}else{
			if ( usd[v] != 2 ) continue;
			dfs( v, f );
		}
	}
}

int main(){
	cin >> n;
	g = vector<vector<int> > ( n );
	cin >> m;
	int u , v;
	for( int i = 0;  i < m; i++){
		cin >> u >> v;
		u--,v--;
		g[u].push_back( v );
		g[v].push_back( u );
		like[u][v] = true;
	}
	cin >> k ;
	for( int i = 0 ; i < k; i++){
		cin >> u >> v;
		u--,v--;
		g[u].push_back( v );
		g[v].push_back( u );
	}
	for( int i = 0; i < n; i++) usd[i] = 2;
	int res = 0;
	for( int i = 0; i < n; i++){
		int tmp = 0;
		if ( usd[ i ] == 2){
			dfs( i,1 );
			cout << i +1 <<" ->" ;
			for( int i = 0;  i < n; i++){
				if ( usd[i] == 1){
					tmp += usd[i];
					cout << i + 1 << " ";
				}
				usd[i] = 2;
			}
			cout << endl;
		}
		res= max( res, tmp);
	}
	cout << res << endl;

}
