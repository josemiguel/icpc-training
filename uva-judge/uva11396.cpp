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
#define MAX 305

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;
int n,m;

int C[MAX];
vector<vector<int> > g;

bool BFS(int r){
	queue<int> Q;
	Q.push(r);
	C[r] = 5;
	while(!Q.empty()){
		int v = Q.front();Q.pop();
		rep(i,g[v].size()){
			int u = g[v][i];
			if (C[u] == 0){
				C[u] = -C[v];
				Q.push(u);
			}else if (C[u] == C[v]){
				return false;
			}
		}
	}
	return true;
}

bool F(){
	clr(C);
	return BFS(0);
}

int main(){
	while(scanf("%d",&n) && n){
		int u , v;
		g = vector<vector<int> > (n+1);
		while(scanf("%d%d",&u,&v) && u+v){
			u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		puts(F()?"YES":"NO");
	}
	return 0;
}
