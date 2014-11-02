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
	
	string ss;
	while(getline(cin,ss)){
		istringstream is(ss);
		string s;
		is>>s;
		int len = s.size()-1;
		for(int i = len; i >=0; i--){
			cout<<s[i];
		}
		while(is>>s){
			cout<<" ";
			int len = s.size()-1;
			for(int i = len; i >=0; i--){
				cout<<s[i];
			}
		}
		cout<<endl;
	}
	
	return 0;
}
