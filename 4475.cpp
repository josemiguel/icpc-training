#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std ;

struct state{
	int sec; 
	char p;
	state(){}
	state(int sec, char p): sec(sec), p( p ) {}
	bool operator < ( const state &x) const{
		if ( x.sec == sec ){
			return p == 'E';
		}
		return sec < x.sec;
	}
};

int main(){
	int n;	
	while( scanf("%d",&n ) && n){
		int hh,m,s;
		char p;
		int e = 0;
		vector<state> h;
		for( int i = 0; i < n; i++){
			scanf("%d:%d:%d %c",&hh,&m,&s,&p);
			h.push_back( state( hh*3600+m*60+s, p ));
			e += p == 'E';
		}
		sort( h.begin(), h.end() );

		int k = h.size(), res = 0, tmp = 0;

		for( int i = 0; i < k; i++){
			if ( e < k/2 and h[i].p == '?' ) e++, h[i].p = 'E';
			else if ( h[i].p == '?' ) h[i].p = 'X';

			if ( h[i].p == 'E') tmp++;
			else tmp--;

			res = max( res , tmp );
		}
		printf("%d\n", res);
	}

	return 0;
}
