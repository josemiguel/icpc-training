#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
using namespace std;

vector<vector<int> > g;
int parent[681];
bool seen[681];

map<int,string> mp2;
void proute(int u){
	if (parent[u]!=0){
		proute(parent[u]);
		cout<<mp2[parent[u]]<<" "<<mp2[u]<<endl;
	}
}

void bfs(int ini, int fin){
	queue<int> q;
	memset(seen,0,sizeof(seen));
	memset(parent,0,sizeof(parent));	
	q.push(ini);
	seen[ini] = 1;
	parent[ini] == ini;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < g[v].size() ; i++){
			int u = g[v][i];
			if (!seen[u]){
				seen[u] = 1;
				parent[u] = v;
				q.push(u);
			}
		}
	}
	
	if (parent[fin]!=0){
		proute(fin);
	}else{
		cout<<"No route"<<endl;
	}
}

int main(){
	int n;
	int r = 0;
	while(cin>>n){
		if (r!=0) cout<<endl;
		map<string,int> mp1;
		mp2 = map<int,string>();
		g = vector<vector<int> > (681);
		string a,b;		
		int m = 1;		
		for(int i = 0 ; i < n ; i++){
			cin>>a>>b;
			if (mp1.find(a)==mp1.end()){
				mp1[a] = m;
				mp2[m] = a;
				m++;						
			}
			if (mp1.find(b)==mp1.end()){
				mp1[b] = m;
				mp2[m] = b;
				m++;						
			}
			g[mp1[a]].push_back(mp1[b]);
			g[mp1[b]].push_back(mp1[a]);			
		}
		cin>>a>>b;
		bfs(mp1[a],mp1[b]);
		r=1;
	}
	return 0;
}
