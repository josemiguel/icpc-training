#include<iostream>
#include<cstring>
#include<string>

using namespace std;
string s;

int dp[ 2010 ][ 2010 ];
int izq[ 2010 ],der[ 2010 ];

typedef long long Int;

int F(int i, int j){
    if ( i >= j) return true;
    if ( dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = F(i+1,j-1) && s[i] == s[j];

}
int main(){
	memset(dp,-1,sizeof(dp));

	cin >> s;
	for( int i = 0; i < s.size(); i++){
		for( int j = i ; j < s.size(); j++){
			if( F( i , j ) ){
				der[ i ]++; izq[ j ]++;
			}
		}
	}
	Int res = 0;
	for( int i = 1; i < s.size(); i++) der[s.size() - i - 1] += der[s.size() - i];
	for( int i = 0; i < s.size()-1; i++) res += izq[i] * (der[ i + 1] );
	cout << res << endl;

	return 0;
}

