#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std ;

struct Point{
	int x, y, id;
	double ang;
	Point(){}
	bool operator < (const Point &p ) const{
		return ang < p.ang;
	}
	
};
Point p[10005];
int main(){

	int runs;
	scanf("%d",&runs);
	while( runs-- ){
		int n;
		scanf("%d",&n);
		
		double cx = 0.0, cy = 0.0;
		for( int i = 0; i < n; i++){
			scanf("%d %d",&p[i].x,&p[i].y);
			p[i].id = i;
			cx += p[i].x / (double) n;
			cy += p[i].y / (double) n;
		}
		for( int i = 0; i < n; i++ ){
			p[i].ang = atan2( p[i].y - cy , p[i].x - cx);
		}
		sort( p , p + n  );	
		for( int i = 0; i < n; i++){
			if ( i ) putchar(' ');
			printf("%d",p[i].id);
		}
		putchar(10);
		
	}
	

	return 0;
}
