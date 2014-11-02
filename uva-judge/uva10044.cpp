#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;

#define All(v) v.begin(),v.end()
#define MAX 5005

int n,m;
vector<vector<int> > g;
vector<int> dist;

void bfs(int s){
	queue<int> q;
	q.push(s);
	for(int i = 0; i < n+1 ; i++) dist[i] = -1;

	dist[s] = 0;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int u =  g[v][i];
			if (dist[u] == -1){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
}

string trim(string s){
	for(int i = 0; i < s.size() ; i++) if (isspace(s[i])) s.erase(s.begin()+i), i--;
	return s;

}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		int q;
		scanf("%d%d",&m,&q);
		cin.ignore();
		n = 1;
		map<string,int> mp;

		int erdos;
		string p,s;
		vector<vector<int> > fila(m);
		for(int t = 0 ; t < m ;t++){
			getline(cin,p);
			for (int fb, fe = 0, lb, le = 0; p[fe] != ':' && p[le] != ':'; ) {
				fb = p.find_first_not_of(" ,", le);
				fe = p.find_first_of(" ,:", fb);
				lb = p.find_first_not_of(" ,", fe);
				le = p.find_first_of(" ,:", lb);
				if (fb == string::npos || fe == string::npos ||  lb == string::npos || le == string::npos) {
					break;
				}
				string name = p.substr(fb, fe-fb) + ", " + p.substr(lb, le-lb);
				name = trim(name);
				if (name != ""){
					if (mp.find(name) == mp.end()) mp[name] = n,n++;
					fila[t].push_back(mp[name]);
				}
			}
		}
		g = vector<vector<int> > (n+1);
		dist = vector<int> (n+1);
		for(int i = 0; i < fila.size() ; i++){
			for(int j = 0; j < fila[i].size()-1; j++){
				for(int k = j+1; k < fila[i].size(); k++){
					g[fila[i][j]].push_back(fila[i][k]);
					g[fila[i][k]].push_back(fila[i][j]);					
				}
			}
		}
		

		bfs(mp["Erdos,P."]);
		printf("Scenario %d\n",r);
		while(q--){
			getline(cin,s);
			if (!s.empty()){
				int ss = mp[trim(s)];
				if (ss && dist[ss] != -1){
					cout<<s<<" "<<dist[ss]<<endl;
				}else{
					cout<<s<<" infinity\n";
				}
			}else cout<<endl;
						
		}
	}
	
	return 0;
}
