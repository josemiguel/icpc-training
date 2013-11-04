#include<iostream>
#include<map>
#include<list>
#include<set>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
// teorema de pick area = adentro + puntos_en_los_lados(coor enteras)/2 - 1
using namespace std ;

const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef long long Int;
int cmp( double a, double b = 0 ){
	return a + EPS < b ? -1 : a - EPS > b ? 1 : 0 ;
}

struct Point{
	int id;
	double x, y;
	double ang;
	Point(){}
	Point( double x, double y ):x(x),y(y){}
	Point( double x, double y, int id ):x(x),y(y),id(id){}
	
	bool operator < ( const Point &p ) const {
		int t = cmp(x, p.x);
		if(t != 0) return t < 0;
		return cmp(y, p.y) < 0;
	}
	bool operator == ( const Point &p ) const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}	
	bool operator != ( const Point &p ) const {
		return cmp(x, p.x) != 0 || cmp(y, p.y) != 0;
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

int sign( double n ){
	return n < 0 ? -1 : 1;
}

double ccw( Point a, Point b, Point c ){
	return ( b - a ) % ( c - a );
}

double norma( Point a ) {
	return sqrt( a.x*a.x + a.y*a.y );
}

double dist( Point a, Point b ){
	return norma( b - a );
}

Point rot( Point p, double a ){
	return Point( -p.x*cos(a) + p.y * sin(a) ,  p.x * sin(a) + p.y*cos(a) );
}
//distancia minima del punto p al segmento a,b 
double dist( Point p, Point a, Point b ){

	Point ab = b - a;
	Point ba = a - b;

	Point bp = p - b;
	Point ap = p - a;
	
	if ( ba * bp < 0 ) return dist( b, p );
	if ( ab * ap < 0 ) return dist( a, p );
	return fabs(ccw( p , a , b )) / norma( b - a );
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

bool exist_tri( double a, double b, double c ){
	return a + b > c && a + c > b && b + c > a;
}

//mira si el punto p esta dentro del qr
bool onSeg( Point p, Point q, Point r ){
	Point pq = q - p;
	Point pr = r - p;
	if ( cmp( pq % pr ) == 0 ) // revisa que sean colineales 
		if ( cmp( pq * pr ) <= 0 ) return true; // revisa que este al medio 
	return false;
}


bool intersect( Point a1, Point a2, Point b1, Point b2 ){

	int a =  ccw2( a1 , a2, b1 ) * ccw2( a1, a2, b2);
	int b =  ccw2( b1 , b2, a1 ) * ccw2( b1, b2, a2);
	if ( a > 0 || b > 0 ) return false;
	if ( a < 0 && b < 0 ) return true;
	return onSeg( a1, b1, b2 ) || onSeg( a2, b1, b2 ) || onSeg( b1, a1, a2 ) || onSeg( b2, a1, a2 ) ;
}


Point crossPoint( Point a1, Point a2, Point b1, Point b2 ) {
	// chekar si se intersecan antes
	double A = (a2-a1) % (b2-b1) ;
	double B = (a2-a1) % (a2-b1) ;

	double t = B / A;
	if ( fabs(A) < EPS && fabs(B) < EPS ) return b1;
	return b1 + (b2 - b1) * t; // P(t) = a + ( b-a ) * t
}

Int puntosEncima( Point A, Point B ){
	Int xx =  A.x - B.x, x, y, yy = A.y - B.y;
	if ( xx == 0 && yy == 0 ) return 0;
	Int mcd =__gcd(abs(xx),abs(yy));
	x = xx/ mcd , y = yy/ mcd;
	if ( xx ) return xx/x - 1;
	return yy/y - 1;
}


// sweep line

//


//pendiente
double slope( Point a, Point b ){
	if ( a.x == b.x ) return -1e9;
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return dy / dx;
}
int DEB = 0;
Point max_slope( Point p1, Point p2, Point piv, int k = 0 ){
	int t;
	if ( p1 < piv ) return p2;
	else if ( p2 < piv ) return p1;
	
	if ( DEB ){
		cout <<"prev-->>>> "<< piv.x <<" " << piv.y << endl;
		cout <<"next_prev-->>>> "<< p1.x <<" " << p1.y << endl;
		cout <<"cross-->>>> "<< p2.x <<" " << p2.y << endl<<endl;
	}
	double s1 = slope( piv, p1 );
	if ( s1 < -1e8 ) return p2;
	double s2 = slope( piv, p2 );
	if ( s1 < -1e8 ) return p2;

	
	if ( (t = cmp(s1,s2 )) == 0 ){

		if ( dist(piv,p1) < dist( piv,p2 ) ){
			return p1;
		}
		return p2;
	}
	if ( t > 0 ) return p1;
	return p2;

}


//Poligonos
double area( Poly p ){
	double res = 0.0;
	int n = p.size();
	for( int i = 0; i < n; i++){
		res += p[ i ] % p[ ( i + 1 ) % n ];
	}
	return fabs(res / 2.0 );
}



int main(){

	int n;
	while(scanf("%d",&n) && n != -1 ){
		Poly P;
		map<Point,int> ID;
		map<Point,int> V;
		map<int,int> next;
		vector<pair<Point,Point> > seg;
		int it = 0, id = 0;
		for( int i = 0; i < n; i++ ){
			int I,D,H;
			scanf("%d%d%d",&I,&D,&H);

			Point izq = Point(I, 0 ); 
			Point punta = Point( (I+D)/2.0 , H) ; 
			Point der = Point(D, 0 ); 

			
			V[izq]++;
			V[punta]++;
			V[der]++;
			
			if ( !ID.count( izq )){
				izq.id = id;
				ID[ izq ] = id;
				id++;
				P.push_back( izq );
			}else{
				izq.id = ID[izq];
			}
			if ( !ID.count( punta )){
				punta.id = id;
				ID[ punta ] = id;
				P.push_back( punta );
				id++;
			}else{
				punta.id = ID[punta];
			}
			if ( !ID.count( der )){
				der.id = id;
				ID[ der ] = id;
				id++;
				P.push_back( der );
			}else{
				der.id = ID[der];
			}


			seg.push_back( make_pair( izq, punta ) );
			seg.push_back( make_pair( punta, der ) );

			if ( !next.count( izq.id ) ) next[izq.id] = punta.id ;
			else{
				if ( next[izq.id] != -1 ){ 
					Point mxsl = max_slope( izq , P[next[izq.id]], punta );
					next[ izq.id ] = mxsl.id;
				}else{
					next[ izq.id ] = punta.id;
				}
			}

			if ( !next.count( punta.id ) ) next[punta.id] = der.id ;
			else{
				Point mxsl = max_slope( punta , P[next[punta.id]], punta );
				next[ punta.id ] = mxsl.id;
			}
			if ( !next.count( der.id ) ) next[der.id] = -1;
			else{
				Point mxsl = max_slope( der , P[next[der.id]], der );
				next[ der.id ] = mxsl.id;
			}
					

			it += 3;

		}

		sort( seg.begin(), seg.end() );

		for( int i = 0; i < seg.size(); i++ ){
			int prev , first = true;
			for( int j = i + 1; j < seg.size(); j++ ){
				if ( intersect( seg[i].first, seg[i].second, seg[j].first, seg[j].second ) ){
					Point cross = crossPoint( seg[i].first, seg[i].second, seg[j].first, seg[j].second );
					if ( V[cross] > 0 ) continue;
					if ( !ID.count( cross ) )  {
						cross.id = id;
						ID[cross] = id; 
						P.push_back( cross );
						id++;
					}else{
						cross.id = ID[cross];
					}
					if (DEB	){
					cout << "Segmentos " << endl;
					cout << "seg 1 :" << endl;
					cout << seg[i].first.x <<" " << seg[i].first.y << endl;
					cout << seg[i].second.x <<" " << seg[i].second.y << endl;

					cout << "seg 2 :" << endl;
					cout << seg[j].first.x <<" " << seg[j].first.y << endl;
					cout << seg[j].second.x <<" " << seg[j].second.y << endl;
					cout << endl;
					
					
					Point mxsl = max_slope( P[ next[ seg[i].first.id ]] , P[cross.id], seg[i].first );
					next[ seg[i].first.id ] = mxsl.id;

					mxsl = max_slope( P[ next[ seg[j].first.id ]] , P[cross.id], seg[j].first );
					next[ seg[j].first.id ] = mxsl.id;
					
					mxsl = max_slope( seg[i].second, seg[j].second, P[ cross.id ]  );
					next[ cross.id ] = mxsl.id;
					if ( !first && cross != seg[i].first){
						mxsl = max_slope( P[ next[prev] ], cross , P[ prev ] ,1 );
						next[ prev ] = mxsl.id;
					}
					first = false;
					prev = cross.id;
					it++;
					}
				}
			}
		}

		Poly res;
		Point ini = P[0];
		for( int pos = 0; pos < P.size(); pos++){
			if ( DEB ){			
			cout << P[pos].x<<" " << P[pos].y<<" " << endl;
			if ( next[pos] >= 0 )
			cout << P[next[pos]].x<<" " << P[next[pos]].y << endl;
			cout << endl;
			}
			ini = min( ini, P[pos] );
		}
		if ( DEB )cout <<"--"<<endl;
		int pos = ini.id, k = 0;

		
		while( pos >= 0 && it-- ){
			if ( DEB )cout << P[pos].x<<" " << P[pos].y << endl;
			res.push_back( P[pos]);
			pos = next[ pos ]; 
		}

		printf("%.2lf\n", area( res ));
	}

	return 0;
}



