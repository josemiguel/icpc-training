#include<cstdio>
#include<algorithm>
using namespace std ;
typedef long long Int;
int v[100002];


Int lcm( Int a, Int b, Int c ){
	Int k = (a*b)/__gcd( a, b );
	k = (k*c)/__gcd( c , k );
	return k;
}

void solve( Int N ){
	int n = 0;
	for( int i = 1; i <= 1000000 && i <= N ; i++){
		if ( N % i ) continue;
		v[ n++ ] = i;
	}
	bool ya = false;
	for( int i = 0; i < n - 2 ; i++)
		for( int j = i+1; j < n - 1 ; j++)
			for( int k = j+1; k < n  ; k++){
				if( v[k] - v[i] > 25 ) break;
				if ( lcm( v[i], v[j], v[k]) != N ) continue;
				ya = true;		
				printf("%d %d %d\n", v[i], v[j], v[k] );
			}
	if ( !ya) {
		puts("Such bells don't exist");
	}
	putchar(10);
}

int main(){
	Int n;
	int r = 1;
	while( scanf("%lld",&n ) && n ){
		printf("Scenario %d:\n",r++);
		solve( n );
	}
}
