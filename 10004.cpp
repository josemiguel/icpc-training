#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > g;
int n;

bool bfs(int ini){
	queue<int> q;
	q.push(ini);
	vector<int> color(n,0);
	color[ini] = 5;
	while(!q.empty())
	{
		int v = q.front();q.pop();
		for(int i = 0;i<g[v].size();i++)
		{
			int u = g[v][i];
			if (!color[u])
			{
				color[u] = -color[v];
				q.push(u);
			}else
			{
				if (color[u] == color[v]) return false;
			}
		}
	}
	return true;
}

int main(){

 	while(cin>>n && n){
 		g = vector<vector<int> > (n);
		int e;
		cin>>e;
		while(e--){
			int u,v;
			cin>>u>>v;	
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (!bfs(0)){
	 		cout<<"NOT BICOLORABLE.\n";
 		}else{
			cout<<"BICOLORABLE.\n";
		}


 	}
}
