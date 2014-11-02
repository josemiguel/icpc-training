#include<iostream>
#include<cstring>
using namespace std;

int dp[55][55];
string s;
int n;
int F(int u, int pos ){
	if ( u == n || pos == s.size()) return 0;
	if ( dp[u][pos] != -1)  return dp[u][pos];
	int res = 0;
	if ( s[pos] == 'T'){
		res = max( res, 1 + F(u + 1, pos + 1) );
	}else{
		res = max( res, F( u + 1, pos + 1));
	}
	res = max( res,(int)( s[pos] == 'F') +  F ( u , pos + 1) );
	return dp[u][pos] = res;


}

int main(){
	memset(dp,-1,sizeof dp);
	cin >> s >> n;
	
	cout << F(0,0) <<endl;

	return 0;
}
