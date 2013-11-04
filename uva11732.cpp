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

struct Trie{
	int words,prefixes,nodes;
	Trie *edges[70];
	
	Trie(){
		words = prefixes = 0;
		nodes = 1; // root -> ""
		for(int i = 0; i < 70; i++) edges[i] = NULL;
	}
	
	void add(char word[]){
		int len = strlen(word),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			tmp->prefixes++;
			k = word[i]-'9';
			if (!tmp->edges[k]){
				tmp->edges[k] = new Trie();
				this->nodes++;
			}
			tmp = tmp->edges[k];
		}	
		tmp->words++;					
	}
};

int cuenta(Trie *t){
	if (t == NULL) return 0;
	int res = 0,tmp = 0,x=0;
	for(int i = 0; i < 70; i++){
		if (t->edges[i]) x++;
		tmp += cuenta(t->edges[i]);
	}
	if (x > 1) res = (x*(x-1))/2;	
	return res + tmp;
}


int main(){
	int n,r=1; 
	char s[1005];
	while(cin>>n && n){
		Trie *t = new Trie();
		for(int i = 0; i < n; i++) {
			scanf("%s",s);
			t->add(s);
		}
		int res = cuenta(t);
		cout<<"Case "<<r++<<": "<<res<<endl;
	}
	
	return 0;
}
