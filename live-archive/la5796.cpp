#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 10010
int p[ MAX ];
void init(int n ){for(int i = 0; i < n; i++) p[i]=i;}
int _find( int a ) { return a == p[a] ? a : _find( p[a]); }
void _union( int a , int b ) { p[_find(a)] = _find(b); }
int usd[ MAX ];
int pre[ MAX ];
int low[ MAX ];

vector<vector<int> > g;

void dfs( int u, int pai, int lvl ){
	usd[ u ] = true;
	low[ u ] = pre[ u ] = lvl;
	for( int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if ( usd[v] == 1 && v != pai) 
			low[u] = min( low[u], pre[v] );
		if ( !usd[v] ){
			dfs( v, u , lvl + 1 );
			low[ u ] = min( low[v], low[u] );
			if ( low[v] > pre[u] )	_union(v, u );
		}
	}
	usd[u] = 2;
}

int main(){

	int n , m, q ;
	while( scanf("%d %d %d",&n,&m,&q) != -1 && n+m+q){
		g = vector<vector<int> > ( n );
		init( n );
		memset( usd, 0, sizeof usd );
		int u , v;
		for( int i = 0; i < m; i++ ){
			scanf("%d %d",&u,&v);
			u--,v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for( int i = 0; i < n; i++) if (!usd[i]){
			dfs( i, 0 , 0 );
		}
		while(q--){
			scanf("%d%d",&u,&v);
			u--,v--;
			if ( _find(u) == _find(v) ){
				putchar('Y');
			}else{
				putchar('N');
			}
			putchar(10);	
		}
		putchar('-');
		putchar(10);
	}


	return 0;
}
