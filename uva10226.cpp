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
	cin>>runs;
	cin.ignore();
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) cout<<endl;
		map<string,int> g;
		string s;
		int n = 0;
		while(getline(cin,s) && s!=""){
			n++;
			g[s]++;
		}
		for(map<string,int>::iterator it = g.begin(); it != g.end(); it++){
			double percent = it->second/(double)n;
			cout<<it->first<<" ";
			printf("%.4lf\n",percent*100);
		}
	}
	
	return 0;
}
