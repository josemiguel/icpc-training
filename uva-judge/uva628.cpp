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
int len;
vector<string> pal;
vector<string> d;
string r;
void solve(int idx,int k){
	if (idx == len){
		for(int i = 0; i < len; i++){
			cout<<pal[i];
		}
		cout<<endl;
	}
	if (r[idx]=='#'){
		pal[idx] = d[k];
		solve(idx+1,k);
	}else if (isdigit(r[idx])){
		for(int i = 0; i <= 9; i++){
			ostringstream os;
			os<<i;
			pal[idx] = os.str();
			solve(idx+1,k);	
		}
	}
}

int main(){
	int n,m;
	while(scanf("%d",&n) != -1){
		d = vector<string> (n);
		for(int i = 0; i < n ; i++){
			cin>>d[i];
		}
		scanf("%d",&m);
		while(m--){
			cin>>r;
			len = r.size();
			puts("--");
			for(int i = 0; i < n; i++){
				pal = vector<string> (len);
				solve(0,i);
			}
		}
	}
	return 0;
}
