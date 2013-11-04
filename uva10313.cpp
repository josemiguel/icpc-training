#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30
typedef long long Int;
int n;
Int dp[ 302 ][ 302 ];
Int memo[ 302 ][ 302 ];
int L;
Int F( int T, int u ){
	if ( T == 0 ) return 1; 
	if ( T <= 0 ) return 0;
	if ( dp[T][u] != -1) return dp[T][u];
	Int res = 0;
	for( int  i = u ; i <= L; i++){
		res += F( T - i, i );
	}
	return dp[T][u] = res;
}


Int f( int n , int up){
	if ( up == 0 ) return memo[ n ][ up ] = 0;
	if ( memo[ n ][ up ] != -1) return memo[ n ][ up ];
	L = up;
	n = n >= 301 ? 300 : n;
	for ( int i = 0; i <= n; i++){
		for( int j = 0; j <= up; j++){
			dp[ i ][ j ] = -1;
		}
	}

	return memo[ n ][ up ] = F( n , 1);
}

int main(){
	char s[20];
	memset( memo, -1, sizeof memo );
	while(fgets(s,20,stdin)){
		int n ,l1 = 0,l2 = 0;
		int inp = sscanf(s,"%d%d%d",&n,&l1,&l2);
		
		if (inp == 1){
			l1 = 1;
			l2 = n;
		}else if (inp == 2){
			l2 = l1;
			l1 = 1;
		}
		long long res = f(n, l2 ) - f(n, l1 - 1);
		printf("%lld\n",res);
	}
	
	return 0;
}
