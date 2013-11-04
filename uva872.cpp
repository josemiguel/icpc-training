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
int cons[MAX][MAX];
//vector<vector<int> > g;
int n,m;

int main(){
	int runs;
	scanf("%d",&runs);
	cin.ignore();
	for(int r = 1 ; r <= runs ; r++){
		cin.ignore();
		if (r!=1) putchar(10);
		string s,t;
		getline(cin,s);
		getline(cin,t);

		istringstream is(t);
		memset(cons,0,sizeof(cons));
		char u,v,c;
		while(is>>u>>c>>v){
			cons[u-'A'][v-'A'] = true;
		}
		for(int i = 0; i < s.size(); i++) if (isspace(s[i])) s.erase(s.begin()+i),i--;
		n = s.size();
		sort(All(s));
		vector<string> res;
		do{
			int f = false;
			for(int i = 0; i < n - 1; i++){
				for(int j = i + 1 ; j < n; j++){
					if (cons[s[j]-'A'][s[i]-'A']) f = true;
				}
			}
			if (!f) res.push_back(s);
		}while(next_permutation(All(s)));
		if (res.size()){
			for(int i = 0; i < res.size(); i++){
				cout<<res[i][0];
				for(int j = 1; j < res[i].size(); j++){
					cout<<" "<<res[i][j];
				}
				cout<<endl;
			}
		}else cout<<"NO"<<endl;
	}
	
	return 0;
}
