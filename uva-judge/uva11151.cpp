#include<iostream>
#include<cstring>
#include<string>
using namespace std;


string s;
int dp[1005][1005];

int F(int i, int j){
	if (i>j) return 0;
	if (i==j) return 1;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j]) return dp[i][j] = 2 + F(i+1,j-1);
	return dp[i][j] = max(F(i+1,j), F(i,j-1));
}

int main(){
	int T = 1,n;
	cin>>n;
	cin.ignore();
	while(getline(cin,s) && n--){
		memset(dp,-1,sizeof dp);
		cout<<F(0,s.size()-1)<<endl;
	}
	return 0;
}
