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
#define MAX 30

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;


int lcm(int a, int b){
	return (a*b)/__gcd(a,b);
}

int N;	
int dp[1005][2005];

bool check(int n, int sum){
	if (!n && !sum) return false;
	REP(i,1,n+1){
		if (sum % i) return false;
	}
	return true;
}

int F(int curr, int sum){
	if (curr > N) return 0;
	if (dp[curr][sum] != -1) return dp[curr][sum];
	if (check(curr,sum)) return F(curr+1,sum);
	int resMIN = oo;
	REP(i,1,curr+1){
		if (sum % i){
			int d = i*(sum/i) + sum%i - i;
			int tmp = F(curr,sum+d);
			resMIN = min(resMIN,1 + tmp);
		}
	}
	return dp[curr][sum] = resMIN;
	
}

int main(){
	
	int runs;
	cin>>runs;
	REP(r,1,runs+1){
		cin>>N;
		int res = 0;
		memset(dp,-1,sizeof dp);
		cout<<N-F(0,0)<<endl;
	}
	
	return 0;
}
