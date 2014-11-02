#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;
vector<vector<int> > g;
int color[205];
bool dfs( int u ) {
	bool res = false;
	for( int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if ( color[v] == 0 ){
			color[v] = -color[u];
			res |= dfs( v );
		}else if ( color[u] == color[v] ) {
			return true;
		}
	}
	return res;

}

int main(){
	int n;
	while(cin >> n && n){
		int m ;
		cin >> m;
		g = vector<vector<int> > ( n );
		int u, v;
		for( int i = 0 ;  i < n ; i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			color[i] = 0 ;
		}
		color[0] = 5;
		if ( dfs(0) ) {
			cout << "NOT ";
		}
		cout << "BICOLORABLE." << endl;
	}

	return 0;
}
