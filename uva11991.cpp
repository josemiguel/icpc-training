#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		map<int,vector<int> > g;
		for(int i = 1; i <= n; i++){
			int u; cin>>u;
			g[u].push_back(i);
		}
		for(int i = 0; i < m; i++){
			int k,v;
			int res;
			cin>>k>>v; 
			if (g[v].size() < k) res = 0;
			else res = g[v][k-1];
			cout<<res<<endl;
		}
		
	}
	return 0;
}
