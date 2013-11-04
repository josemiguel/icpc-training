#include<iostream>
#include<list>
#include<set>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std ;

const double PI = acos(-1.0);
const double EPS = 1e-9;

int cmp( double a, double b = 0 ){
	return a + EPS < b ? -1 : a - EPS > b ? 1 : 0 ;
}

struct Point{
	double x, y;
	double ang;
	Point(){}
	Point( int x, int y ):x(x),y(y){}
	bool operator < ( const Point &p ) const {
		int t = cmp(x, p.x);
		if(t != 0) return t < 0;
		return cmp(y, p.y) < 0;
	}
	int operator %( Point p ) {
		return x * p.y - y * p.x;
	}
	int operator *( Point p ){
		return x * p.x + y * p.y;
	}

	Point operator *( int k ){
		return Point( x * k , y * k );
	}
	Point operator - ( Point p ){
		return Point( x - p.x, y - p.y);
	}
};
typedef vector<Point> Poly;

double norma( Point b ){
	return sqrt( b.x * b.x + b.y * b.y );
}

int ccw2( Point a, Point b, Point c ){
	Point ba = b - a;
	Point ca = c - a;
	if ( cmp((ba % ca)) > 0 ) return 1;
	if ( cmp((ba % ca)) < 0 ) return -1;
	if ( cmp((ba * ca)) < 0 ) return 2;
	if ( cmp(norma(ba), norma(ca)) < 0 ) return -2;
	return 0;
}


bool onSeg( Point p, Point q, Point r ){
	Point pq = q - p;
	Point pr = r - p;
	if ( cmp( pq % pr ) == 0 ) 
		if ( cmp( pq * pr ) <= 0 ) return true;
	return false;
}


bool intersect( Point a1, Point a2, Point b1, Point b2 ){
	int a =  ccw2( a1 , a2, b1 ) * ccw2( a1, a2, b2);
	int b =  ccw2( b1 , b2, a1 ) * ccw2( b1, b2, a2);
	if ( a > 0 || b > 0 ) return false;
	if ( a < 0 && b < 0 ) return true;
	return onSeg( a1, b1, b2 ) || onSeg( a2, b1, b2 ) || onSeg( b1, a1, a2 ) || onSeg( b2, a1, a2 ) ;
}

// sweep line

struct Event{
	int x, y, id ;
	bool f ;
	Event(){}
	Event( Point p, int id):id(id) {
		x = p.x;
		y = p.y;
	}
	bool operator < ( const Event &p)  const{
		int t = cmp( y , p.y );
		if ( t != 0 ) return t < 0 ;
		int s = cmp( x, p.x );
		if ( s != 0 ) return s < 0;
		if(f != p.f)return f;
		return id < p.id;
	}
};

int intersecciones( vector<pair<Point,Point> > seg ){
	int res = 0;
	set<Event> Q;
	vector< int > cross( seg.size() , 0);		
	vector< int > sweep;
	for( int i = 0; i < seg.size(); i++){
		Event q( seg[i].first, i);
		Event r( seg[i].second, i);
		if ( r < q ) swap( q, r );
		q.f = true; r.f = false; 
		Q.insert(q); 
		Q.insert(r);
	}
	while( Q.size() > 0 ){
		Event p = *Q.begin(); 
		Q.erase( Q.begin() );
		if ( p.f ){
			for( int i = 0; i < sweep.size(); i++){
				bool b = intersect( seg[ sweep[i] ].first, seg[ sweep[i] ].second, seg[ p.id ].first, seg[ p.id ].second);
				if ( b ) {
					cross[ p.id ]++;
					cross[ sweep[i] ]++;
				}
			}
			sweep.push_back( p.id ); 
		}else{
			vector<int>::iterator it = find(sweep.begin(),sweep.end(), p.id );
			if ( it != sweep.end() ) sweep.erase( it );
		}
	}
	for( int i= 0; i < cross.size(); i++){
		if ( cross[i] == 0 ) res++;
	}
	return res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	while(runs--){
		int n;
		scanf("%d",&n);
		vector< pair<Point,Point> > seg;
		for( int i = 0; i < n;i++){
			Point a, b;
			scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
			seg.push_back( make_pair( a, b ) );
		}
		printf("%d\n", intersecciones( seg ) );
	} 
	return 0;
}

