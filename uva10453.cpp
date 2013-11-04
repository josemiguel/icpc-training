#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<string>
#include<cctype>
#include<set>
#include<map>
#include<numeric>

#define ll long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<20)
#define ones(x) __builtin_popcount(x)
#define clr(x) memset((x),0,sizeof(x))
#define rclr(x) memset((x),-1,sizeof(x))
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define MAX 1005

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)
#define get(s) getline(cin,s)
#define sz size()
using namespace std;
string s;

int dp[MAX][MAX];
int rec[MAX][MAX];
int F(int i, int j){
	if (i>=j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j]) return dp[i][j] = F(i+1,j-1);
	return dp[i][j] = 1 + min(F(i+1,j),F(i,j-1));
}
string l, r;
void track(int i,int j) {
	if(i == j) l += s[i];
 	if (i >= j) return;   
    if(s[i] == s[j]) {
        l += s[i];
        r =  s[j] + r;
        track(i+1,j-1);
    }else if(dp[i][j-1] < dp[i+1][j]) {
		l += s[j];
		r = s[j] + r;
		track(i,j-1);
    }else{
		l += s[i];
		r = s[i] + r;            
		track(i+1,j);
	}
}

int main(){
	while(cin>>s){
		rclr(dp);
		rclr(rec);
		int ans = F(0,s.sz-1);
		l = "" , r = "";
		track(0,s.sz-1);
		cout<<ans<<" "<<l<<r<<endl;
	}

	return 0;
}
