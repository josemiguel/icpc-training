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
vector<int> pai;
vector<string> cads;

void track(int i){
	if (i > 0){
		track(pai[i]);
		cout<<cads[i]<<endl;
	}
}

int main(){
	map<string,int> pos;
	int n = 1;
	string s,e;
	cads.push_back("");
	for(int i=0; getline(cin,s) && s!=""; i++){
		cads.push_back(s);
		pos[s] = i+1;
		n++;
	}

	int k = 0;
	while(cin>>s>>e){
		if (k!=0) cout<<endl;
		k++;
		int eqz = s.size();
		queue<int> q;
  	    pai = vector<int>(n,-1);
		int ss = pos[s];
		int ee = pos[e];
		q.push(ss);
		pai[ss] = -2;
		bool llego = false;
		while(!q.empty()){
			int v = q.front();q.pop();
			if ( v == ee ) {llego = true;break;}
			if (eqz != cads[v].size()) continue;
			string _s = cads[v];
			for(int i = 0; i < _s.size(); i++){
				for(int j = 0; j < 27 ; j++){
					_s[i] = j + 'a';
					int pp = pos[_s];
					if (pp != 0){
						if (pai[pp] == -1){
							pai[pp] = v;
							q.push(pp);
						}
					}
					_s[i] = cads[v][i];
				}
			}
		}
		
		if (llego)
			track(ee);
		else
			cout<<"No solution.\n";
	}

	return 0;
}
