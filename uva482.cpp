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

string a[10002];

int main(){
	int r;
	cin>>r;	
	cin.ignore();

	int k = 0;
	while(r--){
		cin.ignore();		
		if (k) cout<<endl;
		k = 1;
		int n = 1;
		string s1,s2;
		getline(cin,s1);
		getline(cin,s2);		
		
		istringstream is(s1),_is(s2);
		int idx;
		string _a;
		while(is>>idx && _is>>_a){
			a[idx] = _a;			
			n++;
		}
		for(int i = 1 ; i < n ; i++){
			cout<<a[i]<<endl;
		}
	}
	
	return 0;
}
