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
vector<string> g;
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y, char c){
	g[x][y] = c;
	for(int i = 0; i < 4 ;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < n && yy < g[xx].size()) {
			if (g[xx][yy] == ' '){
				dfs(xx,yy,c);
			}
		}
	}
}

int main(){
	string s;
	while(1){
		bool b = false;
		int k = 0;
		vector<pair<int,int> > pp;
		g = vector<string> ();
		if (!getline(cin,s)) break;

		for(int i = 0; i < s.size(); i++){
			if (s[i] != 'X' && !isspace(s[i])) pp.push_back(make_pair(k,i));
		}
		k++;
		g.push_back(s);
		bool ex = false;
		while(1){
			if (!getline(cin,s)) {ex= true; break;}
			if (s[0] == '_') break;
			g.push_back(s);	
			for(int i = 0; i < s.size(); i++){
				if (s[i] != 'X' && s[i] != ' ') pp.push_back(make_pair(k,i));
			}
			k++;

		}
		if (ex) break;
		
		n = k;
		for(int i = 0; i < pp.size(); i++){
			dfs(pp[i].first,pp[i].second,g[pp[i].first][pp[i].second]);
		}
		g.push_back(s);
		for(int i = 0; i < k+1; i++) cout<<g[i]<<endl;
	}
	return 0;
}
