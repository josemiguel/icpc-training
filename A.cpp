#include <iostream>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <queue>
#include <list>
#include <stack>
#define Int long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<30)
#define ones(x) __builtin_popcount(x)
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define MAX 2400
using namespace std;
/*int n,m;
int p[MAX];
void Init(int n) {for(int i = 0; i <=n ; i++) p[i] = i;}
int Find(int a){ return p[a] == a? a : p[a] = Find(p[a]); }
void link(int a,int b){ p[a] = b; }
void Union(int a, int b) {link(Find(a),Find(b));}
*/
//int g[MAX][MAX];
//vector<vector<int> > g;
//vector<pair<int,pair<int,int> > > edg;
//bool air[MAX];
//int dist[MAX];
/*struct state{
	int u,v;
	state(){}
	state(int u,int v):u(u),v(v){}
};*/
int len;
#define MOD 0xfaceb00c
string s;
int toInt( int ini, int cant ){
	int res = 0;
	if ( ini+cant > s.size() ) return -1;
	for(int i = ini; i < ini+cant; i++) res = res*10 + (s[i]-'0');
	return res;
}
int m;
Int dp[1005];
Int F( int pos ){
	if ( pos == len ) return 1;
	if ( dp[pos] != -1) return dp[pos];
	Int res = 0;
	for(int i = 1; i <= 3; i++){
		int val = toInt(  pos, i );
		if ( s[pos] == '0' ) continue;
		if ( val == -1) continue;
		if ( val <= m ){
			res = (res%MOD + F( pos + i )%MOD)%MOD;
		}
	}
	return dp[pos] = res%MOD;

}

int main(){
	int runs;
	
	cin>>runs;
	for(int r = 1; r <= runs; r++){
		cin >> m >> s;
		len = s.size();
		memset( dp,-1,sizeof dp);
		printf("Case #%d: %lld\n",r, F( 0 )%MOD );

	}
	
	return 0;
}
