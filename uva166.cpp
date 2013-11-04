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
int coins[] = {5, 10, 20, 50, 100, 200};
const int len = 6;
int dp[6][1055];
int sz[6],n;

int F( int last, int T ){
	if ( T == 0 ) return 0;
	int res = 1 << 28;
	if ( T < 0 ) return res;
	if ( dp[last][T] != -1 ) return dp[last][T];
	for(int i = last; i < len; i++){
		res = min( res, 1 + F( i, T - coins[ i ] ) );
	}
	return dp[last][T] = res;
}


int next( int mask , int pos ){
	for(int i = pos+1; i < len; i++){
		if ( mask & (1<<i) ) return i;
	}
	return -1;
	
}

int G( int mask , int i, int T) {
	if ( i == -1 && T >= n ) {
		return dp[0][T-n];
	}
	if ( i == -1 ) return 1<<30;
	int res = 1 << 30;
	for(int j = 1; j <= sz[ i ] ; j++){
		if ( T + j * coins[ i ] > 500 ) continue;
		res = min( res, j + G( mask, next( mask, i) , T + j * coins[ i ] ));
	
	}
	return res;
}

int main(){
	memset( dp, -1, sizeof dp);
	F( 0, 1050 );
	dp[0][0] = 0;
	while(1){
		int e = 0;
		for(int i = 0; i < len; i++){
			scanf("%d",&sz[i]);
			e += sz[i];
		}
		
		if ( !e ) break;
		int a, b;
		scanf("%d.%d",&a,&b);
		n = a * 100 + b;
		int res = 1 << 30;
		for(int i  = 1; i < ( 1 << len ); i++ ){
			bool cagao = false;
			for( int j = 0; j < len; j++){
				if ( i &( 1<< j) )
					if ( !sz[j] ){
						cagao = true;
						break;
					}
			}
			if ( !cagao ) res = min( res, G( i, next( i, -1 ) , 0 ) );;
		}		
		printf("%3d\n",res );
	}
	return 0;
}
