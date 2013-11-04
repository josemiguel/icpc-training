#include<iostream>
#include<string>
#include<cstring>

using namespace std;
string s;
int res;

int f(int a, int b){
	if (s[a] == s[b]) return 1;
	if (s[a] == '}' && s[b] == '{') return 2;
	return 0;
}
int dp[2005][2005];
int stable(int ini, int fin){
	if (ini + 1 == fin) return f(ini,fin);
	int res = 1<<30;
	if (dp[ini][fin] != -1) return dp[ini][fin];
	if (s[ini] == '{' && s[fin] == '}') res = stable(ini+1,fin-1);
	for(int i = ini+2; i <= fin; i+=2){
		res = min(res,stable(ini,i-1) + stable(i,fin));
	}
	return dp[ini][fin] = res;
}

int main(){
	int r=1;
	while(getline(cin,s) && s[0] != '-'){
		memset(dp,-1,sizeof dp);
		cout<<r++<<". "<<stable(0,s.size()-1)<<endl;

	}
	return 0;
}
