#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n;
	int r = 0;
	while(cin>>n){
		if (r) cout<<endl;
		r = 1;
		map<string,int> res;
		vector<string> dic(n);
		for(int i = 0; i < n; i++){
			cin>>dic[i];
		}
		
		for(int i = 0 ; i < n; i++){
			string s;int G,m;
			cin>>s>>G>>m;
			for(int j = 0; j < m; j++){
				string t;
				cin>>t;
				res[t] += G/m;
			}
			if (m)	res[s] -= (G/m)*m;
		}
		for(int i = 0; i < n; i++) cout<<dic[i]<<" "<<res[dic[i]]<<endl;	
	}

	return 0;
}
