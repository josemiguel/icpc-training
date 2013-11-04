#include<iostream>
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

Point P[102];
int main(){

	int T;
	scanf("%d",&T);
	while( T-- ){
		int r, n;
		scanf("%d %d",&r, &n);
		for( int i = 0; i < n; i++){
			scanf("%d %d", &P[i].x, &P[i].y);
		}
		sort( P , P + n );
		Point H[ 2 * n ];
		int k = 0;
		for( int i = 0; i < n; i++){
			while( k >= 2 && ccw( H[k-2], H[k-1], P[i] ) <= 0 ) k--;
			H[k++] = P[i];
		}
		int t = k + 1;
		for( int i = n - 2 ; i >= 0 ; i--){
			while( k >= t && ccw( H[k-2], H[k-1], P[i] ) <= 0 ) k--;
			H[k++] = P[i];
		}
		printf("%d %d\n",r, k - 1);

		for( int i = k -1 ; i >= 1 ; i-- ){
			printf("%d %d\n", H[i].x, H[i].y );
		}	
	}

	return 0;
}

