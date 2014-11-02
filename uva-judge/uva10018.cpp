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

bool pal(string a){
	for(int i = 0, j = a.length() -1 ; i <= j; i++, j--){
		if (a[i] != a[j]) return false;
	}
	return true;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		string s;
		cin>>s;
		int moves = 0;
		while(!pal(s)){
			string tmp = s;
			reverse(All(s));
			istringstream i1(s),i2(tmp);
			ostringstream os;
			long long a,b;
			i1>>a;i2>>b;
			os<<a+b;
			s = os.str();
			moves++;
		}
		cout<<moves<<" "<<s<<endl;
	}
	
	return 0;
}
