#include<iostream>
#include<sstream>
#include<string>
#include<set>
#include<map>
using namespace std;

int main(){
	int n,m,R=1;
	while(cin>>n>>m){
		string K[n+5];
		for(int i = 0; i < n; i++) cin>>K[i];
		cin.ignore(); set<pair<int,string> > res;
		for(int i = 0; i < m; i++) {
			string s; getline(cin,s);
			string tmp = "";
			set<string> H; 
			for(int j = 0; j < s.size(); j++) {
				string tmp = "";
				while(isalpha(s[j])) tmp += tolower(s[j]), j++;
				H.insert(tmp);
			}
			int T = 0;
			for(int j = 0; j < n; j++) if (H.count(K[j])) T++;
			res.insert(make_pair(-T,s));
		}
		int f = 0, ant;
		cout<<"Excuse Set #"<<R++<<endl;
		for(set<pair<int,string> >::iterator it = res.begin(); it != res.end(); it++){
			if (res.begin()->first == it->first) cout<<it->second<<endl;
		}
		cout<<endl;
		
	}
	
	return 0;
}
