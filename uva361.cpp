#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

bool co ( point a, point b , point c){
	if ( ccw( a, b, c ) == 0 ){
		if ( ( b - a ) * ( c - a) <= 0) return true;
	}
	return false;
}

bool in ( point p, poly t ){
	int n = t.size();
	int cross = 0;
	for(int i = 1; i <= n; i++){
		point q = t[i-1];
		point r = t[i%n];
		if ( co( p, q, r ) ) return true;
		if ( q.y > r.y ) swap( q, r);
		if ( q.y < p.y && r.y >= p.y && ccw( p, q, r ) > 0 ) cross++;
	}
	return cross % 2;
}

bool usd[ 1005 ][ 1005 ];

int main(){

	int c , r, o, cases = 1;
	
	while( scanf("%d%d%d",&c,&r,&o) && c+r+o  ){
		
		vector< point > O( o );
		poly C( c ) , R( r );

		for(int i = 0; i < c; i++ ) scanf( "%d %d" ,&C[i].x,&C[i].y);
		
		for(int i = 0; i < r; i++ ) scanf( "%d %d" ,&R[i].x,&R[i].y);
		
		for(int i = 0; i < o; i++ ) scanf( "%d %d" ,&O[i].x,&O[i].y);


		C = hull( C );
		R = hull( R );
		

		printf( "Data set %d:\n", cases++);
		for(int i = 0; i < o ; i++){
			if ( c > 2 && in( O[i], C )){
				printf("     Citizen at (%d,%d) is safe.\n", O[i].x, O[i].y);
			}else if ( r > 2 && in ( O[i], R ) ){
				printf("     Citizen at (%d,%d) is robbed.\n",O[i].x,O[i].y);
			}else{
				printf("     Citizen at (%d,%d) is neither.\n",O[i].x, O[i].y);		
			}
		}

		putchar( 10 );	
	}

	return 0;
}

