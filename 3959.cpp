#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
#define repn( i, a, b ) for( int i = a; i < b; i++)
#define rep( i, a ) repn( i, 0 , a )

struct Point{
	int x, y ;
	Point(){}
	Point( int x, int y ):x(x),y(y) {}
	Point operator -( Point p ){
		return Point( x - p.x, y - p.y );
	}
	Int operator %( Point p ){
		return x * p.y - y * p.x;
	}
	bool operator < ( Point p ){
		return p.x != x ? x < p.x : y < p.y ;
	}
};
typedef vector<Point> Poly;

vector<vector<int> > g;
Poly p;
bool cmp( int i , int j ){
	return p[i] < p[j] ;
}
char ori( Point a, Point b ){
	if ( a.x < b.x && a.y == b.y) return 'E';
	if ( a.x > b.x && a.y == b.y) return 'W';
	if ( a.x == b.x && a.y > b.y) return 'S';
	if ( a.x == b.x && a.y < b.y) return 'N';
}

Int ccw( Point a, Point b, Point c ){
	return ( b - a ) % ( c - a);
}

bool usd[ 1005 ];
vector<int> t;
void dfs( int u){
	usd[u] = true;
	for( int i = 0; i < g[u].size(); i++){
		if ( usd[g[u][i]] ) continue;
		dfs( g[u][i] );
		break;
	}
	t.push_back( u );	
}
int main(){

	int n;
	while( cin >> n ){
		p = Poly( n );
		rep( i , n ) cin >> p[i].x >> p[i].y ;
		//sort( p.begin(), p.end() );
		memset( usd , 0 , sizeof usd);
		g = vector<vector<int > > ( n );
		rep( i , n ){
			repn( j,  i + 1 , n ){
				if (  p[i].x == p[j].x || p[i].y == p[j].y ){
					g[i].push_back( j );	
					g[j].push_back( i );	
				}
			}
		}
		rep( i, n ) sort( g[i].begin(), g[i].end(), cmp );
		t.clear();
		dfs( 0 );

		for( int i = 0; i < t.size();i++){
			cout << ori( p[t[i]], p[t[(i+1)%t.size()]] )  ;
		}
		cout << endl;
	}

	return 0;
}
