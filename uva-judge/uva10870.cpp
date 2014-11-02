#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

int mod;
int inline sum ( const int &x, const int y = 0) {
	return ((x % mod) + (y % mod) ) % mod;
}
int inline mult( const int &x , const int &y ){
	return (sum(x) * sum(y)) % mod;
}

struct Matrix{
	int a[ 16 ][ 16 ], n, m ;
	Matrix(){
		memset( a , 0 , sizeof a );
	}
	Matrix( int n, int m ) : n ( n ), m ( m ){
		memset( a , 0 , sizeof a );
	}
	Matrix operator *( Matrix B ){
		Matrix res( n, B.m );
		for( int i = 0; i < n; i++)
			for( int j = 0; j < B.m; j++)
				for( int k = 0; k < m; k++)
					res.a[i][j] = sum( res.a[i][j] , ( mult( a[i][k] , B.a[k][j] ) ) );
		return res;
	}

};

Matrix p;
Matrix exp( int n ){
	if ( n <= 1 ) return p;
	Matrix b = exp( n / 2 );
	b = b * b;
	if ( n & 1 ) return b * p;
	return b ;
}

int main(){
	int d, n ;
	while( scanf("%d%d%d",&d,&n,&mod) && d + n + mod ){
		p.n = d, p.m = d;
		int k = 1;
		for( int i = 0; i < d ;i++ ) {
			scanf("%d",&p.a[0][i]);
			if ( k < d )  p.a[ k++ ][ i ] = 1;
		}
		Matrix res = exp( n - d ), T( d, 1 );
		for( int i = d - 1; i >= 0; i-- ) scanf("%d",&T.a[ i ][ 0 ]);

		if ( n > d ){
			int ans = 0, tmp;
			T = res * T;
			printf("%d\n",T.a[0][0]);

		}else{
			printf("%d\n",T.a[ d - 1 - ( n - 1 )][ 0 ]);
		}
	}

	return 0;
}
