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
#define ll ll
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
using namespace std;
/*int n,m;
int p[MAX];
void startt(int n) {for(int i = 0; i <=n ; i++) p[i] = i;}
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
typedef long long ll;
string res[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(){
	ll n;
	cin>>n;
	ll S=0;ll start=5;ll bef=0;ll cont=1;
	while(S + start < n){
		S+=start;
		start*=2;
		cont*=2;
	}
	ll D = n-S-1;
	D /= cont;
	cout<<res[D]<<endl;
	return 0;
}
