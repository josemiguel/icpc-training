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
int a[20005][205];
int sz[205];
bool usd[205],same[205];
void print(vector<int> v){
	if (v.size()){
		cout<<v.size()<<" ";
		for(int t = 0; t < v.size(); t++){
			if (!t) cout<<v[t];
			else cout<<" "<<v[t];
		} 
		cout<<endl;
	}
	
}



int main(){
	int n;
	cin>>n;
	n = ((n-1)*n)/2;
	memset(usd,0,sizeof usd);
	memset(same,0,sizeof same);	
	memset(sz,0,sizeof sz);		
	for(int i = 0; i < n; i++){
		int t;
		cin>>t;

		for(int j = 0; j < t; j++) {
			cin>>a[i][j];
		}
		sz[i] = t;
	}
	if (n == 1){ 
		int M = sz[0]/2;
		int C = sz[0] - M;
		cout<<M;
		for(int i = 0; i < M; i++){
			cout<<" "<<a[0][i];
		}
		cout<<endl<<C;
		for(int i = M; i < M+C; i++){
			cout<<" "<<a[0][i];			
		}			
		cout<<endl;
		return 0; 
	
	}

	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j < n; j++){
			vector<int> v;
			for(int k = 0; k < sz[i]; k++){
				if (usd[a[i][k]]) continue;
				for(int l = 0; l < sz[j]; l++){
					if (usd[a[j][l]]) continue;
					if (a[i][k] == a[j][l]) { same[a[i][k]] = same[a[j][l]] = true; v.pb(a[i][k]); }
				}
			}
			print(v);
			vector<int> A,B;
			for(int k = 0; k < sz[i]; k++){
				if (usd[a[i][k]] || same[a[i][k]]){ usd[a[i][k]] = true; continue; }
				A.pb(a[i][k]);
				usd[a[i][k]] = true;
			}
			print(A);
			for(int l = 0; l < sz[j]; l++){
				if (usd[a[j][l]] || same[a[j][l]]){ usd[a[j][l]] = true; continue; }
				usd[a[j][l]] = true;
				B.pb(a[j][l]);
			}		
			print(B);
		}
	}
	return 0;
}
