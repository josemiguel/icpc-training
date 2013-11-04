#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std ;
char s[50005];

int f( char c ){
	if ( c >= 'A' && c <='F')
		return	c - 'A' + 10;
	return c -'0';
}
vector<char > a ;
int main(){

	int T;


	scanf("%d",&T);
	while( T--){
		int r, b;
		scanf("%d %d %s",&r, &b, s );
		char c;
		a.clear();
		
		for( int i = 0; i < 2*b; ){
			int hi = f(s[i]);
			int lo = f(s[i+1]);
			int n;
			if ( (hi & ( 1 << 3 )) == 0 ) {
				i+=2;
				n = (hi << 4) | lo ;
				n+=1;
				for( int j = 0; j < n; j++){
					a.push_back ( s[i++] );
					a.push_back ( s[i++] );
				}
			}
			else{
				hi ^= (1<<3);
				n = (hi << 4) | lo ;
				n+=3;
			
				for( int j = 1; j <= n; j++){
					a.push_back( s[i+2] );
					a.push_back( s[i+3] );
				}
				i+=4;
			}
		}
		printf("%d %d\n", r, a.size()/2 );
		for( int i = 0; i < a.size(); i++ ) {
			putchar(a[i]);
			if ( i == a.size() - 1 ) putchar(10);
			else if ( (i+1)%80 == 0 ) putchar(10);
			
		}

	}

	return 0;
}
