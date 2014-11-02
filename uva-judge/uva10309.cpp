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
#define MAX 11

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)
#define get(s) getline(cin,s)
#define sz size()
using namespace std;

int tmp[MAX],a[MAX];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

int play(int x, int y){
	rep(i,5){
		int xx = x + dx[i], yy = y + dy[i];
		if ( xx < 0 || yy < 0 || xx >= 10 || yy >= 10) continue;
		if ((tmp[xx]>>yy) & 1) tmp[xx] &= ~((1<<yy));
		else tmp[xx] |= (1<<yy);
	}
}
int dp[MAX][1<<MAX];
int F(int u, int mask){
	if (u == 10) return (tmp[u-1] ? 101 : 0);
	if (dp[u][mask] != -1) return dp[u][mask];
	int res = 0;
	rep(i,10) if ((mask>>i) & 1) play(u,i), res++;
	int ret = F( u + 1 ,tmp[u]);
	if( ret == 101 ) return dp[u][mask] = 101;
	return dp[u][mask] = res + ret;

}

int main(){
	string s;
	char c;	
	while(cin>>s && s!="end"){
		clr(a); rclr(dp);
		rep(i,10) rep(j,10)	{cin>>c; if (c == 'O') a[i] |= (1<<j);}
		int res = 101;
		rep(mask ,1<<10) {
			rep(i,10) tmp[i] = a[i];
			res = min(res,F(0,mask));
		}
		if (res >= 101) res = -1;
		cout << s << " " << res << endl;
	}
	return 0;
}
