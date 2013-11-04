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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30
#define MAX 500
bool cons[MAX][MAX];
//vector<vector<int> > g;
int n,m;
int main(){
	string s;
	int r = 0;
	while(getline(cin,s)){
		if (r) cout<<endl;
		r++;
		string t;
		getline(cin,t);
		istringstream is(t);
		char u,v;
		memset(cons,false,sizeof(cons));
		while(is>>u>>v)	cons[u-'a'][v-'a'] = true;
		for(int i = 0; i < s.size(); i++) if (isspace(s[i])) s.erase(s.begin()+i),i--;
		sort(All(s));
		vector<string> res;
		n = s.length();
		do{
			bool f = false;
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if (cons[s[j]-'a'][s[i]-'a']) f = true;
				}
			}
			if (!f) res.push_back(s);
		}while(next_permutation(All(s)));
		
		for(int i = 0; i < res.size();i++) cout<<res[i]<<endl; 
	}
	
	return 0;
}
