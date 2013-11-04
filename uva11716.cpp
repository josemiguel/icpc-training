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
	int runs;
	scanf("%d",&runs);
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		string s;
		getline(cin,s);
		int len = s.size();
		int n = sqrt((double)len);
		if (n*n == len){
			for(int i = 0; i < n ; i++){
				for(int j = i; j < len; j+=n){
					putchar(s[j]);
				}
			}
			putchar(10);
		}else{
			puts("INVALID");
		}
		
	}
	
	return 0;
}
