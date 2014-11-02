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
	int runs;
	scanf("%d",&runs);
	map<string,set<string> > g;	
	for(int r = 1 ; r <= runs ; r++){
		string ctr,cq;
		cin>>ctr;
		getline(cin,cq);
		istringstream is(cq);
		g[ctr].insert(cq);
	}
	for(map<string,set<string> > ::iterator it = g.begin(); it != g.end(); it++){
		cout<<it->first<<" "<<(it->second).size()<<endl;
	}
	
	return 0;
}
