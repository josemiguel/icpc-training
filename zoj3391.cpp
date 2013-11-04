#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std ;

#define MAX 32*32

int d[ MAX ];
int g[ 32 ][ 32 ];

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

struct edge{
	int u, v, w;
	edge(int u, int v, int w ):u(u),v(v),w(w){}
};

vector< edge > e;
void insert( int u, int v, int w ){
	e.push_back(edge(u,v,w)); 
}

#define NORMAL 0
#define GRAVE 1
#define HOLE 2
#define INF 1 << 29

void pre(int n, int m){
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++){
			if ( g[i][j] != NORMAL) continue;
			for( int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if ( x < 0 || y < 0 || x >= n || y >= m ) continue;
				if ( g[x][y] != GRAVE )
					insert( i * m + j , x * m + y , 1 );
			}
		}
	}
}

int bf(int n, int fin){
	d[0] = 0;
	for( int j = 0; j < n - 1 ; j++){
		for( int i = 0; i < e.size() ; i++){
			d[e[i].v] = min( d[e[i].v], d[e[i].u] + e[i].w );
		}
	}
	for( int i = 0; i < e.size(); i++){
		if (  d[e[i].v] > d[e[i].u] + e[i].w ) return -INF;
	}
	return d[fin];
}

int main(){
	int n,m,t,x,y,xx,yy;
	while( scanf("%d%d",&n,&m) && n+m){

		e.clear();
		memset( g,NORMAL, sizeof g );
		for( int i = 0; i < MAX ; i++ ) d[i] = INF;
		

		scanf("%d",&t);
		for( int i = 0; i < t; i++){
			scanf("%d%d",&x,&y);
			g[x][y] = GRAVE;
		}
		scanf("%d",&t);
		for( int i = 0; i < t; i++ ){
			scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&t);
			insert( x * m + y, xx* m + yy , t);
			g[x][y] = HOLE;
		}
		
		g[n-1][m-1] = 3;

		pre( n , m );


		int res = bf( n * m  , ( n-1 ) * m + ( m-1 ) );
		if ( res == -INF ) {
			printf("Never\n");
		}else if ( res == INF ){
			printf("Impossible\n");
		}else {
			printf("%d\n",res);
		}

	}

	return 0;
}
