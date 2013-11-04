#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int fail[100005];
void pre(string &p){
	int i = 0, j = -1;
	fail[i] = j;
	while( i < p.size() ){
		while( j >= 0 && p[i] != p[j] ) j = fail[j];
		i++; j++;
		fail[i] = j;
	}
}

int kmp(string &t, string &p){
	pre(p);
	int i = 0, j = 0;
	while( i < t.size()){
		while( j >= 0 && t[i] != p[j] ) j = fail[j];
		i++; j++;
		if ( j == p.size() ){
//			cout << t << "( "<< t.size() << ") " << p <<" ("<< p.size() <<") " << -1 << endl;
			return -1;
		}
	}
//	cout << t << "( "<< t.size() << ") " << p <<" ("<< p.size() <<") " << j << endl;
	return j;

}

int cost[3][3];
string s[3];
int dp[1<<4][4];
int F(int mask, int u){
	if ( mask == (1<<3)-1 ) return 0;
	if (dp[mask][u] != -1) return dp[mask][u];
	int res = 1<<30;
	for(int i = 0 ; i < 3; i++){
		if ( mask & (1 << i) ) continue;
		if ( cost[u][i] == -1 ){
			res = min( res, (int) F(mask | (1 << i), u) );
		}else{
			res = min( res,(int) (s[i].size() - cost[u][i]) + F(mask | (1 << i), i) );
		}
	}
	return dp[mask][u] = res;
}
#include<cstring>
int main(){
	while(cin >> s[0] >> s[1] >> s[2]){
		memset(cost,0, sizeof cost);
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if ( i != j ) 	cost[i][j] = kmp(s[i],s[j]);
				
			}
		}		

//		cout << s[0].size()+s[1].size()+s[2].size()<<endl;
		memset(dp,-1,sizeof dp);
		int res = 1 << 30;
		for(int i = 0; i < 3; i++) res = min(res, F(1 << i,i) + (int) s[i].size());
		cout << res << endl;
	}

	return 0;
}
