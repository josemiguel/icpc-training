#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct Point{
	int x, y, id;
	Point(){}
	Point( int x, int y ):x(x),y(y){}
	bool operator < ( Point const &p) const{
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
	bool operator == ( Point p ){
		return p.x == x && y == p.y;
	}
	Point operator - ( Point p ){
		return Point( x - p.x, y - p.y );
	}
	int operator % ( Point p ){
		return x * p.y - y * p.x;
	}
};

int ccw( Point a, Point b, Point c ){
	return ( b - a ) % ( c - a  );
}

typedef vector<Point> Poly;
vector<int> g[ 1505 ];
int pai[ 1505 ],R[ 1505 ];
Point puntos[ 1505 ], ori[ 1505 ];
Poly T[ 1505 ];

map<Point, int > ID;
map< pair<Point,Point>, int > LADO;
int id;

void dfs( int u, int p ){	
	for( int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if ( pai[ v ] == -1) {
			pai[ v ] = u;
			ori[ id++ ] = puntos[ v ] ;
			dfs( v, u );
		}
	}
}
int area(int n){
	int res = 0;
	for( int i = 0; i < n; i++) res += ori[i] % ori[(i+1)%n];
	return res;
}

int main(){
	int n;
	while( scanf("%d",&n ) && n != -1 ){
		ID.clear();
		LADO.clear();

		id = 0;
		for( int i = 0; i < n; i++ ) g[i].clear();

		for( int i = 0; i < n - 2; i++ ){
			Poly tri( 3 );
			for( int j = 0; j < 3; j++) {
				scanf("%d %d",&tri[j].x,&tri[j].y);
				if ( ID.find( tri[j] ) == ID.end()) { 
					ID[ tri[j] ] = id; 
					tri[j].id = id;
					puntos[ id ] = tri[j];
					id++;
				}

			}

			for( int j = 1; j <= 3; j++ ){
				Point a = min ( tri[j-1], tri[j % 3] );
				Point b = max ( tri[j-1], tri[j % 3] );
				LADO[ make_pair( a, b ) ]++; 
			}
			T[ i ] =  tri ;
		}

		for( map< pair<Point,Point >, int > ::iterator it = LADO.begin(); it != LADO.end(); it++ ){
			if ( it->second != 1 ) continue; 
			pair<Point,Point> seg = it->first;	

			Point pu = seg.first;
			Point pv = seg.second;
			int u = ID[ pu ], v = ID[ pv ];
			g[ u ].push_back( v );
			g[ v ].push_back( u );
		}

		id = 0;
		memset( pai, -1,sizeof pai );
		dfs( 0, -1 ); 

		if ( area(n) > 0 ) reverse( ori, ori + n ) ; // para que esté clockwise, antes de ordenar
		
		for( int i = 0; i < n; i++ ) R[ ori[ i ].id ] = ori[ ( i + 1 ) % n].id; 

		sort( ori, ori + n ); 
		for( int pos = ori[0].id ; n-- ; pos = R[pos] ){
			if ( pos != ori[0].id ) putchar( 32 );
			printf("%d %d", puntos[pos].x,puntos[pos].y);
		}
		printf("\n");
	}

	return 0;
}

