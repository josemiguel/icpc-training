#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > g(n+1);

int main(){

	int n,t;
	
	cin>>n>>t;
	g  = vector<vector<int> > (n+1);
	
	for(int i = 0; i < t; i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(v);
		c[u][v] = w;
	}
	
	
	

	return 0;
}
