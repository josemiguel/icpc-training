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
#define MAX 10010

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;
int n,m;
long long dist[MAX];
vector<vector<pair<int,int> > > g,gg;

ll dijkstra(int s,int e){
	for(int i = 0; i < n; i++) dist[i] = -1;
	set<pair<ll,int> > Q;
	Q.insert(mp(0LL,s));
	dist[s]=0;
	while(!Q.empty()){
		pair<ll,int> tmp = *Q.begin();Q.erase(Q.begin());
		int u = tmp.second;
		ll w = tmp.first;
		if ( u == e ) return dist[e];
		if (dist[u] < w) continue;
		for(int i = 0; i < gg[u].size(); i++){
			pair<int,int> tmp2 = gg[u][i];
			int v = tmp2.first;
			ll we = tmp2.second;
			if (dist[v] == -1 or dist[v] > we + w){
				dist[v]=we+w;
				Q.insert(mp(dist[v],v));
			}
		}
	}
	return -1;
}

int main(){
	
	int runs;
	scanf("%d",&runs);
	while(runs--){
		int s,t,k;
		scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
		s--,t--;
		g = vector<vector<pair<int,int> > >(n+1);
		for(int i = 0;i < m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			g[u].pb(mp(v,w));
		}
		ll res = -1;
		for(int i = 0; i < k; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;			
			gg = g;
			gg[u].pb(mp(v,w));
			ll tmp = dijkstra(s,t);
			if (tmp == -1) continue;
			if ( res == -1 or res > tmp) res = tmp;
		}
		printf("%lld\n",res);
	}		
	
		
	return 0;
}



