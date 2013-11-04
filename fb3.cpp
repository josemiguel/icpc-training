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

int main(){
	int m;
	cin>>m;
	while(m--){
		int n;
		cin>>n;
		vector<string> ss;
		for(int i = 0; i < n ; i++){
			string s;
			cin>>s;
			ss.push_back(s);
		}
		sort(ss.begin(),ss.end());
		set<string> _s;
		do{
			string sss = "";
			for(int i = 0; i < n ; i++){
				sss += ss[i];
			}
			_s.insert(sss);			
		}while(next_permutation(ss.begin(),ss.end()));
		cout<<*_s.begin()<<endl;
	}
	return 0;
}
