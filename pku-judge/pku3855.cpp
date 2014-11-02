#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std ;

const double pi = acos(-1.0);
const double EPS = 1e-9;
struct Point{
	double x, y;
	double ang;
	Point(){}
	Point( double x, double y ):x(x),y(y){}
	bool operator < ( const Point &p ) const {
		if ( ang == p.ang ){
			if ( x == p.x ) return y < p.y;
			return x < p.x;
		}
		return ang > p.ang;
	}
	double operator %( Point p ) {
		return x * p.y - y * p.x;
	}
	double operator *( Point p ){
		return x * p.x + y * p.y;
	}

	Point operator *( double k ){
		return Point( x * k , y * k );
	}

	Point operator + ( Point p ){
		return Point( p.x + x , p.y + y );
	}
	Point operator - ( Point p ){
		return Point( x - p.x, y - p.y);
	}
	Point operator / ( double d ){
		return Point( x / d , y / d );
	}
	
};
typedef vector<Point> Poly;

double ccw( Point a, Point b, Point c ){
	return ( b - a ) % ( c - a );
}

double norma( Point a ) {
	return sqrt( a.x*a.x + a.y*a.y );
}

double dist( Point a, Point b ){
	return norma( b - a );
}

double dist( Point p, Point a, Point b ){
	return ccw( p , a , b ) / norma( b - a );
}

int ccw2( Point a, Point b, Point c ){
	Point ba = b - a;
	Point ca = c - a;
	if ( (ba % ca) > 0 ) return 1;
	if ( (ba % ca) < 0 ) return -1;
	if ( (ba * ca) < 0 ) return 2;
	if ( norma(ba) < norma(ca) ) return -2;
	return 0;
}

double area( Poly &p ){
	double res = 0.0;
	int n = p.size();
	for( int i = 0; i < n; i++){
		res += p[ i ] % p[ ( i + 1 ) % n ];
	}
	return fabs(res / 2.0 );
}

Point centerMass( Poly p ){
	Point c( 0 , 0 ) ;
	for( int i = 0; i < p.size(); i++ ) {
		c.x += p[i].x / (double)p.size();
		c.y += p[i].y / (double)p.size();
	}
	return c;
}

bool inTriang( const Poly &T , const Point &p){
	return ccw2( T[0], T[1], p ) >= 0 && 
		ccw2( T[1],T[2],p ) >= 0 && 
		ccw2( T[2],T[0],p) >= 0; 
}

bool can( const Poly &t,  const Poly &p, int i , int j , int k ){
	if(ccw(t[0], t[1], t[2]) <= 0) return false;
	for(int l = 0; l < p.size(); l++){
		if(l != i && l != j && l != k)
			if( inTriang(t, p[l]))	return false;
	}
	return true;
}
vector<Poly> triangulate( const Poly &p ){
	vector<Poly> res;
	int n = p.size();
	vector<int> l, r;
	for( int i = 0; i < n; i++){
		l.push_back( (i-1+n)%n );
		r.push_back( (i+1)%n );
	}
	int i = n - 1, cagao = 0;
	while( res.size() < n - 2 ){
		if ( cagao >= n ) return vector<Poly>();
		i = r[i];
		Poly tmp;
		tmp.push_back( p[l[i]] );
		tmp.push_back( p[i] );
		tmp.push_back( p[r[i]] );
		if ( can( tmp, p , l[i], i , r[i] ) ){
			res.push_back( tmp );
			l[r[i]] = l[i];
			r[l[i]] = r[i];
			cagao = 0;
		}else cagao++;
	}
	return res;
}


int main(){
	int n, r =  1;
	while( scanf("%d",&n )!=-1 && n ){
		Poly p( n );
		for( int i = 0; i < n; i++ ){
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		
		vector<Poly> t = triangulate( p );
		if ( !t.size() ) {
			reverse( p.begin(),p.end() );
			t = triangulate( p );
		}
		Point C( 0,0 );
		double wS = 0;
		for( int i = 0; i < t.size(); i++ ){
			Point c = ( t[i][0] + t[i][1] + t[i][2] ) / 3;
			double wA = area( t[i] );
			C = C + c * wA;
			wS += wA;
		}
		C = C /  wS;
		printf("Stage #%d: %.6lf %.6lf\n", r++,C.x, C.y);
	}
}
