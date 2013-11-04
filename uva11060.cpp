#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
vector<string> dic;
stack<int> S;
vector<vector<int> > g;
#define MAX 105
int de[MAX];
map<string,int> m;
int main(){
	int n,q,r=1;
	while(cin>>n){
		dic = vector<string>(n);
		g = vector<vector<int> > (n+1);
		memset(de,0,sizeof de);
		m.clear();
		for(int i = 0; i < n; i++) {
			cin>>dic[i];
			if (!m.count(dic[i])) m[dic[i]] = i+1;
		}
		cin>>q;
		for(int i = 0;i < q; i++){
			string u,v;
			cin>>u>>v;
			g[m[u]].push_back(m[v]);
			de[m[v]]++;
		}
		set<int> Q;
		vector<int> res;
		for(int i = 1; i <= n; i++){
			if (de[i] == 0)  Q.insert(i);
		}
		while(!Q.empty()){
			int u = *Q.begin(); Q.erase(Q.begin());
			res.push_back(u);
			for(int i = 0; i < g[u].size();i++){
				int v = g[u][i];
				de[v]--;
				if (de[v] == 0){
					Q.insert(v);
				}
			}
		}
		
		
		cout<<"Case #"<<r++<<": Dilbert should drink beverages in this order:";
		for(int i = 0;i < res.size();i++) cout<<" "<<dic[res[i]-1];
		cout<<"."<<endl;
		cout<<endl;
	}
	
	return 0;
}
