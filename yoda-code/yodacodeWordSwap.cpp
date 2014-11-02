#include <algorithm>
#include <list>
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

vector<string> ss;
vector<int> seen;
int n;

bool adj(string a, string b){
	int lenpal = b.size();
	if (lenpal == a.size()){
		int diff = 0;
		for(int k = 0; k < lenpal ; k++){
			diff += (a[k] != b[k]);
			if (diff > 1) return false;
		}
		return true;
	}
	return false;
}

list<int> l;

bool dfs(int u, string end){
	bool ok = false;
	seen[u] = true;
	if (ss[u] == end) ok = true;
	if (!ok)
	for(int i = 0; i < ss.size() ; i++){
		if (seen[i]) continue;
		if (adj(ss[u],ss[i])){
			ok = dfs(i,end);
			if (ok) break;
		}
	}
	if (ok){
		l.push_front(u);
	}
	return ok;
}



int main(int nargs, char **args){
	ifstream fcin (args[1]);
	string start(args[2]),end(args[3]);
	string s;
	n = 0;
	int st,en;
	while(fcin>>s){
		ss.push_back(s);
		if (s == start) st = n;
		n++;
	}
	sort(ss.begin(),ss.end());
	seen =  vector<int> (n+1,false);
	dfs(st,end);
	return 0;
}
