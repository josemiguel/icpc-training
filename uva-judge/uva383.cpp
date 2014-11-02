#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define mp make_pair 
#define MAXN 55
vector<vector<int> > g;

int bfs(int ini, int fin){
	queue<int> q;
	q.push(ini);
	int dist[MAXN] = {0};
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < g[v].size();i++){
			int u = g[v][i];
			if (!dist[u]){
				q.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
	return dist[fin];
}

int main(){
	int r;
	cin>>r;
	cout<<"SHIPPING ROUTES OUTPUT\n\n";
	for(int rr = 1 ; rr <= r ; rr++){
		int n,e,q,w;
		cin>>n>>e>>q;
		map<string,int> mp;
		g = vector<vector<int> > (n);
		for(int i = 0; i < n ; i++){
			string s;
			cin>>s;
			mp[s] = i;
		}
		string u,v;		
		for(int i  = 0; i < e ; i++){
			cin>>u>>v;
			g[mp[u]].push_back(mp[v]);
			g[mp[v]].push_back(mp[u]);
		}
		cout<<"DATA SET  "<<rr<<endl<<endl;
		
		for(int i = 0; i < q ; i++){
			cin>>w>>u>>v;
			int dist = bfs(mp[u],mp[v]);
			if (!dist) cout<<"NO SHIPMENT POSSIBLE\n";
			else cout<<"$"<<w*100*dist<<endl;
		}
		cout<<endl;
	
	}
	cout<<"END OF OUTPUT\n";
	

	return 0;
}
