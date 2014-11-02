#include<cstdio>
using namespace std;
bool usd[ 1 << 26 ];
bool dp[ 1 << 26 ];
bool F(int n, int len) {
	if ( len == 0 ) return true;
	if ( usd[ n ] ) return dp[n];
	for (int i = len; i >= 2; i--) {
		for (int j = 0; j <= len - i ; j++) {
			int m = (n >> j) & ( ( 1 << i ) -1);
			if (m == 0 || m == ( 1<< i ) - 1) {
				int mask = n & ( (1 << j) - 1) | ( (n >> ( i + j )) << j);
				if (F(mask, len - i)) {
					usd[ n ] = true;
					return dp[ n ] = true;
				}
			}
		}
	}
	usd[ n ] = true;
	return dp[ n ] = false;
}
int main() {
	int T;
	scanf("%d\n",&T);
	while( T--) {
		int n = 0, len = 0;;
		char c;
		while( (c = getchar()) && c!='\n'){
			n |= ( c == 'a' ) << len; len++;
		}
		n |= 1 << len;
		printf("%d\n", F( n, len ) );
	}
}

