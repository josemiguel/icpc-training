#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct point{
	double x, y;
	point(){}
	point(double x, double y) : x(x) ,y(y){}
	point operator - ( point p ){
		return point( x - p.x , y - p.y);
	}
    	double operator %(point p){
		return x * p.y - y * p.x;
	}
	double operator *(point p){return x*p.x+y*p.y;}	
};

double ccw( point a, point b, point c ){
	point p1 = b - a;
	point p2 = c - a;
	return p1 % p2;
}
inline int cmp(double a, double b=0)
{
    if(fabs(a-b)<=1e-7) return 0;
        if(a<b) return -1;
	    return 1;
	    }
int co(point p, point q, point r){
    if(cmp((q-p)%(r-p))==0)
            if(cmp((q-p)*(r-p))<=0) return 1;
    return 0;
}

bool in( point p, point t[], int n){
	double sum = 0.0;
	
	int cross = 0;
	for( int i = 1; i <= n ; i++){
		point q = t[ i - 1 ];
		point r = t[ i % n ];
		if ( q.y > r.y ) swap( q, r );
		if ( q.y < p.y && r.y >= p.y && ccw( p, q, r ) < 0) cross++;
	}
	return cross % 2;
}

int main(){
	int n;
	while( cin >> n && n){
		point t[ n + 1 ];
		for(int i = 0; i < n; i++){
			cin >> t[i].x >> t[i].y ;
		}
		point p;
		cin >> p.x >> p.y;
		if ( in( p, t , n ) ){
			cout << "T" << endl;
		}else{
			cout << "F" << endl;
		}
	}
}
