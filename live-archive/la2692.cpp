#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std ;
string s;
int dp[105];
int F( int pos, int car ){
	if ( pos == s.size() ) return 0;
	if ( dp[pos][car] != -1 ) return dp[pos][car];
	int res = 1 << 30;
	if ( pos + 2*car >= s.size() ) continue;
	sub( pos, car ) == sub( pos + car, car );
	res = min( res , car + 2 + cant( i ) + F( pos, car ) );


}

int main(){

	while( cin >> s ){
		memset( dp,-1,sizeof dp);
		F( 0 );
	
	}

	return 0;
}
