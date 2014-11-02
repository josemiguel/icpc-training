#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s,t;
int dp[25][25];
int F(int i, int j){
	if (i == s.size() || j == t.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int tmp = 1<<30;
	if (s[i] == t[j]) tmp = F(i+1,j+1);
	else{
		int a = 1 + F(i+1,j);
		int b = 1 + F(i,j+1);
		tmp = min(tmp,min(a,b));
	}
	return dp[i][j] = tmp;
}

void path(int i, int j){
	if (i == s.size() || j == t.size()) return 0;
	if (s[i] == t[j]){
		F(i+1,j+1);
	}else{
		int a = dp[i+1][j];
		int b = dp[i][j+1];
		
		if (a != -1 && b != -1){
			if (a < b){
				
			}
		}
		
	}
	
}

int main(){
	while(cin>>s && s[0] != '#'){
		cin>>t;
		memset(dp,-1,sizeof dp);
		cout<<F(0,0)<<endl;
	}	
	return 0;
}
