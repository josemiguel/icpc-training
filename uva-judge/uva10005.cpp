#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef pair<int,int> Point;
#define x first
#define y second

double dist( int x, int y , int xx, int yy ){
	return hypot( x - xx, y - yy ); 
}

int main(){
	int n;
	while( scanf("%d",&n ) && n ){
		Point p[n];
		for( int i = 0; i < n; i++ ) scanf("%d %d",&p[i].x,&p[i].y);
		double r;
		scanf("%lf",&r);
		double best = 0, cx= 0 , cy = 0;
		for( int i = 0; i < n; i++){
			cx += p[i].x / (double) n;
			cy += p[i].y / (double) n;
		}

		for( int i = 0; i < n; i++){
			best = max(best, dist( p[i].x, p[i].y , cx, cy ));
		}

		if ( r >= best ){
			puts("The polygon can be packed in the circle.");
		}else{
			puts("There is no way of packing that polygon.");
		}
	}

	return 0;
 
