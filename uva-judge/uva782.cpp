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
vector<vector<bool> > v;
void dfs(int x, int y){

	for(int i = 0; i < 4 ;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < n && yy < g[xx].size()) {
			if (g[xx][yy] != '_' && g[xx][yy] != '*' && g[xx][yy] != '#' && g[xx][yy] != ' '){
				g[x][y] = '#';
			}else if (g[xx][yy] == ' ' && !v[xx][yy]){
				v[xx][yy] = 1;
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
		g = vector<string> (100,string(100,' '));

		while(getline(cin,s) && s[0] != '_'){
			for(int i = 0; i < s.size(); i++){
				if (s[i] == '*') pp = make_pair(k,i), s[i] = ' ';
				g[k][i] = s[i];
			}
			k++;
		}
		g[k] = s;

		n = k;
		v = vector<vector<bool> > (n+100,vector<bool> (n+100,false));
		dfs(pp.first,pp.second);
		
		for(int i = 0; i < k+1; i++){
			stack<char> s;
			bool  b = true;
			for(int j = g[i].size()-1; j>=0 ;j--){
				if (g[i][j] == ' ' && b) continue;
				if (g[i][j] != ' '){
					b = false;
				}
				if (!b) s.push(g[i][j]);
			}
			while(!s.empty()) cout<<s.top(), s.pop();
			cout<<endl;
		}
		
	}
	return 0;
}
