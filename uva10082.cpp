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

char mp[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
	string s;
	while(getline(cin,s)){
		for(int i = 0; i < s.size();i++){
			for(int k = 0; k < 48; k++){
				if (s[i]==mp[k]){
					s[i]=mp[k-1];
				}
			}
		}
		cout<<s<<endl;		
	}
	
	return 0;
}
