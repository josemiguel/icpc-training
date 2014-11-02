#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std ;

int res = 0;
int l;

int main(){

	int n,m,s;
	cin >> n >> m >> s;
	s--;
	vector<vector<pair<int,int> > > g(n);
	for( int i = 0; i < m ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--;
		g[u].push_back( make_pair( v,w));
		g[v].push_back( make_pair( u,w));
	}
	set<pair<int,int> > Q;
	Q.insert(make_pair( 0, s ));
	int dist[ n + 1 ], pai[ n + 1];
	memset( dist,-1,sizeof dist);
	memset( pai,-1,sizeof pai);
	dist[ s ] = 0;
	pai[ s ] = -2;
	while(!Q.empty()){
		pair<int,int> cur = *Q.begin();
		Q.erase(Q.begin());
		int v = cur.second;
		int w = cur.first;
		if ( w > dist[ v ] ) continue;
		for( int i = 0; i < g[ v ].size(); i++){
			int u = g[ v ][ i ].first;
			int W = g[ v ][ i ].second;
			if ( dist[ u ] == -1 || w + W < dist[ u ]){
				dist[ u ] = w + W;
				pai[ u ] = v;
				Q.insert( make_pair( dist[u], u ) );
			}
		}
	}
	cin >> l;
	for( int i = 0; i < n ; i++) {
		if ( dist[ i ] == l ) res++;
	}
	memset( dist, 0, sizeof dist);

	stack< int > S;
	int u = s;
	for( int i = 0; i < g[ u ].size(); i++){
		S.push( g[ u ][ i ].first );
		dist[ g[ u ][ i ].first ] = g[ u ][ i ].second;
	}
	while(!S.empty() ){
		int v = S.top();S.pop();
		for( int i = 0; i < g[ v ].size(); i++){
			int x = g[ v ][ i ].first;
			int w = g[ v ][ i ].second;
			if ( x == s ) continue;
			if ( w + dist[ v ] > l ) res++;
			else S.push( x );
		}
	}
	cout << res << endl;


	return 0;
}
