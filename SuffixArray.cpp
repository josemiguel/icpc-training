#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXN 30000

int p[MAXN], r[MAXN], h[MAXN], t, n; 
char s[MAXN];
bool comp(int i,int j){ return p[i + t] < p[j + t]; }

void build(){
	int bc[256];
	memset( bc, 0, sizeof bc);	
	for( int i = 0; i < n; i++ ) bc[ s[i] ]++;
	for( int i = 1; i < 256; i++ ) bc[i] += bc[i-1];
	for( int i = 0; i < n; i++ ) r[--bc[s[i]]] = i;
	for( int i = 0; i < n; i++ ) p[i] = bc[s[i]]; 
	
	for(t = 1; t < n; t = t << 1  ){
		for(int i = 0 ,j = 1; j < n; i = j++){
			while( j < n && p[r[i]] == p[r[j]] ) j++; 
			if( j == i + 1 ) continue;
			int *ini = r + i, *fin = r + j; 
			sort(ini, fin, comp); 
			int num = i, pri = p[*ini + t], pk;
			for(; ini < fin; p[*ini++] = num ){
				if( ((pk = p[*ini+t]) == pri) || (i <= pri && pk < j) ){}
				else pri = pk, num = ini - r;
			}
		}
	}
}


int main(){

	int runs;
	scanf("%d\n",&runs);
	while( runs-- ){
		gets( s );
		int sz = strlen( s );
		bool cagao = true;
		for(int i = 1; i < sz; i++){
			if ( s[i-1] != s[i] ) {cagao = false;break;}
		}
		if ( cagao ){
			printf("1\n");
			continue;
		}

		n = 2 * sz;
		for( int i = 0; i < sz; i++ ){
			s[ sz + i ] = s[ i ] ;
		}

		build( );
		for(int i = 0; i < n; i++){
			if ( r[ i ] < sz ){
				printf("%d\n",r[ i ]+1);
				break;
			}
		}
	}

	return 0;
}
