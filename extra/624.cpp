#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std ;
int N,M;
int dp[25][6005];

struct item{
	int val, id;
	item(){}
	item(int val, int id):val(val),id(id){}
	bool operator < (const item &a)const{
		return val < a.val;
	}
};
item a[25];
bool cmp( item a,  item b){
	return a.id < b.id;
}

int F(int pos, int T){
	if (pos == N) return 0;
	if (T <= 0) return 0;
	if (dp[pos][T] != -1) return dp[pos][T];
	int res = 0, p1 = 0, p2 = 0;
	if (T >= a[pos].val) p1 = 1 + F( pos + 1, T - a[pos].val);
	p2 = F( pos + 1, T);

	res = max(res, max(p1, p2) );
	return dp[pos][T] = res ;
}
item opt[25];int len ;
int path(int pos, int T){
	if ( pos == N || T <= 0 ) return 0;
	int res = 0;
	if ( F( pos + 1, T ) > F( pos + 1, T - a[ pos ].val)){
		res = max( res, path(pos + 1, T ) );
	}else{
		res = max( res, a[ pos ].val + path( pos + 1,T - a[ pos ].val ) );

		opt[ len++ ] = a[ pos ];

	}
	return res;

}

int main(){

	
	while( scanf("%d", &M) != -1 ){
		memset(dp,-1,sizeof dp);
		scanf("%d" , &N);
		
		for( int i = 0; i < N; i++ ) {
			scanf("%d", &a[i].val);
			a[i].id = i;
		}
		len = 0;
		sort( a, a + N );

		F(0,M);
		int res = path(0,M);
		sort( opt, opt + len, cmp );
		for(int i = 0; i < len; i++) printf("%d ",opt[i].val);
		printf("sum:%d\n", res );
	}

	return 0;
}
