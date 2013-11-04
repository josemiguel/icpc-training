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
	scanf("%d%d",&n,&m);
	map<string,int> g;
	for(int i = 0; i <n; i++){
		string s;
		int v;
		cin>>s>>v;
		g[s] = v;
	}
	for(int i = 0 ; i < m ;i++){
		string s;
		int total = 0;
		while(cin>>s && s!="."){
			total +=g[s];
		}
		cout<<total<<endl;
	}
	
	return 0;
}
