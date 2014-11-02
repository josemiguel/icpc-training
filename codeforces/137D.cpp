#include<iostream>
#include<string>
using namespace std;
int dp[505][505];
string s;
int F( int i, int j){
	if ( i > j ) return 0;
	if ( i == j ) return 1;
	int res = 1 << 30;
	
	if ( s[i] == s[j] ) return dp[i][j] = F(i+1,j-1);

	return dp[i][j] = min(res, 1 + min(  F(i+1,j-1 ) );



}

int main(){


	cin >> s;
	memset( dp,-1,sizeof dp);
	cout << F( 0, s.size()-1) << endl;
	pathF( 0, s.size()-1);

	return 0;
}
