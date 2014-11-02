#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std ;
#define count( x ) __builtin_popcount( x )
struct point{
	int x, y;
	int v, l , id;
	point(){}
	point(int x, int y) :x(x),y(y){}
	int operator %(point p){
		return x * p.y - y * p.x ;
	}
	point operator -( point p ){
		return point( x - p.x, y - p.y );
	}
	bool operator < ( const point &p )const{
		if( x == p.x){
			return y < p.y;
		}
		return x < p.x;
	}
};

typedef vector<point> poly;

int ccw( point a, point b, point c){
	return ( b - a ) % ( c - a);
}

poly hull( poly p ) {
	int k = 0, n = p.size();
	sort( p.begin(), p.end());
	poly h( 2 * n );
	for(int i = 0; i < n; i++){
		while( k >= 2 && ccw( h[k-2], h[k-1], p[i] ) <= 0 ) k--;
		h[ k++ ] = p[ i ];
	}
	int tmp = k + 1;
	for(int i = n - 2; i >= 0; i--){
		while( k >= tmp && ccw( h[k-2], h[k-1], p[i] ) <= 0 ) k--;
		h[ k++ ] = p[ i ];
	}
	h.resize( k );
	return h;
}

double dist( point a, point b ){
	return hypot( a.x - b.x , a.y - b.y );
}
double dist( poly p ){
	double res = 0;
	for(int i = 0; i < p.size() - 1; i++){
		res += dist( p[i], p[i + 1]);
	}
	return res;
}

int main(){

	int n , r = 1;
	while( scanf("%d",&n) && n ){
		if (r!=1 ) putchar( 10 );

		poly p(n) ;
		for(int i = 0; i < n; i++){
			scanf("%d%d%d%d",&p[i].x, &p[i].y, &p[i].v,&p[i].l);
			p[i].id = i + 1;
		}

		printf("Forest %d\nCut these trees:",r++);
		int best_val = 1 << 30;
		int best_mask =  ( 1 << n ) - 1;
		double best_len = 0;
		for(int mask = 1; mask < ( 1 << n ) ; mask++){
			if ( count( mask ) < 3 ) continue;
			poly tmp;
			int len = 0;
			int val = 0;
			for(int i = 0; i < n; i++){
				if ( mask & ( 1 << i ) ){
					tmp.push_back( p[ i ] );
				}else{
					len += p[ i ].l;
					val += p[ i ].v;
				}
			}
			double dist_tmp = dist( hull ( tmp, mask ) );
			if ( len >= dist_tmp ) {
				if ( val < best_val ){
					best_val = val;	
					best_mask = mask;
					best_len = dist_tmp;
				}
				if ( val == best_val ){
					if (count( mask ) < count( best_mask ) ){
						best_val = val;
						best_mask = mask;
						best_len = dist_tmp;
					}
				}
			}
		}
		double len = 0;
		for(int i = 0; i < n; i++){
			if(!( best_mask & ( 1 << i ) )) {
				len += p[i].l;
				printf(" %d",p[i].id);
			}
		}
		printf("\nExtra wood: %.2lf\n", len - best_len);


	}

	return 0;
}
