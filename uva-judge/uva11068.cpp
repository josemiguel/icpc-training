#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std ;

const double pi = acos(-1.0);

struct Point{
	double x, y;
	Point(){}
	Point( double x, double y ):x(x),y(y){}
	bool operator < ( const Point &p ) const {
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
	double operator %( Point p ) {
		return x * p.y - y * p.x;
	}
	double operator *( Point p ){
		return x * p.x + y * p.y;
	}
	Point operator + ( Point p ){
		return Point( p.x + x , p.y + y );
	}
	Point operator - ( Point p ){
		return Point( x - p.x, y - p.y);
	}
	
};
typedef vector<Point> Poly;

double ccw( Point a, Point b, Point c ){
	return ( b - a ) % ( c - a );
}

double norma( Point a ) {
	return hypot( a.x, a.y );
}

double dist( Point a, Point b ){
	return norma( b - a );
}

//distancia perpendicular del punto p al segmento a,b 
double dist( Point p, Point a, Point b ){
	return ccw( p , a , b ) / norma( b - a );
}
// Ax + By = C
struct Recta{
	int A, B, C;
	Recta(){}
	Recta( Point a, Point b ){
		A = b.y - a.y;
		B = a.x - b.x;
		C = A*a.x + B*a.y;
	}
	Point intersect( Recta r, bool &paralelas ) {
		double det = A*r.B - r.A*B;
		if ( det == 0 ) {
			paralelas = true;
			return Point(1<<20,1<<20);
		}else{
			double x = (r.B*C - B*r.C) / det;
			double y = (A*r.C - r.A*C) / det;
			return Point( x, y );
		}
	}
};


//Poligonos

double area( Poly p ){
	double res = 0.0;
	int n = p.size();
	for( int i = 0; i < n; i++){
		res += p[ i ] % p[ ( i + 1 ) % n ];
	}
	return fabs(res / 2.0 );
}


// convex hull 

Poly convexHull( Poly p ){
	sort( p.begin(), p.end() );
	int n = p.size(), k = 0;
	Poly h ( 2 * n );
	for( int i = 0; i < n; i++ ){
		while( k >= 2 && ccw( h[k-2], h[k-1], p[i] ) <= 0 ) k--;
		h[k++] = p[i];
	}
	int t = k + 1;
	for( int i = n - 2; i >= 0; i-- ){
		while( k >= t && ccw( h[k-2], h[k-1], p[i] ) <= 0 ) k--;
		h[k++] = p[i];
	}
	h.resize( k - 1 );
	return h;
	
}

// si un punto esta dentro de un poligono

bool inPoly( Poly &P, Point p ){
	int cross = 0, n = P.size();
	for( int i = 1; i <= n; i++){
		Point q = P[i-1]; 
		Point r = P[i%n]; 

		// qr es un lado del poligono
		if ( q.y > r.y ) swap( q, r ); // por comodidad hacer que r siempre este arriba de q
		double ori = ccw( p ,q , r ); // la orientacion 
		if ( p.y > q.y && p.y <= r.y ){ // esta tipo al medio de un segmento... el intervalo debe ser asi... (q, r] 
		// de tal forma que en la siguiente iteracion no se repita el r
			if ( ori > 0 ) { // si el segmento esta tipo a la derecha 
				cross++;
			}
			else if ( ori == 0 ) return true;
		}
	}
	return cross % 2;

}

bool inConvexPoly( Poly P, Point p ){
	int n = P.size(); 
	double ori = ccw( P[0], P[1], P[2] );
	int lo = 1, hi = n - 1 ;
	while( true ){
		int mid = ( lo + hi ) / 2;

		double mid_ori = ccw( P[0], P[mid], p );
		if ( (mid_ori < 0 && ori < 0) || ( mid_ori > 0 && ori > 0 ) ) lo = mid ;
		else hi = mid ;
		if ( hi <= lo ){	
			lo = ( lo + 1 ) % n;
			break;
		}
		lo = ( lo + 1 ) % n;

	}
	cout << P[lo].x<< " " <<P[lo].y << endl;
	cout << P[hi].x<< " " <<P[hi].y << endl;
	Poly tri;

	tri.push_back( P[0] ); 
	tri.push_back( P[lo] ); 
	tri.push_back( P[hi] ); 
	return inPoly( tri, p );
}



int main(){
	int n;
	Recta r1,r2;
	while( cin >> r1.A >> r1.B >> r1.C >> r2.A >> r2.B >> r2.C ){
		if ( r1.A == 0 && r1.B == 0 && r1.C == 0 && r2.A == 0 && r2.B == 0 && r2.C == 0 )
			break;
		bool paralelas = false;
		Point res = r1.intersect( r2, paralelas );
		if (!paralelas)
			printf("The fixed point is at %.2lf %.2lf.\n", res.x, res.y);
		else
			puts("No fixed point exists.");
		
	}
}


