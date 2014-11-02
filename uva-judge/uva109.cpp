#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std ;

struct point{
	int x, y;
	point(){}
	point( int x, int y ): x(x), y(y) {}
	bool operator < (const  point &p )const{
		if ( x == p.x ){
			return y < p.y;
		}
		return x < p.x;
	}
	point operator - ( point p ){
		return point( x - p.x , y - p.y );
	}
	int operator % ( point p ){
		return x * p.y - y * p.x;
	}
	int operator *( point p ){
		return x * p.x + y * p.y;
	}
};
typedef vector< point > poly;

double area( poly p ){
	double res = 0.0;
	int n = p.size();
	for(int i = 0; i < n; i++){
		res += p[i]%p[(i+1)%n];	
	}
	return res / 2 ;
}

int ccw( point a, point b, point c ){
	return  ( b - a ) % ( c - a ) ;
}


poly hull( poly p ){
	int k = 0; 
	sort( p.begin(), p.end());
	int n = p.size();

	poly res( 2 * n ) ;

	for(int i = 0; i < n; i++){
		while( k >= 2 && ccw( res[k-2], res[k-1] ,p[i] ) <= 0) k--;
		res[k++] = p[i];
	}
	int tmp = k + 1;
	for(int i = n - 2 ; i >= 0; i--){
		while( k >= tmp && ccw( res[k-2], res[k-1] ,p[i] ) <= 0) k--;
		res[k++] = p[i];
	}
	res.resize( k );
	return res;
}


bool co( point a , point b, point c ){
	if ( ccw( a, b, c ) == 0){
		if ( ( b - a ) * ( c - a ) <= 0 ) return true;
	}
	return false;
}


bool in( point p, poly t){
	int cross = 0;
	int n = t.size();
	for(int i = 1; i <= n; i++){
		point q = t[i-1], r = t[i % n];
	
		if ( co( p, q, r ) ) return true;

		if ( q.y > r.y ) swap( q, r );
		if ( q.y < p.y ){
			if ( r.y >= p.y && ccw( p, q ,r ) > 0) {
				cross++;
			}
		}
	
	}
	return cross % 2;
}
bool usd[ 105 ];
int main(){
	int n;
	vector<poly> v;
	while( cin >> n && n!=-1){
		poly p( n );
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}

		poly t = hull( p );
		v.push_back( t );
	}
	point p;
	double res = 0.0;
	memset( usd, 0, sizeof usd);
	while( cin >> p.x >> p.y ){
		
		for(int i = 0; i < v.size(); i++){
			if (usd[i]) continue;
			if ( in( p, v[i] ) ) {
				res += area( v[i] );
				usd[ i ] = true;
				break;
			}
		}
	}
	printf("%.2lf\n", res );
	return 0;
}
