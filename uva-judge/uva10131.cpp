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
#define ll long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<30)
#define CLR(x) memset((x),0,sizeof (x))
#define NCLR(x) memset((x),-1,sizeof (x))
#define ones(x) __builtin_popcount(x)
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define MAX 2400
using namespace std;
int n,m;
vector<vector<int> > g;
struct node{
	int w,s,id;
	node(){}
	node(int w, int s, int id):w(w), s(s), id(id){}

};

bool operator < (const node &a, const node &b){
	if (a.w == b.w){
		if (a.s == b.s){
			return a.id < b.id;
		}
		return a.s > b.s;
	}
	return a.w < b.w;
}


int dp[1010];
int pre[1010];
node a[1010];

int main(){
	n = 0; int w,s;
	CLR(dp); CLR(a);
	CLR(pre);
	while(cin>>w>>s) a[n] = node(w,s,n+1) , n++;
	
	sort(a,a+n);
	int res = 0;

	for(int i = n-1; i >= 0; i--){
		dp[i] = 1;
		pre[i] = -1;
		for(int j = i+1; j < n; j++){
			if (a[i].w < a[j].w && a[i].s > a[j].s)
				if (dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
		}
		res = max(dp[i],res);
	}
	vector<int> p;
	for(int i = 0; i < n; i++){
		if (dp[i] == res){
			for(int pos = i; pos != -1; pos = pre[pos]){
				p.pb(a[pos].id);
			}
			break;
		}
	}
	cout<<res<<endl;
	for(int i = 0; i < p.size(); i++) cout<<p[i]<<endl;
	return 0;
}
