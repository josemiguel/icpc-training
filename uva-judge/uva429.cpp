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
#define MAXN 205
using namespace std;

vector<vector<int> > g;

int dist[MAXN];

int bfs(int ini, int fin){
	queue<int> q;
	q.push(ini);
	memset(dist,0,sizeof(dist));
	while(!q.empty()){
		int v = q.front(); q.pop();
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
	for(int c = 0 ; c < r ; c++){
		if (c) cout<<endl;
		int n = 0;
		map<string,int> mp;
		vector<string> ss;
		
		string s;
		while(cin>>s && s!="*"){
			if(mp.find(s) == mp.end()) mp[s]=n++;
			ss.push_back(s);
		}
		g = vector<vector<int> > (n);
		
		int len = ss.size();
		for(int i = 0; i < len -1; i++){
			for(int j = i +1 ; j < len ; j++){
				int lenpal = ss[i].size();
				if (lenpal == ss[j].size()){
					int diff = 0;
					bool b = false;
					for(int k = 0; k < lenpal ; k++){
						diff += (ss[j][k] != ss[i][k]);
						if (diff > 1) {
							b = true;
							break;
						}
					}
					if (!b){
						g[mp[ss[i]]].push_back(mp[ss[j]]);
						g[mp[ss[j]]].push_back(mp[ss[i]]);						
					}
				}
			}
		}
				
		cin.ignore();
		while(getline(cin,s) && s!=""){
			istringstream is(s);
			string a,b;
			is>>a>>b;
			cout<<a<<" "<<b<<" "<<bfs(mp[a],mp[b])<<endl;
		}
	}
	
	return 0;
}
