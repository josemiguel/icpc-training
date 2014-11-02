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
/*int n,m;
int P[MAX];
inline void Init(int n) { rep(i,n) P[i] = i; }
inline int Find(int u) { return P[u] == u ? u : (P[u] = Find(P[u])); }
inline void link(int u, int v){ P[u] = v;}
inline void Union(int u, int v) {link(Find(u),Find(v)); }
*/
/*
vector<vector<int> > g,rg;
bool usd[2005];
stack<int> S;
void dfs1(int u){ usd[u] = true; for(int i = 0; i < g[u].size(); i++) if (!usd[g[u][i]]) dfs1(g[u][i]); S.push(u); }
void dfs2(int u){ usd[u] = true; for(int i = 0; i < rg[u].size(); i++) if (!usd[rg[u][i]]) dfs2(rg[u][i]); }

*/
//int g[MAX][MAX];
//vector<vector<int> > g;
//vector<pair<int,pair<int,int> > > edg;

/*struct state{
	int u,v;
	state(){}
	state(int u,int v):u(u),v(v){}
};*/
int f[105];
int kmp(string p, string t){
	if (p.size() > t.size()) return false;
	for(int i = 1, j = f[0] = -1; i <= p.size();f[i] = ++j, i++)
		while (j >= 0 && p[j] != p[i-1]) j = f[j];

	for(int i = 0, j = 0; i < t.size(); i++){
		while( j >= 0 && p[j] != t[i]) j = f[j];
		if ( ++j >= p.size() ) return true;
	}
	return false;
}
 

int main(){
	
	int runs;
	cin>>runs;
	while(runs--){
		int n;cin>>n;
		string dic[n+1];
		for(int i = 0; i < n; i++)cin>>dic[i];
		int res = 0;
		string s = dic[0];
		for(int k = 0; k < s.size(); k++){
			string tmp = "";
			for(int l = s.size(); l >= 0 ; l--){
				tmp = s.substr(k,l);
				if (tmp.size() <= res) break;
				bool sale = true;
				for(int i = 1; i < n; i++){
					string rtmp = tmp; reverse(All(rtmp));
					if (!kmp(tmp,dic[i]) && !kmp(rtmp,dic[i])) sale = false;
				}
				if (sale) res = max(res,(int)tmp.size()); 
			}
		}
		cout<<res<<endl;
	}	
	
	return 0;
}
