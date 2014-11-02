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
int dx[] = {0,0,1,-1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

void dfs(int x, int y){
	g[x][y] = '#';
	for(int i = 0; i < 4 ;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
			if (g[xx][yy] == ' '){
				dfs(xx,yy);
			}
		}
	}
}

int main(){
	int runs;
	cin>>runs;
	cin.ignore();
	string s;
	while(runs--){
		bool b = false;
		int k = 0;
		pair<int,int> pp;
		g = vector<string> ();
		while(getline(cin,s) && s[0] != '_'){
			if (!b)
				for(int i = 0; i < s.size(); i++){
					if (s[i] == '*') pp = make_pair(k,i), b = true;
				}
			k++;
			g.push_back(s);
		}
		g.push_back(s);
		n = k, m = g[0].size();
		dfs(pp.first,pp.second);
		for(int i = 0; i < k+1; i++) cout<<g[i]<<endl;
	}
	return 0;
}
