#include<iostream>
#include<cstdio>
using namespace std ;

int sum( int g[][25],  int p, int q, int r, int s ){
	int res = 0;
	for( int i = p; i <= r; i++){
		for( int j = q ; j <= s; j++){
			if ( g[i][j] == 0 ) return -1;
			res++; 
		}
	}
	return res;
}

int main(){
	int g[25][25];
	int N , M;
	scanf("%d%d",&N,&M);
	for( int i = 0; i < N; i++)
		for( int j = 0; j < M; j++)
			scanf("%d",&g[i][j]);
	
	int res = 0;
	int p1x = 0 , p1y = 0, p2x = 0, p2y = 0;
	for( int i = 0; i < N; i++){
		for( int j = 0; j < M; j++){
			for( int k = i ; k < N; k++){
				for( int l = j ; l < M; l++){
					int tmp = sum( g, i , j, k , l ) ;
					if ( tmp == -1 ) continue;
					if ( tmp > res ){
						res = tmp;
						p1x = i; p1y = j;
						p2x = k; p2y = l;
					}
				}
			}
		}
	}
	printf("La submatriz estará definida por los puntos  (%d, %d),(%d,%d),(%d,%d) y (%d,%d) con área %d.\n ", p1x, p1y, p1x, p2y, p2x, p2y, p2x, p1y, res);


	return 0;
}
