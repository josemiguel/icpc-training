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

int n,m;

int main(){
	set<string> dic;
	string s;
	while(getline(cin,s)){
		int n =  s.size();
		for(int i = 0; i < n; i++){
			if (!isalpha(s[i])) s[i] = ' ';
			else s[i] = tolower(s[i]);
		}
		istringstream is(s);
		string ss;
		while(is>>ss){
			dic.insert(ss);	
		}
	}
	for(set<string>::iterator it = dic.begin(); it != dic.end(); it++){
		cout<<*it<<endl;
	}
	
	return 0;
}
