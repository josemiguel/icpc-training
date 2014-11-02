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

int main(){
	string tmp;
	while(cin>>tmp && tmp!="#"){
		bool b = next_permutation(tmp.begin(),tmp.end());
		if (b){
			cout<<tmp<<endl;
		}else{
			cout<<"No Successor"<<endl;
		}
	}
	return 0;
}
