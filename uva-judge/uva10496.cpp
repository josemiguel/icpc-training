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
int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }
int N,M,q;
int p[MAX][2];
int arr[MAX][MAX];
int dp[MAX][1<<10];

int F(int,int);
int main(){
	int runs;
	cin>>runs;
	rep(r,runs){
		int x,y;
		cin>>N>>M>>p[0][0]>>p[0][1]>>q;
		rep(i,q) cin>>p[i+1][0]>>p[i+1][1];
		q++;
		REP(i,0,q-1)
			REP(j,i+1,q){
				arr[i][j] = arr[j][i] = dist(p[i][0],p[i][1],p[j][0],p[j][1]);
			}
		rclr(dp);
		printf("The shortest path has length %d\n",F(0,0));
	}
	return 0;
}
int F(int u, int mask){
	if (mask +1 == (1<<q)) return dist(p[u][0],p[u][1],p[0][0],p[0][1]); 
	if (dp[u][mask] != -1) return dp[u][mask];
	int res = 1<<20;
	rep(i,q){ 
		if ((mask>>i) & 1) continue;
		int tmp = F(i,mask | (1<<i));
		res = min(res, arr[u][i] + tmp);
	}
	return dp[u][mask] = res;
}

