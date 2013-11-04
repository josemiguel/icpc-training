#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std ;
int n,m;
int h[502][502];

int f( int x, int v  ){
	int *id =(int *) lower_bound( h[x] , h[x] + m, v );
	if ( id == NULL ) return -1;
	return id - h[x];
}

int g( int x, int y, int v ){
	int lo = 0 , hi = min( n - 1 - x ,m - 1 - y);
	while( lo <= hi ){
		int mid = (lo+hi)/2;
		if ( h[x + mid ][ y + mid] <= v ){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	return lo;
}

int main(){

	while( scanf("%d %d",&n,&m) && n+m){
		for( int i = 0; i < n; i++)
			for( int j = 0; j < m; j++)
				scanf("%d",&h[i][j]);
		int q;
		scanf("%d",&q);
		while(q--){
			int l,u;
			scanf("%d %d",&l,&u);
			int res = 0;
			for( int i = 0; i < n; i++){
				int j = f( i , l );
				if ( j < 0 ) break;

				int k = g( i , j , u );
				res = max( res, k  );
			}
			printf("%d\n", res);
		}
		printf("-\n");
	}

	return 0;
}
