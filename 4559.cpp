#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std ;

struct Point{
	int x, y;
	Point(){}
	Point(int x, int y ):x(x),y(y){}
	bool operator < ( const Point &p )const{
		if ( p.y== y)
			return x< p.x;
		return y > p.y;
	}
	Point operator - ( Point p ){
		return Point( x - p.x , y - p.y );
	}
	int operator %( Point p ){
		return x * p.y - y * p.x;
	}
};

int ccw( Point a, Point b, Point c ){
	return (b-a)%(c-a);
}

typedef vector<Point> Poly;

Poly convexHull( Poly &P ){
	int n = P.size();
	sort( P.begin(), P.end());
	int k = 0;
	Poly H( 2 * n );
	for( int i = 0; i < n; i++){
		while( k >= 2 && ccw( H[k-2], H[k-1], P[i] ) <= 0 ) k--;
		H[k++] = P[i];
	}
	int t = k + 1;
	for( int i = n - 2 ; i >= 0 ; i--){
		while( k >= t && ccw( H[k-2], H[k-1], P[i] ) <= 0 ) k--;
		H[k++] = P[i];
	}
	H.resize( k );
	H.erase( H.begin() );
	return H;
}


bool in( Point p, Poly H ){

	int cross = 0;
	int n = H.size(); 
	for( int i = 1; i <= n ; i++){
		Point q = H[i - 1];
		Point r =  H[i % n];

		if ( ccw( p, q, r ) == 0 ) return false; 
		
		if ( q.y > r.y ) swap( q, r );
		if ( p.y > q.y && p.y <= r.y && ccw( p, q, r ) > 0 ) cross++; 
	}
	return cross % 2 ;

}

int main(){

	int T;
	scanf("%d",&T);
	while( T-- ){
		int r, n;
		scanf("%d %d",&r, &n);
		Poly P(n);
		for( int i = 0; i < n; i++){
			scanf("%d %d", &P[i].x, &P[i].y);
		}
		Poly H = convexHull( P );
		int k = H.size();
		int ymin = 1<<20;
		int xmin = 1<<20;
		int xmax = -1<<20;
		int ymax = -1<<20;
		for( int i = 0; i < k; i++){
			ymin = min(ymin, H[i].y);
			xmin = min(xmin, H[i].x);
			
			xmax = max(xmax, H[i].x);
			ymax = max(ymax, H[i].y);
		}
		vector<pair<int,pair<int,int> > > res;
		int Y, lx, rx;
		for( int y = ymax -1 ; y > ymin; y--){
			bool f = true;
			for( int x = xmin + 1 ; x <=  xmax ; x++){
				if ( in( Point(x, y),H ) ){
					if ( f ) Y = y , lx = x;
					f = false;
				}else if ( !f ){
					rx  = x -1;
					res.push_back( make_pair( Y , make_pair( lx, rx ) ));
					break;
				}

			}
		}
		printf("%d %d\n", r, res.size() );
		for( int i = 0; i < res.size(); i++){
			printf("%d %d %d\n", res[i].first, res[i].second.first, res[i].second.second);
		}

	}

	return 0;
}

