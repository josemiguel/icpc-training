#include<iostream>
#include<map>
#include<set>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main(){
	int n,m;

	cin >> n >> m;
	string dic[n];
	map<string,int> M;
	for(int i = 0; i < n; i++){
		cin>>dic[i];
		M[dic[i]] = i;
	}
	vector<set<int> > g;
	for(int i = 0; i < m; i++){
		string u,v;
		cin>>u>>v;
		g[M[u]].insert(M[v]);
		g[M[v]].insert(M[u]);
	}
	int N,best = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		bool puede = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if ((mask&(1<<i)) && (mask&(1<<j))){
					if (g[i].count(j)){
						puede = false;
						goto sale;
					}
				}
			}
		}
		sale:
		if (puede){
			int tmp = __builtin_popcount(n);
			if (tmp > best){
				best = tmp;
				N = mask;
			}
	
		}
	}
	vector<string> res;
	for(int i = 0; i < N; i++) if (N&(1<<i)) res.push_back(i);
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<endl;
	}
	


	return 0;
}
