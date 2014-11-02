#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

struct Point{
	int x, y;	
	Point(){}
	Point( int x, int y ):x(x), y(y){}
	bool operator <( Point const &p ) const{
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
};

struct Segment{
	Point izq, der;
	int id, L;
	Segment(){}
	Segment( int a, int b, int c, int d ){
		izq = Point( a, b);
		der = Point( c, d);
		L = abs( c - a );
	}
	bool operator < ( Segment const &s ) const{
		return izq < s.izq;
	}

	bool arriba( Segment s ){
		if ( izq.y > s.izq.y && der.y > s.izq.y ) return true;
		if ( izq.y > s.der.y && der.y > s.der.y ) return true;
		return false;
	}
	bool setoca ( Segment s ){
		if ( s.izq.x >= izq.x && s.izq.x <= der.x ) return true;
		if ( s.der.x >= izq.x && s.der.x <= der.x ) return true;
		return false;
	}

};
bool cmp( Segment a, Segment b ){
	return a.id < b.id;
}

int intersect( Segment a, Segment b ){
	int m = 1, tmp = 0;
	if ( b.arriba( a ) ) {
		m = -1;
		swap( a , b );
	}

	if ( b.setoca( a ) ){
		int l = a.izq.x - b.izq.x;
		int r = a.der.x - b.der.x;
		if ( l > 0 ) tmp += l;
		if ( r < 0 ) tmp -= r;
	}
	return tmp * m;
}

int main(){
	int runs;

	cin >> runs;
	while( runs--){
		int n ;
		cin >> n;
		vector<Segment> v( n );
		for( int i = 0; i < n; i++ ){
			int a, b, c , d;
			cin >> a >> b >> c >> d;
			v[i] = Segment( a, b, c, d );
			v[i].id = i;
		}/*
		sort( v.begin(), v.end() );
		int j = 1;
		for( int i = 0; i < v.size() && j < v.size(); ){
			int l = intersect( v[i], v[j] );
			if ( l == 0 ) i++, j++;
			else{
				if ( l < 0 ) v[i].L += l, j++;
				if ( l > 0 ) v[j].L -= l;
				i++;
			}
		}
		sort( v.begin(), v.end() , cmp );*/

		for( int i = 0; i < v.size(); i++){
			for( int j = i + 1; j < v.size(); j++){
				int l = intersect( v[i], v[j] );
				if ( l < 0 ) v[i].L +=l ;
				if ( l > 0 ) v[j].L -=l ;
			}
		}


		for( int i = 0; i < v.size(); i++){
			cout << v[i].L << endl;
		}
	}

	return 0;
}
