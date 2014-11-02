#include<iostream>
#include<cstring>
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


//Poligonos

double area( Poly &p ){
	double res = 0.0;
	int n = p.size();
	for( int i = 0; i < n; i++){
		res += p[ i ] % p[ ( i + 1 ) % n ];
	}
	return fabs(res / 2.0 );
}


int dp[ 55 ][ 55 ];
int SP ;
Point p[ 55 ];

int areat( int i , int j , int k ){
	return ccw(p[ i ] ,p[ j ] ,p[ k ]);
}
int n;
int F( int a, int b ){
	if ( b - a <= 1 ) return 0;
	if ( dp[a][b] != -1 ) return dp[a][b];
	int res = 1 << 30;
	for( int i = a + 2; i <= b; i++ ){
		int SA = areat( a, ( a + 1) % n , i);
		if ( (SA <= 0 && SP <= 0) || ( SA >= 0 && SP >= 0 ) ){
			int sSA = fabs( SA );
			res = min ( res, max( max(sSA, F( (a + 1)%n, i )) ,  F( i , b ) ) );
		}
	}
	return dp[a][b] = res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	while( runs-- ){
		int SP = 0;
		scanf("%d",&n);
		for( int i = 0; i < n; i++ ){
			scanf("%lf %lf",&p[i].x,&p[i].y);
			if( i > 0 ) {
				SP += areat( 0 , i-1 ,i );
			}
			dp[i][(i+1)%n] = 0;
		}
		for( int i = 2; i < n; i++){
			for( int j = 0; j < n; j++){
				int tmp = 1 << 29;
				for( int k = 1 ; k < i ; k++){
					int SA = areat( j,(j+k)%n, (j+i)%n);
					if ( (SA <= 0 && SP <= 0) || ( SA >= 0 && SP >= 0 ) ){
						int sSA = fabs ( SA );
						tmp = min(tmp , max( sSA, max( dp[ ( j + k ) % n][( j + i ) % n] , dp[ j ][( j + k ) % n] ) ) );
					}
				}
				dp[j][ (j + i) % n] = tmp;
			}
		}
		printf("%.1lf\n", dp[1][0]/2.0);
	}
}


