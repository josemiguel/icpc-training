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
#define MAX
//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;

int main(){
	string nick,job;
	int b = 0;
	map<string,set<string> > g;	
	while(1){

		if (!b) getline(cin,nick);
		b = 1;
		if (nick == "0") break;
		if (nick == "1") {
			for(map<string,set<string> > ::iterator it = g.begin(); it != g.end(); it++){
				cout<<it->first<<" "<<(it->second).size()<<endl;
			}	
			b = 0;
			g = map<string,set<string> > (); continue;
		}
		while(getline(cin,job) && islower(job[0]) && isalpha(job[0])){
			g[nick].insert(job);
			if (nick == "YOUBOOK") cout<<job<<" "<<g[nick].size()<<endl;
		}
		nick = job;
	}
	return 0;
}
